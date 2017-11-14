#include "../../../gl-utils.h"

//
//  gl_info_persample_early_constant
//
void gl_info_persample_early_constant_print() {
  gl_info_persample_early_constant_write (stdout);
}
void gl_info_persample_early_constant_write (FILE* file) {
  fprintf (file, "gl info persample early constants...\n");
  if (gl_check_context()) {
    //GLint   glint[4];
    fprintf (file, "  ...pixel ownership test...\n");
    fprintf (file, "  ...scissor test...\n");
  }
  fprintf (file, "...gl info persample early constants\n");
}

//
//  gl_info_persample_early_state
//
void gl_info_persample_early_state_print() {
  gl_info_persample_early_state_write (stdout);
}
void gl_info_persample_early_state_write (FILE* file) {
  fprintf (file, "gl info persample early state...\n");
  if (gl_check_context()) {
    //GLint     glint  [4];
    GLboolean glbool [4];
    GLfloat   glfloat[4];
    fprintf (file, "  ...pixel ownership test...\n");
    fprintf (file, "  ...scissor test...\n");
    GLint max_viewports;
    glGetIntegerv (GL_MAX_VIEWPORTS, &max_viewports);
    for (GLint i = 0; i < max_viewports; ++i) {
      glGetBooleani_v (GL_SCISSOR_TEST, i, glbool);
      fprintf (file, "GL_SCISSOR_TEST [%2i]: %s\n",
        i, gl_show_boolean (*glbool));
      glGetFloati_v (GL_SCISSOR_BOX, i, glfloat);
      fprintf (file, "GL_SCISSOR_BOX  [%2i]: %f %f %f %f\n",
        i, glfloat[0], glfloat[1], glfloat[2], glfloat[3]);
    }
  }
  fprintf (file, "...gl info persample early state\n");
}
