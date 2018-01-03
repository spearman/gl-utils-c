#include "../../gl-utils.h"

//
//  gl_info_debug_output_constant
//
void gl_info_debug_output_constant_print() {
  gl_info_debug_output_constant_write (stdout);
}
void gl_info_debug_output_constant_write (FILE* file) {
  fprintf (file, "gl info debug output constants...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);
    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_major_version))
    {
      GLint glint[4];
      glGetIntegerv (GL_MAX_DEBUG_GROUP_STACK_DEPTH, glint);
      fprintf (file, "GL_MAX_DEBUG_GROUP_STACK_DEPTH: %i\n", *glint);
      glGetIntegerv (GL_MAX_DEBUG_LOGGED_MESSAGES, glint);
      fprintf (file, "GL_MAX_DEBUG_LOGGED_MESSAGES:   %i\n", *glint);
      glGetIntegerv (GL_MAX_DEBUG_MESSAGE_LENGTH, glint);
      fprintf (file, "GL_MAX_DEBUG_MESSAGE_LENGTH:    %i\n", *glint);
      glGetIntegerv (GL_MAX_LABEL_LENGTH, glint);
      fprintf (file, "GL_MAX_LABEL_LENGTH:            %i\n", *glint);
    } else {
      fprintf (file,
        "  debug output requires OpenGL version 4.3 or greater\n");
    }
  }
  fprintf (file, "...gl info debug output constants\n");
}

//
//  gl_info_debug_output_state
//
void gl_info_debug_output_state_print() {
  gl_info_debug_output_state_write (stdout);
}
void gl_info_debug_output_state_write (FILE* file) {
  fprintf (file, "gl info debug output state...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);
    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_major_version))
    {
      GLint     glint [4];
      GLboolean glbool[4];
      glGetBooleanv (GL_DEBUG_OUTPUT, glbool);
      fprintf (file, "GL_DEBUG_OUTPUT:                      %s\n",
        gl_show_boolean (*glbool));
      glGetBooleanv (GL_DEBUG_OUTPUT_SYNCHRONOUS, glbool);
      fprintf (file, "GL_DEBUG_OUTPUT_SYNCHRONOUS:          %s\n",
        gl_show_boolean (*glbool));
      glGetIntegerv (GL_DEBUG_GROUP_STACK_DEPTH, glint);
      fprintf (file, "GL_DEBUG_GROUP_STACK_DEPTH:           %i\n", *glint);
      glGetIntegerv (GL_DEBUG_LOGGED_MESSAGES, glint);
      fprintf (file, "GL_DEBUG_LOGGED_MESSAGES:             %i\n", *glint);
      glGetIntegerv (GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH, glint);
      fprintf (file, "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH:  %i\n", *glint);
    } else {
      fprintf (file,
        "  debug output requires OpenGL version 4.3 or greater\n");
    }
  }
  fprintf (file, "...gl info debug output state\n");
}
