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
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);

    GLint glint[4];
    // gl 4.4
    if (4 < gl_major_version
      || (4 == gl_major_version && 4 <= gl_minor_version))
    {
      glGetIntegerv (GL_QUERY_BUFFER_BINDING, glint);
      fprintf (file, "GL_QUERY_BUFFER_BINDING:  %i\n", *glint);
    }
  }
  fprintf (file, "...gl info asynchronous queries state\n");
}
