#include "../../gl-utils.h"

//
//  gl_info_image_loadstore_constant
//
void gl_info_image_loadstore_constant_print() {
  gl_info_image_loadstore_constant_write (stdout);
}
void gl_info_image_loadstore_constant_write (FILE* file) {
  fprintf (file, "gl info image loadstore constants...\n");
  if (gl_check_context()) {
    GLint     glint [4];
    //GLboolean glbool[4];
    glGetIntegerv (GL_MAX_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_IMAGE_UNITS:             %i\n", *glint);
    glGetIntegerv (GL_MAX_COMBINED_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_COMBINED_IMAGE_UNIFORMS: %i\n", *glint);
  }
  fprintf (file, "...gl info image loadstore constants\n");
}

//
//  gl_info_image_loadstore_state
//
void gl_info_image_loadstore_state_print() {
  gl_info_image_loadstore_state_write (stdout);
}
void gl_info_image_loadstore_state_write (FILE* file) {
  fprintf (file, "gl info image loadstore state...\n");
  if (gl_check_context()) {
    GLint     glint [4];
    GLboolean glbool[4];
    GLint image_units;
    glGetIntegerv (GL_MAX_IMAGE_UNITS, &image_units);
    for (GLint i = 0; i < image_units; ++i) {
      glGetIntegeri_v (GL_IMAGE_BINDING_NAME, i, glint);
      fprintf (file, "GL_IMAGE_BINDING_NAME   [%i]: %i\n", i, *glint);
      glGetIntegeri_v (GL_IMAGE_BINDING_FORMAT, i, glint);
      fprintf (file, "GL_IMAGE_BINDING_FORMAT [%i]: %s\n", i,
        gl_show_image_format (*glint));
      glGetIntegeri_v (GL_IMAGE_BINDING_LEVEL, i, glint);
      fprintf (file, "GL_IMAGE_BINDING_LEVEL  [%i]: %i\n", i, *glint);
      glGetIntegeri_v (GL_IMAGE_BINDING_ACCESS, i, glint);
      fprintf (file, "GL_IMAGE_BINDING_ACCESS [%i]: %s\n", i,
        gl_show_rw_access (*glint));
      glGetBooleani_v (GL_IMAGE_BINDING_LAYERED, i, glbool);
      fprintf (file, "GL_IMAGE_BINDING_LAYERED[%i]: %s\n", i,
        gl_show_boolean (*glbool));
      glGetIntegeri_v (GL_IMAGE_BINDING_LAYER, i, glint);
      fprintf (file, "GL_IMAGE_BINDING_LAYER  [%i]: %i\n", i, *glint);
    }
  }
  fprintf (file, "...gl info image loadstore state\n");
}
