#include "../../../gl-utils.h"

//
//  gl_info_persample_processing_constant
//
void gl_info_persample_processing_constant_print() {
  gl_info_persample_processing_constant_write (stdout);
}
void gl_info_persample_processing_constant_write (FILE* file) {
  fprintf (file, "gl info persample processing constants...\n");
  if (gl_check_context()) {
    GLint   glint[4];
    fprintf (file, "  ...stencil test...\n");
    fprintf (file, "  ...depth test...\n");
    fprintf (file, "  ...blending...\n");
    glGetIntegerv (GL_MAX_DUAL_SOURCE_DRAW_BUFFERS, glint);
    fprintf (file, "GL_MAX_DUAL_SOURCE_DRAW_BUFFERS:  %i\n", *glint);
    fprintf (file, "  ...logical operations...\n");
    fprintf (file, "  ...write mask...\n");
  }
  fprintf (file, "...gl info persample processing constants\n");
}

//
//  gl_info_persample_processing_state
//
void gl_info_persample_processing_state_print() {
  gl_info_persample_processing_state_write (stdout);
}
void gl_info_persample_processing_state_write (FILE* file) {
  fprintf (file, "gl info persample processing state...\n");
  if (gl_check_context()) {
    GLint     glint  [4];
    GLboolean glbool [4];
    GLfloat   glfloat[4];
    fprintf (file, "  ...stencil test...\n");
    glGetBooleanv (GL_STENCIL_TEST, glbool);
    fprintf (file, "GL_STENCIL_TEST:                  %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_STENCIL_CLEAR_VALUE, glint);
    fprintf (file, "GL_STENCIL_CLEAR_VALUE:           %x\n", *glint);
    glGetIntegerv (GL_STENCIL_REF, glint);
    fprintf (file, "GL_STENCIL_REF:                   %x\n", *glint);
    glGetIntegerv (GL_STENCIL_VALUE_MASK, glint);
    fprintf (file, "GL_STENCIL_VALUE_MASK:            %x\n", *glint);
    glGetIntegerv (GL_STENCIL_FAIL, glint);
    fprintf (file, "GL_STENCIL_FAIL:                  %s\n",
      gl_show_stencil_op (*glint));
    glGetIntegerv (GL_STENCIL_FUNC, glint);
    fprintf (file, "GL_STENCIL_FUNC:                  %s\n",
      gl_show_depth_func (*glint));
    glGetIntegerv (GL_STENCIL_PASS_DEPTH_FAIL, glint);
    fprintf (file, "GL_STENCIL_PASS_DEPTH_FAIL:       %s\n",
      gl_show_stencil_op (*glint));
    glGetIntegerv (GL_STENCIL_PASS_DEPTH_PASS, glint);
    fprintf (file, "GL_STENCIL_PASS_DEPTH_PASS:       %s\n",
      gl_show_stencil_op (*glint));
    glGetIntegerv (GL_STENCIL_BACK_FAIL, glint);
    fprintf (file, "GL_STENCIL_BACK_FAIL:             %s\n",
      gl_show_stencil_op (*glint));
    glGetIntegerv (GL_STENCIL_BACK_FUNC, glint);
    fprintf (file, "GL_STENCIL_BACK_FUNC:             %s\n",
      gl_show_depth_func (*glint));
    glGetIntegerv (GL_STENCIL_BACK_PASS_DEPTH_FAIL, glint);
    fprintf (file, "GL_STENCIL_BACK_PASS_DEPTH_FAIL:  %s\n",
      gl_show_stencil_op (*glint));
    glGetIntegerv (GL_STENCIL_BACK_PASS_DEPTH_PASS, glint);
    fprintf (file, "GL_STENCIL_BACK_PASS_DEPTH_PASS:  %s\n",
      gl_show_stencil_op (*glint));
    glGetIntegerv (GL_STENCIL_BACK_REF, glint);
    fprintf (file, "GL_STENCIL_BACK_REF:              %i\n", *glint);
    glGetIntegerv (GL_STENCIL_BACK_VALUE_MASK, glint);
    fprintf (file, "GL_STENCIL_BACK_VALUE_MASK:       %x\n", *glint);

    fprintf (file, "  ...depth test...\n");
    *glbool = glIsEnabled (GL_DEPTH_TEST);
    fprintf (file, "glIsEnabled (GL_DEPTH_TEST):      %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_DEPTH_FUNC, glint);
    fprintf (file, "GL_DEPTH_FUNC:                    %s\n",
      gl_show_depth_func (*glint));
    glGetBooleanv (GL_POLYGON_OFFSET_POINT, glbool);
    fprintf (file, "GL_POLYGON_OFFSET_POINT:          %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_POLYGON_OFFSET_LINE, glbool);
    fprintf (file, "GL_POLYGON_OFFSET_LINE:           %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_POLYGON_OFFSET_FILL, glbool);
    fprintf (file, "GL_POLYGON_OFFSET_FILL:           %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_POLYGON_OFFSET_FACTOR, glint);
    fprintf (file, "GL_POLYGON_OFFSET_FACTOR:         %i\n", *glint);
    glGetIntegerv (GL_POLYGON_OFFSET_UNITS, glint);
    fprintf (file, "GL_POLYGON_OFFSET_UNITS:          %i\n", *glint);

    fprintf (file, "  ...blending...\n");
    *glbool = glIsEnabled(GL_BLEND );
    fprintf (file, "glIsEnabled (GL_BLEND):           %s\n",
      gl_show_boolean (*glbool));
    glGetFloatv (GL_BLEND_COLOR, glfloat);
    fprintf (file, "GL_BLEND_COLOR:                   %f %f %f %f\n",
        glfloat[0], glfloat[1], glfloat[2], glfloat[3]);
    glGetIntegerv (GL_BLEND, glint);
    fprintf (file, "GL_BLEND:                         %s\n",
      gl_show_blend_func (*glint));
    glGetIntegerv (GL_BLEND_DST_RGB, glint);
    fprintf (file, "GL_BLEND_DST_RGB:                 %s\n",
      gl_show_blend_func (*glint));
    glGetIntegerv (GL_BLEND_DST_ALPHA, glint);
    fprintf (file, "GL_BLEND_DST_ALPHA:               %s\n",
      gl_show_blend_func (*glint));
    glGetIntegerv (GL_BLEND_EQUATION_RGB, glint);
    fprintf (file, "GL_BLEND_EQUATION_RGB:            %s\n",
      gl_show_blend_eq (*glint));
    glGetIntegerv (GL_BLEND_EQUATION_ALPHA, glint);
    fprintf (file, "GL_BLEND_EQUATION_ALPHA:          %s\n",
      gl_show_blend_eq (*glint));
    glGetIntegerv (GL_BLEND_SRC_RGB, glint);
    fprintf (file, "GL_BLEND_SRC_RGB:                 %s\n",
      gl_show_blend_func (*glint));
    glGetIntegerv (GL_BLEND_SRC_ALPHA, glint);
    fprintf (file, "GL_BLEND_SRC_ALPHA:               %s\n",
      gl_show_blend_func (*glint));
    glGetBooleanv (GL_DITHER, glbool);
    fprintf (file, "GL_DITHER:                        %s\n",
      gl_show_boolean (*glbool));

    fprintf (file, "  ...logical operations...\n");
    *glbool = glIsEnabled (GL_COLOR_LOGIC_OP);
    fprintf (file, "glIsEnabled (GL_COLOR_LOGIC_OP):  %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_LOGIC_OP_MODE, glint);
    fprintf (file, "GL_LOGIC_OP_MODE:                 %s\n",
      gl_show_logic_op (*glint));

    fprintf (file, "  ...write mask...\n");
    glGetBooleanv (GL_COLOR_WRITEMASK, glbool);
    fprintf (file, "GL_COLOR_WRITEMASK:               %s %s %s %s\n",
        gl_show_boolean (glbool[0]), gl_show_boolean (glbool[1]),
        gl_show_boolean (glbool[2]), gl_show_boolean (glbool[3]));
    glGetIntegerv (GL_STENCIL_WRITEMASK, glint);
    fprintf (file, "GL_STENCIL_WRITEMASK:             %x\n", *glint);
    glGetIntegerv (GL_STENCIL_BACK_WRITEMASK, glint);
    fprintf (file, "GL_STENCIL_BACK_WRITEMASK:        %x\n", *glint);
    glGetBooleanv (GL_DEPTH_WRITEMASK, glbool);
    fprintf (file, "GL_DEPTH_WRITEMASK:               %s\n",
      gl_show_boolean (*glbool));
  }
  fprintf (file, "...gl info persample processing state\n");
}
