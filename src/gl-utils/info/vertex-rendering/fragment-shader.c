#include "../../../gl-utils.h"

//
//  gl_info_fragment_shader_constant
//
void gl_info_fragment_shader_constant_print() {
  gl_info_fragment_shader_constant_write (stdout);
}
void gl_info_fragment_shader_constant_write (FILE* file) {
  fprintf (file, "gl info fragment shader constants...\n");
  if (gl_check_context()) {
    GLint   glint[4];
    glGetIntegerv (GL_MAX_FRAGMENT_INPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_INPUT_COMPONENTS:             %i\n", *glint);
    glGetIntegerv (GL_MAX_DRAW_BUFFERS, glint);
    fprintf (file, "GL_MAX_DRAW_BUFFERS:                          %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_ATOMIC_COUNTERS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_ATOMIC_COUNTERS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS:       %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_UNIFORM_VECTORS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_UNIFORM_VECTORS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_UNIFORM_BLOCKS:               %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS:           %i\n", *glint);
    glGetIntegerv (GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS:  %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_IMAGE_UNIFORMS:               %i\n", *glint);
    glGetIntegerv (GL_MAX_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_TEXTURE_IMAGE_UNITS:                   %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS, glint);
    fprintf (file, "GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS:        %i\n", *glint);
    glGetIntegerv (GL_FRAGMENT_INTERPOLATION_OFFSET_BITS, glint);
    fprintf (file, "GL_FRAGMENT_INTERPOLATION_OFFSET_BITS:        %i\n", *glint);
    glGetIntegerv (GL_MIN_FRAGMENT_INTERPOLATION_OFFSET, glint);
    fprintf (file, "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET:         %i\n", *glint);
    glGetIntegerv (GL_MAX_FRAGMENT_INTERPOLATION_OFFSET, glint);
    fprintf (file, "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET:         %i\n", *glint);
    glGetIntegerv (GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET, glint);
    fprintf (file, "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET:         %i\n", *glint);
    glGetIntegerv (GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET, glint);
    fprintf (file, "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET:         %i\n", *glint);
  }
  fprintf (file, "...gl info fragment shader constants\n");
}

//
//  gl_info_fragment_shader_state
//
void gl_info_fragment_shader_state_print() {
  gl_info_fragment_shader_state_write (stdout);
}
void gl_info_fragment_shader_state_write (FILE* file) {
  fprintf (file, "gl info fragment shader state...\n");
  if (gl_check_context()) {
    GLint   glint[4];
    glGetIntegerv (GL_FRAGMENT_SHADER_DERIVATIVE_HINT, glint);
    fprintf (file, "GL_FRAGMENT_SHADER_DERIVATIVE_HINT: %s\n",
      gl_show_hint (*glint));
  }
  fprintf (file, "...gl info fragment shader state\n");
}
