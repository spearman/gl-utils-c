#include "../../gl-utils.h"

//
//  gl_info_asynchronous_queries_constant
//
void gl_info_asynchronous_queries_constant_print() {
  gl_info_asynchronous_queries_constant_write (stdout);
}
void gl_info_asynchronous_queries_constant_write (FILE* file) {
  fprintf (file, "gl info asynchronous queries constants...\n");
  if (gl_check_context()) { }
  fprintf (file, "...gl info asynchronous queries constants\n");
}

//
//  gl_info_asynchronous_queries_state
//
void gl_info_asynchronous_queries_state_print() {
  gl_info_asynchronous_queries_state_write (stdout);
}
void gl_info_asynchronous_queries_state_write (FILE* file) {
  fprintf (file, "gl info asynchronous queries state...\n");
  if (gl_check_context()) {
    GLint glint[4];
    glGetIntegerv (GL_QUERY_BUFFER_BINDING, glint);
    fprintf (file, "GL_QUERY_BUFFER_BINDING:  %i\n", *glint);
  }
  fprintf (file, "...gl info asynchronous queries state\n");
}
