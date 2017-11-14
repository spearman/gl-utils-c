#include "../../../gl-utils.h"

//
//  gl_info_primitive_assembly_constant
//
void gl_info_primitive_assembly_constant_print() {
  gl_info_primitive_assembly_constant_write (stdout);
}
void gl_info_primitive_assembly_constant_write (FILE* file) {
  fprintf (file, "gl info primitive assembly constants...\n");
  if (gl_check_context()) {
    fprintf (file, "  ...face culling...\n");
  }
  fprintf (file, "...gl info primitive assembly constants\n");
}

//
//  gl_info_primitive_assembly_state
//
void gl_info_primitive_assembly_state_print() {
  gl_info_primitive_assembly_state_write (stdout);
}
void gl_info_primitive_assembly_state_write (FILE* file) {
  fprintf (file, "gl info primitive assembly state...\n");
  if (gl_check_context()) {
    GLint glint[4];
    GLboolean glbool[4];
    fprintf (file, "  ...face culling...\n");
    *glbool = glIsEnabled (GL_CULL_FACE );
    fprintf (file, "glIsEnabled (GL_CULL_FACE): %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_CULL_FACE_MODE, glint);
    fprintf (file, "GL_CULL_FACE_MODE:          %s\n",
      gl_show_cull_face_mode (*glint));
    glGetIntegerv (GL_FRONT_FACE, glint);
    fprintf (file, "GL_FRONT_FACE:              %s\n",
      gl_show_winding (*glint));
  }
  fprintf (file, "...gl info primitive assembly state\n");
}
