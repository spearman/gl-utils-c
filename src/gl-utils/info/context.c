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
    fprintf (file, "GL_VENDOR:                          %s\n",
      glGetString (GL_VENDOR));
    fprintf (file, "GL_RENDERER:                        %s\n",
      glGetString (GL_RENDERER));
    fprintf (file, "GL_SHADING_LANGUAGE_VERSION:        %s\n",
      glGetString (GL_SHADING_LANGUAGE_VERSION));
    glGetIntegerv (GL_MAJOR_VERSION, glint);
    fprintf (file, "GL_MAJOR_VERSION:                   %i\n", *glint);
    glGetIntegerv (GL_MINOR_VERSION, glint);
    fprintf (file, "GL_MINOR_VERSION:                   %i\n", *glint);
    glGetIntegerv (GL_NUM_SHADING_LANGUAGE_VERSIONS, glint);
    fprintf (file, "GL_NUM_SHADING_LANGUAGE_VERSIONS:   %i\n", *glint);
    glGetIntegerv (GL_NUM_EXTENSIONS, glint);
    fprintf (file, "GL_NUM_EXTENSIONS:                  %i\n", *glint);
    glGetIntegerv (GL_NUM_COMPRESSED_TEXTURE_FORMATS, glint);
    fprintf (file, "GL_NUM_COMPRESSED_TEXTURE_FORMATS:  %i\n", *glint);
    glGetIntegerv (GL_CONTEXT_PROFILE_MASK, glint);
    fprintf (file, "GL_CONTEXT_PROFILE_MASK:            %x\n", *glint);
    glGetIntegerv (GL_CONTEXT_FLAGS, glint);
    fprintf (file, "GL_CONTEXT_FLAGS:                   %x\n", *glint);
    glGetIntegerv (GL_MIN_MAP_BUFFER_ALIGNMENT, glint);
    fprintf (file, "GL_MIN_MAP_BUFFER_ALIGNMENT:        %i\n", *glint);
    glGetInteger64v (GL_TIMESTAMP, glint64);
    fprintf (file, "GL_TIMESTAMP:                       %li\n", *glint64);
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