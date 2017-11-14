EXE = glutils
LIB = $(EXE)lib
SHARED_LIB = lib$(LIB).so
STATIC_LIB = lib$(LIB).a
TEST = $(EXE)-test
FUZZ = $(EXE)-fuzz
HEADERS = $(shell find src/ -name "*.h")
SOURCES = $(shell find src/ -name "*.c")
OBJECTS = $(SOURCES:src/%.c=obj/%.o)
SOURCES_LIB = $(filter-out src/main.c src/test.c, $(SOURCES))
SOURCES_EXE = src/main.c
SOURCES_TEST = src/test.c $(SOURCES_LIB)
SOURCES_FUZZ = src/main.c $(SOURCES_LIB)
OBJECTS_RELEASE_EXE = $(SOURCES_EXE:src/%.c=obj/release/exe/%.o)
OBJECTS_RELEASE_STATIC = $(SOURCES_LIB:src/%.c=obj/release/static/%.o)
OBJECTS_RELEASE_SHARED = $(SOURCES_LIB:src/%.c=obj/release/shared/%.o)
OBJECTS_DEBUG_EXE = $(SOURCES_EXE:src/%.c=obj/debug/exe/%.o)
OBJECTS_DEBUG_STATIC = $(SOURCES_LIB:src/%.c=obj/debug/static/%.o)
OBJECTS_DEBUG_SHARED = $(SOURCES_LIB:src/%.c=obj/debug/shared/%.o)
OBJECTS_TEST = $(SOURCES_TEST:src/%.c=obj/test/%.o)
OBJECTS_FUZZ = $(SOURCES_FUZZ:src/%.c=obj/fuzz/%.o)
CC = gcc
CPPFLAGS =
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Wfatal-errors
LDFLAGS =
LDLIBS = -lm -lGL -lGLEW -lSDL2 #-lX11
ARFLAGS = rc
RELEASE_FLAGS = -O3 -DNDEBUG
DEBUG_FLAGS = -g -ggdb -DDEBUG
TEST_FLAGS = $(DEBUG_FLAGS) -DTEST `pkg-config --cflags glib-2.0`

# debug print rule
print-%: ; @echo $*=$($*)

# targets
all: check release

build: build/debug/$(EXE)
release: build/release/$(EXE)
lib: build/debug/$(STATIC_LIB)
lib-release: build/release/$(STATIC_LIB)
shared: build/debug/$(SHARED_LIB)
shared-release: build/release/$(SHARED_LIB)

doc: build/doc/html/
doc-open: build/doc/html/
	gnome-open build/doc/html/index.html
build/doc/html/: Doxyfile $(HEADERS) $(SOURCES) | build/doc/
	@echo ">>> Generating documentation..."
	doxygen Doxyfile
	@echo "<<< ...Generating documentation done"

run: build/debug/$(EXE)
	@echo ">>> Running debug build..."
	./build/debug/$(EXE)
	@echo "<<< ...Running debug build done"
run-release: release
	@echo ">>> Running release build..."
	./build/release/$(EXE)
	@echo "<<< ...Running release build done"
debug: build/debug/$(EXE)
	@echo ">>> Debugging..."
	gdb ./$<
	@echo "<<< ...Debugging done"
check: $(HEADERS) $(SOURCES)
	@echo ">>> Checking..."
	@echo ">>> Run cppcheck..."
	cppcheck src/ --enable=all --suppress=missingIncludeSystem
	@echo ">>> Run frama-c..."
	frama-c -no-frama-c-stdlib -wp -wp-no-rte -wp-prover alt-ergo\
    -cpp-extra-args="-DTEST" `find src/ -name *[^test][^main].c`
	@echo "<<< ...Checking done"
test: test_results/ build/test/$(TEST)
	@echo ">>> Run unit and property tests in valgrind..."
	valgrind --leak-check=full ./build/test/$(TEST)
	@echo "<<< ...Testing done"
prof: build/release/$(EXE)
	@echo ">>> Profiling..."
	valgrind --tool=callgrind ./$<
	@echo "<<< ...Profiling done"
fuzz: build/fuzz/$(FUZZ)
	@echo ">>> Fuzzing..."
	afl-fuzz -i afl/in -o afl/out ./$< -x -ly
	@echo "<<< ...Fuzzing"

# sanity tests
test_results/: tests/ shared tests.xml
	@echo ">>> Build api-sanity-checker tests..."
	api-sanity-checker -l $(LIB) -d tests.xml -build
	@echo ">>> Run api-sanity-checker tests..."
	api-sanity-checker -l $(LIB) -d tests.xml -run
tests/: shared tests.xml
	@echo ">>> Testing..."
	@echo ">>> Generate api-sanity-checker tests..."
	api-sanity-checker -lib $(LIB) -d tests.xml -gen

# cleanup
clean:
	rm -rf obj/
	rm -rf tests/ test_results/ logs/
	rm -rf afl/out/
	rm -f callgrind.out.*
