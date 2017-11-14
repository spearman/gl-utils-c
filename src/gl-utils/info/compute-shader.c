#include "../../gl-utils.h"

//
//  gl_info_compute_shader_constant
//
void gl_info_compute_shader_constant_print() {
  gl_info_compute_shader_constant_write (stdout);
}
void gl_info_compute_shader_constant_write (FILE* file) {
  fprintf (file, "gl info compute shader constants...\n");
  if (gl_check_context()) {
    GLint glint[4];
    glGetIntegerv (GL_MAX_COMPUTE_ATOMIC_COUNTERS, glint);
    fprintf (file, "GL_MAX_COMPUTE_ATOMIC_COUNTERS:             %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS, glint);
    fprintf (file, "GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS:      %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_COMPUTE_UNIFORM_BLOCKS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMPUTE_UNIFORM_COMPONENTS:          %i\n", *glint);
    glGetIntegerv (GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS: %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_COMPUTE_IMAGE_UNIFORMS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS:         %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS, glint);
    fprintf (file, "GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS:       %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_SHARED_MEMORY_SIZE, glint);
    fprintf (file, "GL_MAX_COMPUTE_SHARED_MEMORY_SIZE:          %i\n", *glint);
    glGetIntegerv (GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS:      %i\n", *glint);
    glGetIntegeri_v (GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_COUNT[0]:         %i\n", *glint);
    glGetIntegeri_v (GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_COUNT[1]:         %i\n", *glint);
    glGetIntegeri_v (GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_COUNT[2]:         %i\n", *glint);
    glGetIntegeri_v (GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_SIZE[0]:          %i\n", *glint);
    glGetIntegeri_v (GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_SIZE[1]:          %i\n", *glint);
    glGetIntegeri_v (GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, glint);
    fprintf (file, "GL_MAX_COMPUTE_WORK_GROUP_SIZE[2]:          %i\n", *glint);
  }
  fprintf (file, "...gl info compute shader constants\n");
}

//
//  gl_info_compute_shader_state
//
void gl_info_compute_shader_state_print() {
  gl_info_compute_shader_state_write (stdout);
}
void gl_info_compute_shader_state_write (FILE* file) {
  fprintf (file, "gl info compute shader state...\n");
  if (gl_check_context()) {
    GLint     glint [4];
    glGetIntegerv (GL_DISPATCH_INDIRECT_BUFFER_BINDING, glint);
    fprintf (file, "GL_DISPATCH_INDIRECT_BUFFER_BINDING: %i\n", *glint);
  }
  fprintf (file, "...gl info compute shader state\n");
}
