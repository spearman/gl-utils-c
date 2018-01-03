#include "gl-utils.h"

bool gl_check_context() {
  if (glGetString == NULL) {
    printf ("OpenGL functions not loaded\n");
    assert (0);
    return false;
  } else {
    const GLubyte* version = NULL;
    version = glGetString (GL_VERSION);
    if (version == NULL) {
      printf ("OpenGL context not initialized\n");
      assert (0);
      return false;
    } else {
      return true;
    }
  }
}

/// The environment variable `GL_UTILS_FATAL_ERRORS` may be defined to cause
/// this function to raise a fatal assertion when an error is encountered.
void gl_check_error() {
  if (gl_check_context()) {
    GLenum error   = glGetError();
    bool was_error = false;
    while (error != GL_NO_ERROR) {
      printf ("glGetError(): %s\n", gl_show_error (error));
      error = glGetError();
      was_error = true;
    }
    if (getenv ("GL_UTILS_FATAL_ERRORS")) {
      assert (!was_error);
    }
  }
}

//
//  gl_info_context_extensions
//
bool gl_extension_is_supported (const char* extension) {
  bool found = false;
  if (gl_check_context()) {
    GLint n;
    glGetIntegerv (GL_NUM_EXTENSIONS, &n);
    for (GLint i = 0; i < n; ++i) {
      const GLubyte* glext = glGetStringi (GL_EXTENSIONS, i);
      if (0 == strcmp (extension, (const char*) glext)) {
        found = true;
        break;
      }
    }
  }
  return found;
}

/// This is just an example function that shows usage of a Frama-C ACSL
/// function contract:
///
/// \code{.unparsed}
/// ensures 0 <= \result;
/// \endcode
/*@
  ensures 0 <= \result;
*/
int myfun (const int x, const int y) {
  return (x < y) ? 0 : x-y;
}

/// This is just an example function that shows usage of a Frama-C ACSL
/// function contract:
///
/// \code{.unparsed}
/// requires 1<= x;
/// ensures 1 <= \result;
/// \endcode
/*@
  requires 1 <= x;
  ensures 1 <= \result;
*/
int pos_id (const int x) {
  return x;
}

#ifdef TEST
#include <assert.h>
void test_myfun() {
  assert (myfun (5,4) == 1);
  assert (myfun (4,5) == 0);
}
void test_pos_id() {
  assert (pos_id (5) == 5);
  assert (pos_id (1) == 1);
}
#endif
