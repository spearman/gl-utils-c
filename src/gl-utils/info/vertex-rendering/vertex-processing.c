#include "../../../gl-utils.h"

//
//  gl_info_vertex_processing_constant
//
void gl_info_vertex_processing_constant_print() {
  gl_info_vertex_processing_constant_write (stdout);
}
void gl_info_vertex_processing_constant_write (FILE* file) {
  fprintf (file, "gl info vertex processing constants...\n");
  if (gl_check_context()) {
    GLint glint[4];

    fprintf (file, "  ...vertex shader...\n");
    glGetIntegerv (GL_MAX_VERTEX_ATTRIBS, glint);
    fprintf (file, "GL_MAX_VERTEX_ATTRIBS:                              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_OUTPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_VERTEX_OUTPUT_COMPONENTS:                    %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_ATOMIC_COUNTERS, glint);
    fprintf (file, "GL_MAX_VERTEX_ATOMIC_COUNTERS:                      %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS, glint);
    fprintf (file, "GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS:               %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_UNIFORM_VECTORS, glint);
    fprintf (file, "GL_MAX_VERTEX_UNIFORM_VECTORS:                      %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_VERTEX_UNIFORM_BLOCKS:                       %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_VERTEX_UNIFORM_COMPONENTS:                   %i\n",
      *glint);
    glGetIntegerv (GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS:          %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_VERTEX_IMAGE_UNIFORMS:                       %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS:                  %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS, glint);
    fprintf (file, "GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS:                %i\n",
      *glint);

    fprintf (file, "  ...tessellation shader...\n");
    glGetIntegerv (GL_MAX_TESS_GEN_LEVEL, glint);
    fprintf (file, "GL_MAX_TESS_GEN_LEVEL:                              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_PATCH_VERTICES, glint);
    fprintf (file, "GL_MAX_PATCH_VERTICES:                              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_PATCH_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TESS_PATCH_COMPONENTS:                       %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_INPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_INPUT_COMPONENTS:               %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS:              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS:        %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS:                %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS:         %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS:                 %i\n",
      *glint);
    glGetIntegerv (GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS:    %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS:                 %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS:            %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS, glint);
    fprintf (file, "GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS:          %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS:            %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS:            %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS:             %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS:      %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS:              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS: %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS:              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS:         %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS, glint);
    fprintf (file, "GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS:       %i\n",
      *glint);

    fprintf (file, "  ...geometry shader...\n");
    glGetIntegerv (GL_MAX_GEOMETRY_INPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_INPUT_COMPONENTS:                   %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_OUTPUT_VERTICES, glint);
    fprintf (file, "GL_MAX_GEOMETRY_OUTPUT_VERTICES:                    %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_OUTPUT_COMPONENTS:                  %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS:            %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VERTEX_STREAMS, glint);
    fprintf (file, "GL_MAX_VERTEX_STREAMS:                              %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_SHADER_INVOCATIONS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_SHADER_INVOCATIONS:                 %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_ATOMIC_COUNTERS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_ATOMIC_COUNTERS:                    %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS:             %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_UNIFORM_BLOCKS:                     %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS:                 %i\n",
      *glint);
    glGetIntegerv (GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS, glint);
    fprintf (file, "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS:        %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_IMAGE_UNIFORMS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_IMAGE_UNIFORMS:                     %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS:                %i\n",
      *glint);
    glGetIntegerv (GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS, glint);
    fprintf (file, "GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS:              %i\n",
      *glint);
  }
  fprintf (file, "...gl info vertex processing constants\n");
}

//
//  gl_info_vertex_processing_state
//
void gl_info_vertex_processing_state_print() {
  gl_info_vertex_processing_state_write (stdout);
}
void gl_info_vertex_processing_state_write (FILE* file) {
  fprintf (file, "gl info vertex processing state...\n");
  if (gl_check_context()) {
    GLint     glint   [4];
    GLboolean glbool  [4];
    GLfloat   glfloat [4];
    fprintf (file, "  ...vertex shader...\n");
    glGetBooleanv (GL_PROGRAM_POINT_SIZE, glbool);
    fprintf (file, "GL_PROGRAM_POINT_SIZE:        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_VERTEX_PROGRAM_POINT_SIZE, glbool);
    fprintf (file, "GL_VERTEX_PROGRAM_POINT_SIZE: %s\n",
      gl_show_boolean (*glbool));

    fprintf (file, "  ...tessellation shader...\n");
    glGetIntegerv (GL_PATCH_VERTICES, glint);
    fprintf (file, "GL_PATCH_VERTICES:            %i\n", *glint);
    glGetFloatv (GL_PATCH_DEFAULT_INNER_LEVEL, glfloat);
    fprintf (file, "GL_PATCH_DEFAULT_INNER_LEVEL: %f %f\n",
      glfloat[0], glfloat[1]);
    glGetFloatv (GL_PATCH_DEFAULT_OUTER_LEVEL, glfloat);
    fprintf (file, "GL_PATCH_DEFAULT_OUTER_LEVEL: %f %f %f %f\n",
      glfloat[0], glfloat[1], glfloat[2], glfloat[3]);

    fprintf (file, "  ...geometry shader...\n");
  }
  fprintf (file, "...gl info vertex processing state\n");
}
