#include "../../gl-utils.h"

//
//  gl_info_vertex_specification_constant
//
void gl_info_vertex_specification_constant_print() {
  gl_info_vertex_specification_constant_write (stdout);
}
void gl_info_vertex_specification_constant_write (FILE* file) {
  fprintf (file, "gl info vertex specification constants...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);

    GLint     glint  [4];
    GLint64   glint64[4];
    GLboolean glbool [4];
    glGetIntegerv (GL_MAX_VERTEX_ATTRIB_BINDINGS, glint);
    fprintf (file, "GL_MAX_VERTEX_ATTRIB_BINDINGS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET, glint);
    fprintf (file, "GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET:       %i\n", *glint);
    glGetIntegerv (GL_MAX_VERTEX_ATTRIB_STRIDE, glint);
    fprintf (file, "GL_MAX_VERTEX_ATTRIB_STRIDE:                %i\n", *glint);
    glGetIntegerv (GL_MAX_ELEMENTS_INDICES, glint);
    fprintf (file, "GL_MAX_ELEMENTS_INDICES:                    %i\n", *glint);
    glGetIntegerv (GL_MAX_ELEMENTS_VERTICES, glint);
    fprintf (file, "GL_MAX_ELEMENTS_VERTICES:                   %i\n", *glint);
    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_minor_version))
    {
      glGetInteger64v (GL_MAX_ELEMENT_INDEX, glint64);
      fprintf (file,
        "GL_MAX_ELEMENT_INDEX:                       %li\n", *glint64);
    }
    glGetBooleanv (GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED, glbool);
    fprintf (file, "GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED: %s\n",
      gl_show_boolean (*glbool));
  }
  fprintf (file, "...gl info vertex specification constants\n");
}

//
//  gl_info_vertex_specification_state
//
void gl_info_vertex_specification_state_print() {
  gl_info_vertex_specification_state_write (stdout);
}
void gl_info_vertex_specification_state_write (FILE* file) {
  fprintf (file, "gl info vertex specification state...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);

    GLint     glint [4];
    GLboolean glbool[4];
    glGetIntegerv (GL_VERTEX_ARRAY_BINDING, glint);
    fprintf (file, "GL_VERTEX_ARRAY_BINDING:          %i\n", *glint);
    glGetIntegerv (GL_ARRAY_BUFFER_BINDING, glint);
    fprintf (file, "GL_ARRAY_BUFFER_BINDING:          %i\n", *glint);
    glGetIntegerv (GL_ELEMENT_ARRAY_BUFFER_BINDING, glint);
    fprintf (file, "GL_ELEMENT_ARRAY_BUFFER_BINDING:  %i\n", *glint);
    glGetIntegerv (GL_DRAW_INDIRECT_BUFFER_BINDING, glint);
    fprintf (file, "GL_DRAW_INDIRECT_BUFFER_BINDING:  %i\n", *glint);
    glGetBooleanv (GL_PRIMITIVE_RESTART, glbool);
    fprintf (file, "GL_PRIMITIVE_RESTART:             %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_PRIMITIVE_RESTART_FIXED_INDEX, glbool);
    fprintf (file, "GL_PRIMITIVE_RESTART_FIXED_INDEX: %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_PRIMITIVE_RESTART_INDEX, glint);
    fprintf (file, "GL_PRIMITIVE_RESTART_INDEX:       %i\n", *glint);
    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_minor_version))
    {
      GLint max_vertex_attribs;
      glGetIntegerv (GL_MAX_VERTEX_ATTRIBS, &max_vertex_attribs);
      for (GLint i = 0; i < max_vertex_attribs; ++i) {
        glGetIntegeri_v (GL_VERTEX_BINDING_DIVISOR, i, glint);
        fprintf (file, "GL_VERTEX_BINDING_DIVISOR[%2i]:   %i\n", i, *glint);
        glGetIntegeri_v (GL_VERTEX_BINDING_OFFSET, i, glint);
        fprintf (file, "GL_VERTEX_BINDING_OFFSET [%2i]:   %i\n", i, *glint);
        glGetIntegeri_v (GL_VERTEX_BINDING_STRIDE, i, glint);
        fprintf (file, "GL_VERTEX_BINDING_STRIDE [%2i]:   %i\n", i, *glint);
      }
    }
  }
  fprintf (file, "...gl info vertex specification state\n");
}
