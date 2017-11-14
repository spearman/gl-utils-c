#include "../../gl-utils.h"

//
//  glew_info
//
void glew_info_print() {
  glew_info_write (stdout);
}
void glew_info_write (FILE* file) {
  fprintf (file, "glew info...\n");
  if (gl_check_context()) {
    fprintf (file, "GLEW_VERSION: %s\n", glewGetString (GLEW_VERSION));
  }
  fprintf (file, "...glew info\n");
}
