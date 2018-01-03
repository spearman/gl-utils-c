#include "../../gl-utils.h"

//
//  gl_info_shader_program_constant
//
void gl_info_shader_program_constant_print() {
  gl_info_shader_program_constant_write (stdout);
}
void gl_info_shader_program_constant_write (FILE* file) {
  fprintf (file, "gl info shader program constants...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);

    GLint     glint [4];
    GLboolean glbool[4];

    glGetIntegerv (GL_MAX_UNIFORM_BLOCK_SIZE, glint);
    fprintf (file, "GL_MAX_UNIFORM_BLOCK_SIZE:                %i\n", *glint);
    gl_check_error();
    glGetIntegerv (GL_MAX_UNIFORM_BUFFER_BINDINGS, glint);
    fprintf (file, "GL_MAX_UNIFORM_BUFFER_BINDINGS:           %i\n", *glint);
    gl_check_error();
    glGetIntegerv (GL_MAX_COMBINED_UNIFORM_BLOCKS, glint);
    fprintf (file, "GL_MAX_COMBINED_UNIFORM_BLOCKS:           %i\n", *glint);
    gl_check_error();

    // gl 4.0
    if (4 <= gl_major_version) {
      glGetIntegerv (GL_MAX_SUBROUTINES, glint);
      fprintf (file, "GL_MAX_SUBROUTINES:                       %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS, glint);
      fprintf (file, "GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS:      %i\n", *glint);
      gl_check_error();
    }
    // gl 4.1
    if (4 < gl_major_version
      || (4 == gl_major_version && 1 <= gl_major_version))
    {
      glGetBooleanv (GL_SHADER_COMPILER, glbool);
      fprintf (file, "GL_SHADER_COMPILER:                       %s\n",
         gl_show_boolean (*glbool));
      gl_check_error();
      glGetIntegerv (GL_NUM_PROGRAM_BINARY_FORMATS, glint);
      fprintf (file, "GL_NUM_PROGRAM_BINARY_FORMATS:            %i\n", *glint);
      gl_check_error();
      GLint program_binary_fmts[*glint];
      glGetIntegerv (GL_PROGRAM_BINARY_FORMATS, program_binary_fmts);
      fprintf (file, "GL_PROGRAM_BINARY_FORMATS:             ");
      for (GLint i = 0; i < *glint; ++i) {
        fprintf (file, "   %x", program_binary_fmts[i]);
      }
      fprintf (file, "\n");
      gl_check_error();
      glGetIntegerv (GL_NUM_SHADER_BINARY_FORMATS, glint);
      fprintf (file, "GL_NUM_SHADER_BINARY_FORMATS:             %i\n", *glint);
      gl_check_error();
      GLint shader_binary_fmts[*glint];
      glGetIntegerv (GL_SHADER_BINARY_FORMATS, shader_binary_fmts);
      fprintf (file, "GL_SHADER_BINARY_FORMATS:              ");
      for (GLint i = 0; i < *glint; ++i) {
        fprintf (file, "   %x", shader_binary_fmts[i]);
      }
      fprintf (file, "\n");
      gl_check_error();
    }

    // gl 4.2
    if (4 < gl_major_version
      || (4 == gl_major_version && 2 <= gl_major_version))
    {
      glGetIntegerv (GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS, glint);
      fprintf (file, "GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS:    %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE, glint);
      fprintf (file, "GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE:        %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_COMBINED_ATOMIC_COUNTERS, glint);
      fprintf (file, "GL_MAX_COMBINED_ATOMIC_COUNTERS:          %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS, glint);
      fprintf (file, "GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS:   %i\n", *glint);
      gl_check_error();
    }

    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_major_version))
    {
      glGetIntegerv (GL_MAX_UNIFORM_LOCATIONS, glint);
      fprintf (file, "GL_MAX_UNIFORM_LOCATIONS:                 %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_SHADER_STORAGE_BLOCK_SIZE, glint);
      fprintf (file, "GL_MAX_SHADER_STORAGE_BLOCK_SIZE:         %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, glint);
      fprintf (file, "GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS:    %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS, glint);
      fprintf (file, "GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS:    %i\n", *glint);
      gl_check_error();
      glGetIntegerv (GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES, glint);
      fprintf (file, "GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES:  %i\n", *glint);
      gl_check_error();
    }

  }
  fprintf (file, "...gl info shader program constants\n");
}

//
//  gl_info_shader_program_state
//
void gl_info_shader_program_state_print() {
  gl_info_shader_program_state_write (stdout);
}
void gl_info_shader_program_state_write (FILE* file) {
  fprintf (file, "gl info shader program state...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);
    GLint glint[4];
    glGetIntegerv (GL_CURRENT_PROGRAM, glint);
    fprintf (file, "GL_CURRENT_PROGRAM:                         %i\n", *glint);
    glGetIntegerv (GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, glint);
    fprintf (file, "GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT:         %i\n", *glint);
    // gl 4.1
    if (4 < gl_major_version
      || (4 == gl_major_version && 1 <= gl_major_version))
    {
      //glGetIntegerv (GL_PROGRAM_PIPELINE_BINDING, glint);
      fprintf (file, "GL_PROGRAM_PIPELINE_BINDING:                %i\n", *glint);
    }
    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_major_version))
    {
      glGetIntegerv (GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, glint);
      fprintf (file, "GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT:  %i\n", *glint);
    }
  }
  fprintf (file, "...gl info shader program state\n");
}

//
//  gl_info_shader_program_buffers
//
void gl_info_shader_program_buffers_print() {
  gl_info_shader_program_buffers_write (stdout);
}
void gl_info_shader_program_buffers_write (FILE* file) {
  fprintf (file, "gl info shader program buffers...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);

    GLint glint[4];
    GLint64 glint64[4];

    GLint max_uniform_buffer_bindings;
    glGetIntegerv (GL_MAX_UNIFORM_BUFFER_BINDINGS,
      &max_uniform_buffer_bindings);
    for (GLint i = 0; i < max_uniform_buffer_bindings; ++i) {
      glGetIntegeri_v (GL_UNIFORM_BUFFER_BINDING, i, glint);
      fprintf (file, "GL_UNIFORM_BUFFER_BINDING       [%3i]:  %i\n", i, *glint);
      glGetInteger64i_v (GL_UNIFORM_BUFFER_START, i, glint64);
      fprintf (file, "GL_UNIFORM_BUFFER_START         [%3i]:  %li\n", i, *glint64);
      glGetInteger64i_v (GL_UNIFORM_BUFFER_SIZE, i, glint64);
      fprintf (file, "GL_UNIFORM_BUFFER_SIZE          [%3i]:  %li\n", i, *glint64);
    }

    // gl 4.2
    if (4 < gl_major_version
      || (4 == gl_major_version && 2 <= gl_major_version))
    {
      GLint max_atomic_counter_buffer_bindings;
      glGetIntegerv (GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS,
        &max_atomic_counter_buffer_bindings);
      for (GLint i = 0; i < max_atomic_counter_buffer_bindings; ++i) {
        glGetIntegeri_v (GL_ATOMIC_COUNTER_BUFFER_BINDING, i, glint);
        fprintf (file, "GL_ATOMIC_COUNTER_BUFFER_BINDING[%2i]:   %i\n", i, *glint);
        glGetInteger64i_v (GL_ATOMIC_COUNTER_BUFFER_START, i, glint64);
        fprintf (file, "GL_ATOMIC_COUNTER_BUFFER_START  [%2i]:   %li\n", i, *glint64);
        glGetInteger64i_v (GL_ATOMIC_COUNTER_BUFFER_SIZE, i, glint64);
        fprintf (file, "GL_ATOMIC_COUNTER_BUFFER_SIZE   [%2i]:   %li\n", i, *glint64);
      }
    }

    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_major_version))
    {
      GLint max_shader_storage_buffer_bindings;
      glGetIntegerv (GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS,
        &max_shader_storage_buffer_bindings);
      for (GLint i = 0; i < max_shader_storage_buffer_bindings; ++i) {
        glGetIntegeri_v (GL_SHADER_STORAGE_BUFFER_BINDING, i, glint);
        fprintf (file, "GL_SHADER_STORAGE_BUFFER_BINDING[%3i]:  %i\n", i, *glint);
        glGetInteger64i_v (GL_SHADER_STORAGE_BUFFER_START, i, glint64);
        fprintf (file, "GL_SHADER_STORAGE_BUFFER_START  [%3i]:  %li\n", i, *glint64);
        glGetInteger64i_v (GL_SHADER_STORAGE_BUFFER_SIZE, i, glint64);
        fprintf (file, "GL_SHADER_STORAGE_BUFFER_SIZE   [%3i]:  %li\n", i, *glint64);
      }
    }
  }
  fprintf (file, "...gl info shader program buffers\n");
}
