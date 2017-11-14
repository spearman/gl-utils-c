#include "../../gl-utils.h"

//
//  gl_info_texture_constant
//
void gl_info_texture_constant_print() {
  gl_info_texture_constant_write (stdout);
}
void gl_info_texture_constant_write (FILE* file) {
  fprintf (file, "gl info texture constants...\n");
  if (gl_check_context()) {
    GLint     glint [4];
    //GLboolean glbool[4];
    glGetIntegerv (GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS:  %i\n", *glint);
    glGetIntegerv (GL_MAX_TEXTURE_SIZE, glint);
    fprintf (file, "GL_MAX_TEXTURE_SIZE:                  %i\n", *glint);
    glGetIntegerv (GL_MAX_RENDERBUFFER_SIZE, glint);
    fprintf (file, "GL_MAX_RENDERBUFFER_SIZE:             %i\n", *glint);
    glGetIntegerv (GL_MAX_TEXTURE_BUFFER_SIZE, glint);
    fprintf (file, "GL_MAX_TEXTURE_BUFFER_SIZE:           %i\n", *glint);
    glGetIntegerv (GL_MAX_RECTANGLE_TEXTURE_SIZE, glint);
    fprintf (file, "GL_MAX_RECTANGLE_TEXTURE_SIZE:        %i\n", *glint);
    glGetIntegerv (GL_MAX_CUBE_MAP_TEXTURE_SIZE, glint);
    fprintf (file, "GL_MAX_CUBE_MAP_TEXTURE_SIZE:         %i\n", *glint);
    glGetIntegerv (GL_MAX_3D_TEXTURE_SIZE, glint);
    fprintf (file, "GL_MAX_3D_TEXTURE_SIZE:               %i\n", *glint);
    glGetIntegerv (GL_MAX_ARRAY_TEXTURE_LAYERS, glint);
    fprintf (file, "GL_MAX_ARRAY_TEXTURE_LAYERS:          %i\n", *glint);
    glGetIntegerv (GL_MAX_TEXTURE_LOD_BIAS, glint);
    fprintf (file, "GL_MAX_TEXTURE_LOD_BIAS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_IMAGE_SAMPLES, glint);
    fprintf (file, "GL_MAX_IMAGE_SAMPLES:                 %i\n", *glint);
    glGetIntegerv (GL_MIN_PROGRAM_TEXEL_OFFSET, glint);
    fprintf (file, "GL_MIN_PROGRAM_TEXEL_OFFSET:          %i\n", *glint);
    glGetIntegerv (GL_MAX_PROGRAM_TEXEL_OFFSET, glint);
    fprintf (file, "GL_MAX_PROGRAM_TEXEL_OFFSET:          %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT, glint);
    fprintf (file, "GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT:   %i\n", *glint);
  }
  fprintf (file, "...gl info texture constants\n");
}

//
//  gl_info_texture_state
//
void gl_info_texture_state_print() {
  gl_info_texture_state_write (stdout);
}
void gl_info_texture_state_write (FILE* file) {
  fprintf (file, "gl info texture state...\n");
  if (gl_check_context()) {
    GLint     glint [4];
    GLboolean glbool[4];
    glGetIntegerv (GL_ACTIVE_TEXTURE, glint);
    fprintf (file, "GL_ACTIVE_TEXTURE:                        %s\n",
      gl_show_texture_unit (*glint));
    glGetIntegerv (GL_SAMPLER_BINDING, glint);
    fprintf (file, "GL_SAMPLER_BINDING:                       %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BUFFER_BINDING, glint);
    fprintf (file, "GL_TEXTURE_BUFFER_BINDING:                %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_BUFFER, glint);
    fprintf (file, "GL_TEXTURE_BINDING_BUFFER:                %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_RECTANGLE, glint);
    fprintf (file, "GL_TEXTURE_BINDING_RECTANGLE:             %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_1D, glint);
    fprintf (file, "GL_TEXTURE_BINDING_1D:                    %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_2D, glint);
    fprintf (file, "GL_TEXTURE_BINDING_2D:                    %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_2D_MULTISAMPLE, glint);
    fprintf (file, "GL_TEXTURE_BINDING_2D_MULTISAMPLE:        %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_3D, glint);
    fprintf (file, "GL_TEXTURE_BINDING_3D:                    %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_CUBE_MAP, glint);
    fprintf (file, "GL_TEXTURE_BINDING_CUBE_MAP:              %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_1D_ARRAY, glint);
    fprintf (file, "GL_TEXTURE_BINDING_1D_ARRAY:              %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_2D_ARRAY, glint);
    fprintf (file, "GL_TEXTURE_BINDING_2D_ARRAY:              %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, glint);
    fprintf (file, "GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY:  %i\n", *glint);
    glGetIntegerv (GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, glint);
    fprintf (file, "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY:        %i\n", *glint);
    glGetBooleanv (GL_TEXTURE_CUBE_MAP_SEAMLESS, glbool);
    fprintf (file, "GL_TEXTURE_CUBE_MAP_SEAMLESS:             %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_TEXTURE_COMPRESSION_HINT, glint);
    fprintf (file, "GL_TEXTURE_COMPRESSION_HINT:              %s\n",
      gl_show_hint (*glint));
  }
  fprintf (file, "...gl info texture state\n");
}
