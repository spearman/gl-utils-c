#include "../../gl-utils.h"

//
//  gl_info_context_constant
//
void gl_info_context_constant_print() {
  gl_info_context_constant_write (stdout);
}
void gl_info_context_constant_write (FILE* file) {
  fprintf (file, "gl info context constants...\n");
  if (gl_check_context()) {
    //GLboolean glbool  [4];
    GLint     glint   [4];
    GLint64   glint64 [4];

    fprintf (file, "GL_VERSION:                         %s\n",
      glGetString (GL_VERSION));
    gl_check_error();

    fprintf (file, "GL_VENDOR:                          %s\n",
      glGetString (GL_VENDOR));
    gl_check_error();

    fprintf (file, "GL_RENDERER:                        %s\n",
      glGetString (GL_RENDERER));
    gl_check_error();

    fprintf (file, "GL_SHADING_LANGUAGE_VERSION:        %s\n",
      glGetString (GL_SHADING_LANGUAGE_VERSION));
    gl_check_error();

    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    fprintf (file, "GL_MAJOR_VERSION:                   %i\n", gl_major_version);
    gl_check_error();

    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);
    fprintf (file, "GL_MINOR_VERSION:                   %i\n", gl_minor_version);
    gl_check_error();

    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_minor_version))
    {
      glGetIntegerv (GL_NUM_SHADING_LANGUAGE_VERSIONS, glint);
      fprintf (file, "GL_NUM_SHADING_LANGUAGE_VERSIONS:   %i\n", *glint);
      gl_check_error();
    }

    glGetIntegerv (GL_NUM_EXTENSIONS, glint);
    fprintf (file, "GL_NUM_EXTENSIONS:                  %i\n", *glint);
    gl_check_error();

    glGetIntegerv (GL_NUM_COMPRESSED_TEXTURE_FORMATS, glint);
    fprintf (file, "GL_NUM_COMPRESSED_TEXTURE_FORMATS:  %i\n", *glint);
    gl_check_error();

    glGetIntegerv (GL_CONTEXT_PROFILE_MASK, glint);
    fprintf (file, "GL_CONTEXT_PROFILE_MASK:            %x\n", *glint);
    gl_check_error();

    glGetIntegerv (GL_CONTEXT_FLAGS, glint);
    fprintf (file, "GL_CONTEXT_FLAGS:                   %x\n", *glint);
    gl_check_error();

    glGetIntegerv (GL_MIN_MAP_BUFFER_ALIGNMENT, glint);
    fprintf (file, "GL_MIN_MAP_BUFFER_ALIGNMENT:        %i\n", *glint);
    gl_check_error();

    glGetInteger64v (GL_TIMESTAMP, glint64);
    fprintf (file, "GL_TIMESTAMP:                       %li\n", *glint64);
    gl_check_error();

    // extension GL_NVX_gpu_memory_info
    if (gl_extension_is_supported ("GL_NVX_gpu_memory_info")) {
      glGetIntegerv (GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX, glint);
      fprintf (file, "GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX:       %iKB\n",
        *glint);
      glGetIntegerv (GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX, glint);
      fprintf (file, "GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX: %iKB\n",
        *glint);
    }
  }
  fprintf (file, "...gl info context constants\n");
}

