#include "../../gl-utils.h"

//
//  gl_info_synchronization_constant
//
void gl_info_synchronization_constant_print() {
  gl_info_synchronization_constant_write (stdout);
}
void gl_info_synchronization_constant_write (FILE* file) {
  fprintf (file, "gl info synchronization constants...\n");
  if (gl_check_context()) {
    GLint glint[4];
    glGetIntegerv (GL_MAX_SERVER_WAIT_TIMEOUT, glint);
    fprintf (file, "GL_MAX_SERVER_WAIT_TIMEOUT:   %i\n", *glint);
  }
  fprintf (file, "...gl info synchronization constants\n");
}

//
//  gl_info_synchronization_state
//
void gl_info_synchronization_state_print() {
  gl_info_synchronization_state_write (stdout);
}
void gl_info_synchronization_state_write (FILE* file) {
  fprintf (file, "gl info synchronization state...\n");
  if (gl_check_context()) { }
  fprintf (file, "...gl info synchronization state\n");
}
