# `gl-utils`

> A collection of OpenGL utility functions.


## Building

To allow building object files with different flags for different targets, they
will be put in obj/*target* directories, where target is:

- obj/release/exe/
- obj/release/static/
- obj/release/shared/
- obj/debug/exe/
- obj/debug/static/
- obj/debug/shared/
- obj/test/
- obj/fuzz/

&#x261e; *Note*: test needs its own object files if we are to conditionally
compile in test functions-- this allows tests to be written in the same file as
the code being tested, while omitting those tests from regular builds

&#x261e; *Note*: fuzz also gets its own object files because to fuzz test with
`afl-fuzz`, the program must be built with instrumentation by `afl-clang`
instead of the usual compiler

| `make [all]` -- check and build the release executable
| `make build` -- build the debug executable
| `make debug` -- build the debug executable and open with `gdb`
| `make release` -- build the release executable
| `make run` -- build and run the debug executable
| `make run-release` -- build and run the release executable
| `make lib` -- build the debug static library
| `make lib-release` -- build the release static library
| `make shared` -- build the debug shared library
| `make shared-release` -- build the release shared library
| `make doc` -- build documentation
| `make doc-open` -- build documentation and open with `gnome-open`
| `make check` -- perform static analysis (cppcheck + frama-c)
    *partially implemented*
| `make test` -- generate, build and execute smoke tests (api sanity
    checker) and then run unit, property, and integration tests
    (theft, glib testing) with `valgrind --leak-check=full`
| `make fuzz` -- build fuzz executable with `afl-clang` and run fuzz
    tests with `afl-fuzz`
| `make profile` -- generate Kcachegrind profiling information by
    running release executable with `valgrind --tool=callgrind`
| `make bench` -- *not implemented*
| `make dist` -- create some sort of distributable archive *not
    implemented*


## Cleanup

`$ make clean` -- will clean up intermediate build products (the contents of
`./obj/`)

`$ make cleanall` -- will clean up intermediate and final build products (the
contents of `./obj/` and `./build/`)


## Usage

Build either the static library `libglutilslib.a` (with `$ make lib-release`)
and link directly, or else the shared library `libglutilslib.so` (with `$make
shared-release`) and make sure it is on the runtime library search path and
linked properly.

Include the main header file:

```c
#include "gl-utils.h"
```

After OpenGL has been initialized, functions may be called:

```c
  gl_info_context_constant_print();
  gl_check_error();
  gl_info_context_state_print();
  gl_check_error();
```

An example program has been included in `./src/main.c` which can be run with `$
make run`.

The environment variable `GL_UTILS_FATAL_ERRORS` may be set to cause an
assertion failure whenever an OpenGL error is encountered with
`gl_check_error`. (Note that currently error checking is *not* done after every
internal GL call so an error may be missed until the next time `gl_check_error`
is called).

For full API documentation, Doxygen docs may be generated with `$ make doc`
which will build documentation in `./build/doc/html/`.