//
//  gl_info_context_state
//
void gl_info_context_state_print() {
  gl_info_context_state_write (stdout);
}
void gl_info_context_state_write (FILE* file) {
  fprintf (file, "gl info context state...\n");
  if (gl_check_context()) {
    //GLboolean glbool  [4];
    GLint     glint   [4];
    glGetIntegerv (GL_COPY_READ_BUFFER, glint);
    fprintf (file, "GL_COPY_READ_BUFFER:    %i\n", *glint);
    glGetIntegerv (GL_COPY_WRITE_BUFFER, glint);
    fprintf (file, "GL_COPY_WRITE_BUFFER:   %i\n", *glint);
    // extension GL_NVX_gpu_memory_info
    if (gl_extension_is_supported ("GL_NVX_gpu_memory_info")) {
      glGetIntegerv (GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX, glint);
      fprintf (file, "GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX: %iKB\n",
        *glint);
      glGetIntegerv (GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX, glint);
      fprintf (file, "GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX:           %i\n",
        *glint);
      glGetIntegerv (GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX, glint);
      fprintf (file, "GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX:           %iKB\n",
        *glint);
    }
    // extension GL_ATI_meminfo
    if (gl_extension_is_supported ("GL_ATI_meminfo")) {
      glGetIntegerv (GL_VBO_FREE_MEMORY_ATI, glint);
      fprintf (file,
        "GL_VBO_FREE_MEMORY_ATI (total free):                                 %iKB\n",
        glint[0]);
      fprintf (file,
        "GL_VBO_FREE_MEMORY_ATI (largest available block):                    %iKB\n",
        glint[1]);
      fprintf (file,
        "GL_VBO_FREE_MEMORY_ATI (total auxiliary):                            %iKB\n",
        glint[2]);
      fprintf (file,
        "GL_VBO_FREE_MEMORY_ATI (largest available auxiliary block):          %iKB\n",
        glint[3]);
      glGetIntegerv (GL_TEXTURE_FREE_MEMORY_ATI, glint);
      fprintf (file,
        "GL_TEXTURE_FREE_MEMORY_ATI (total free):                             %iKB\n",
        glint[0]);
      fprintf (file,
        "GL_TEXTURE_FREE_MEMORY_ATI (largest available block):                %iKB\n",
        glint[1]);
      fprintf (file,
        "GL_TEXTURE_FREE_MEMORY_ATI (total auxiliary):                        %iKB\n",
        glint[2]);
      fprintf (file,
        "GL_TEXTURE_FREE_MEMORY_ATI (largest available auxiliary block):      %iKB\n",
        glint[3]);
      glGetIntegerv (GL_RENDERBUFFER_FREE_MEMORY_ATI, glint);
      fprintf (file,
        "GL_RENDERBUFFER_FREE_MEMORY_ATI (total free):                        %iKB\n",
        glint[0]);
      fprintf (file,
        "GL_RENDERBUFFER_FREE_MEMORY_ATI (largest available block):           %iKB\n",
        glint[1]);
      fprintf (file,
        "GL_RENDERBUFFER_FREE_MEMORY_ATI (total auxiliary):                   %iKB\n",
        glint[2]);
      fprintf (file,
        "GL_RENDERBUFFER_FREE_MEMORY_ATI (largest available auxiliary block): %iKB\n",
        glint[3]);
    }
  }
  fprintf (file, "...gl info context state\n");
}

//
//  gl_info_context_glsl_versions
//
void gl_info_context_glsl_versions_print() {
  gl_info_context_glsl_versions_write (stdout);
}
void gl_info_context_glsl_versions_write (FILE* file) {
  fprintf (file, "gl info context glsl versions...\n");
  if (gl_check_context()) {
    GLint n;
    glGetIntegerv (GL_NUM_SHADING_LANGUAGE_VERSIONS, &n);
    fprintf (file, "GL_SHADING_LANGUAGE_VERSION:\n");
    for (GLint i = 0; i < n; ++i) {
      const GLubyte* glsl_version = glGetStringi (GL_SHADING_LANGUAGE_VERSION, i);
      fprintf (file, "  [%2i]: %s\n", i, glsl_version);
    }
  }
  fprintf (file, "...gl info context glsl versions\n");
}

//
//  gl_info_context_extensions
//
void gl_info_context_extensions_print() {
  gl_info_context_extensions_write (stdout);
}
void gl_info_context_extensions_write (FILE* file) {
  fprintf (file, "gl info context extensions...\n");
  if (gl_check_context()) {
    GLint n;
    glGetIntegerv (GL_NUM_EXTENSIONS, &n);
    fprintf (file, "GL_EXTENSIONS:\n");
    for (GLint i = 0; i < n; ++i) {
      const GLubyte* extension = glGetStringi (GL_EXTENSIONS, i);
      fprintf (file, "  [%3i]: %s\n", i, extension);
    }
  }
  fprintf (file, "...gl info context extensions\n");
}

//
//  gl_info_context_compressed_tex_fmts
//
void gl_info_context_compressed_tex_fmts_print() {
  gl_info_context_compressed_tex_fmts_write (stdout);
}
void gl_info_context_compressed_tex_fmts_write (FILE* file) {
  fprintf (file, "gl info context compressed texture formats...\n");
  if (gl_check_context()) {
    GLint num_compressed_tex_fmts;
    glGetIntegerv (GL_NUM_COMPRESSED_TEXTURE_FORMATS, &num_compressed_tex_fmts);
    GLint compressed_tex_fmts[num_compressed_tex_fmts];
    glGetIntegerv (GL_COMPRESSED_TEXTURE_FORMATS, compressed_tex_fmts);
    fprintf (file, "GL_COMPRESSED_TEXTURE_FORMATS:\n");
    for (GLint i = 0; i < num_compressed_tex_fmts; ++i) {
      fprintf (file, "  [%2i]: %s\n",
        i, gl_show_image_format (compressed_tex_fmts[i]));
    }
  }
  fprintf (file, "...gl info context compressed texture formats\n");
}