cleanall: clean
	rm -rf build/

# objects
build/release/$(EXE):\
  $(OBJECTS_RELEASE_EXE) $(OBJECTS_RELEASE_STATIC) | build/release/
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/debug/$(EXE):\
  $(OBJECTS_DEBUG_EXE) $(OBJECTS_DEBUG_STATIC) | build/debug/
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/test/$(TEST): $(OBJECTS_TEST) | build/test/
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/fuzz/$(FUZZ): $(OBJECTS_FUZZ) | build/fuzz/
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/debug/lib$(LIB).a:\
  $(OBJECTS_DEBUG_STATIC) | build/debug/
	ar $(ARFLAGS) $@ $^
	ranlib $@

build/release/lib$(LIB).a:\
  $(OBJECTS_RELEASE_STATIC) | build/release/
	ar $(ARFLAGS) $@ $^
	ranlib $@

build/debug/lib$(LIB).so:\
  $(OBJECTS_DEBUG_SHARED) | build/debug/
	$(CC) -shared $^ -o $@

build/release/lib$(LIB).so:\
  $(OBJECTS_RELEASE_SHARED) | build/release/
	$(CC) -shared $^ -o $@

# dependencies
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),cleanall)
ifneq ($(MAKECMDGOALS),doc)
ifneq ($(MAKECMDGOALS),check)
include obj/release/static.d
include obj/release/shared.d
include obj/release/exe.d
include obj/debug/static.d
include obj/debug/shared.d
include obj/debug/exe.d
include obj/test.d
include obj/fuzz.d
endif
endif
endif
endif

obj/release/static.d: $(HEADERS) $(SOURCES_LIB) | obj/release/
	@echo ">>> Generating $(STATIC_LIB) release dependencies..."
	@for f in $(SOURCES_LIB); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/release\/static/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(RELEASE_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(STATIC_LIB) release dependencies done"

obj/release/shared.d: $(HEADERS) $(SOURCES_LIB) | obj/release/
	@echo ">>> Generating $(SHARED_LIB) release dependencies..."
	@for f in $(SOURCES_LIB); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/release\/shared/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c -fPIC "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(RELEASE_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(SHARED_LIB) release dependencies done"

obj/release/exe.d: $(HEADERS) $(SOURCES_EXE) | obj/release/
	@echo ">>> Generating $(EXE) release dependencies..."
	@for f in $(SOURCES_EXE); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/release\/exe/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c -O3 "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(RELEASE_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(EXE) release dependencies done"

obj/debug/static.d: $(HEADERS) $(SOURCES_LIB) | obj/debug/
	@echo ">>> Generating $(STATIC_LIB) debug dependencies..."
	@for f in $(SOURCES_LIB); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/debug\/static/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(DEBUG_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(STATIC_LIB) debug dependencies done"

obj/debug/shared.d: $(HEADERS) $(SOURCES_LIB) | obj/debug/
	@echo ">>> Generating $(SHARED_LIB) debug dependencies..."
	@for f in $(SOURCES_LIB); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/debug\/shared/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c -fPIC "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(DEBUG_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(SHARED_LIB) debug dependencies done"

obj/debug/exe.d: $(HEADERS) $(SOURCES_EXE) | obj/debug/
	@echo ">>> Generating $(EXE) debug dependencies..."
	@for f in $(SOURCES_EXE); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/debug\/exe/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(DEBUG_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(EXE) debug dependencies done"

obj/test.d: $(HEADERS) $(SOURCES_TEST) | obj/
	@echo ">>> Generating $(TEST) dependencies..."
	@for f in $(SOURCES_TEST); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/test/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	$(CC) -c "\
        '$$(CPPFLAGS) $$(CFLAGS) $$(TEST_FLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(TEST) debug dependencies done"

obj/fuzz.d: $(HEADERS) $(SOURCES_FUZZ) | obj/
	@echo ">>> Generating $(FUZZ) dependencies..."
	@for f in $(SOURCES_FUZZ); do\
    ( dir=$$(echo $$(dirname $$f) | sed 's/^src/obj\/fuzz/');\
      echo "$$dir/$$(cpp -MM $$f)";\
      echo "	@mkdir -p $$dir";\
      echo "	afl-clang -c "\
        '$$(CPPFLAGS) $$(CFLAGS) $$< -o $$@');\
  done > $@
	@echo "<<< ...Generating $(FUZZ) dependencies done"

# directories
build/:
	@mkdir -p build/
build/release/:
	@mkdir -p build/release/
build/debug/:
	@mkdir -p build/debug/
build/test/:
	@mkdir -p build/test/
build/fuzz/:
	@mkdir -p build/fuzz/
build/doc/:
	@mkdir -p build/doc/
obj/:
	@mkdir -p obj/
obj/release/:
	@mkdir -p obj/release/
obj/debug/:
	@mkdir -p obj/debug/
obj/test/:
	@mkdir -p obj/test/
obj/fuzz/:
	@mkdir -p obj/fuzz/
