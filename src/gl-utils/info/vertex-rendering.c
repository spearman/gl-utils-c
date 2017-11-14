#include "../../gl-utils.h"

//
//  gl_info_vertex_rendering_constant
//
void gl_info_vertex_rendering_constant_print() {
  gl_info_vertex_rendering_constant_write (stdout);
}
void gl_info_vertex_rendering_constant_write (FILE* file) {
  fprintf (file, "gl info vertex rendering constants...\n");
  if (gl_check_context()) {
    gl_info_vertex_processing_constant_write     (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_vertex_postprocessing_constant_write (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_primitive_assembly_constant_write    (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_rasterization_constant_write         (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_persample_early_constant_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_fragment_shader_constant_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_persample_processing_constant_write  (file);
    gl_check_error();
  }
  fprintf (file, "...gl info vertex rendering constants\n");
}

//
//  gl_info_vertex_rendering_state
//
void gl_info_vertex_rendering_state_print() {
  gl_info_vertex_rendering_state_write (stdout);
}
void gl_info_vertex_rendering_state_write (FILE* file) {
  fprintf (file, "gl info vertex rendering state...\n");
  if (gl_check_context()) {
    gl_info_vertex_processing_state_write     (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_vertex_postprocessing_state_write (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_primitive_assembly_state_write    (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_rasterization_state_write         (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_persample_early_state_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_fragment_shader_state_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_persample_processing_state_write  (file);
    gl_check_error();
  }
  fprintf (file, "...gl info vertex rendering state\n");
}
