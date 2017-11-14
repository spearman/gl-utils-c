#include "../gl-utils.h"

//
//  gl_info_constant
//
void gl_info_constant_print() {
  gl_info_constant_write (stdout);
}
void gl_info_constant_write (FILE* file) {
  fprintf (file, "gl info constant...\n");
  if (gl_check_context()) {
    gl_info_context_constant_write               (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_shader_program_constant_write        (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_texture_constant_write               (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_image_loadstore_constant_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_framebuffer_constant_write           (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_vertex_specification_constant_write  (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_vertex_rendering_constant_write      (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_compute_shader_constant_write        (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_pixel_transfer_constant_write        (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_synchronization_constant_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_asynchronous_queries_constant_write  (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_debug_output_constant_write          (file);
    gl_check_error();
  }
  fprintf (file, "...gl info constant\n");
}

//
//  gl_info_state
//
void gl_info_state_print() {
  gl_info_state_write (stdout);
}
void gl_info_state_write (FILE* file) {
  fprintf (file, "gl state info...\n");
  if (gl_check_context()) {
    gl_info_context_state_write               (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_shader_program_state_write        (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_framebuffer_state_write           (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_texture_state_write               (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_image_loadstore_state_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_vertex_specification_state_write  (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_vertex_rendering_state_write      (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_compute_shader_state_write        (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_pixel_transfer_state_write        (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_synchronization_state_write       (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_asynchronous_queries_state_write  (file);
    gl_check_error();
    fprintf (file, "\n");
    gl_info_debug_output_state_write          (file);
    gl_check_error();
  }
  fprintf (file, "...gl state info\n");
}
