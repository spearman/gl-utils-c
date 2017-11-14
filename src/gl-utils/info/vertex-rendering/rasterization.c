#include "../../../gl-utils.h"

//
//  gl_info_rasterization_constant
//
void gl_info_rasterization_constant_print() {
  gl_info_rasterization_constant_write (stdout);
}
void gl_info_rasterization_constant_write (FILE* file) {
  fprintf (file, "gl info rasterization constants...\n");
  if (gl_check_context()) {
    GLint   glint[4];
    GLfloat glfloat[4];

    fprintf (file, "  ...rasterizer discard...\n");

    fprintf (file, "  ...scan conversion...\n");
    glGetIntegerv (GL_SUBPIXEL_BITS, glint);
    fprintf (file, "GL_SUBPIXEL_BITS:                   %i\n", *glint);
    glGetFloatv (GL_POINT_SIZE_GRANULARITY, glfloat);
    fprintf (file, "GL_POINT_SIZE_GRANULARITY:          %f\n", *glfloat);
    glGetFloatv (GL_POINT_SIZE_RANGE, glfloat);
    fprintf (file, "GL_POINT_SIZE_RANGE:                %f - %f\n",
      glfloat[0], glfloat[1]);
    glGetFloatv (GL_LINE_WIDTH_GRANULARITY, glfloat);
    fprintf (file, "GL_LINE_WIDTH_GRANULARITY:          %f\n", *glfloat);
    glGetFloatv (GL_ALIASED_LINE_WIDTH_RANGE, glfloat);
    fprintf (file, "GL_ALIASED_LINE_WIDTH_RANGE:        %f - %f\n",
      glfloat[0], glfloat[1]);
    glGetFloatv (GL_SMOOTH_LINE_WIDTH_GRANULARITY, glfloat);
    fprintf (file, "GL_SMOOTH_LINE_WIDTH_GRANULARITY:   %f\n", *glfloat);
    glGetFloatv (GL_SMOOTH_LINE_WIDTH_RANGE, glfloat);
    fprintf (file, "GL_SMOOTH_LINE_WIDTH_RANGE:         %f - %f\n",
      glfloat[0], glfloat[1]);

    fprintf (file, "  ...multisampling...\n");
    glGetIntegerv (GL_MAX_FRAMEBUFFER_SAMPLES, glint);
    fprintf (file, "GL_MAX_FRAMEBUFFER_SAMPLES:         %i\n", *glint);
    glGetIntegerv (GL_MAX_INTEGER_SAMPLES, glint);
    fprintf (file, "GL_MAX_INTEGER_SAMPLES:             %i\n", *glint);
    glGetIntegerv (GL_MAX_SAMPLES, glint);
    fprintf (file, "GL_MAX_SAMPLES:                     %i\n", *glint);
    glGetIntegerv (GL_MAX_COLOR_TEXTURE_SAMPLES, glint);
    fprintf (file, "GL_MAX_COLOR_TEXTURE_SAMPLES:       %i\n", *glint);
    glGetIntegerv (GL_MAX_DEPTH_TEXTURE_SAMPLES, glint);
    fprintf (file, "GL_MAX_DEPTH_TEXTURE_SAMPLES:       %i\n", *glint);
    glGetIntegerv (GL_MAX_SAMPLE_MASK_WORDS, glint);
    fprintf (file, "GL_MAX_SAMPLE_MASK_WORDS:           %i\n", *glint);

    fprintf (file, "  ...primitive parameter interpolation...\n");
    glGetIntegerv (GL_MAX_VARYING_FLOATS, glint);
    fprintf (file, "GL_MAX_VARYING_FLOATS:              %i\n", *glint);
    glGetIntegerv (GL_MAX_VARYING_COMPONENTS, glint);
    fprintf (file, "GL_MAX_VARYING_COMPONENTS:          %i\n", *glint);
    glGetIntegerv (GL_MAX_VARYING_VECTORS, glint);
    fprintf (file, "GL_MAX_VARYING_VECTORS:             %i\n", *glint);
    glGetIntegerv (GL_VIEWPORT_INDEX_PROVOKING_VERTEX, glint);
    fprintf (file, "GL_VIEWPORT_INDEX_PROVOKING_VERTEX: %s\n",
      gl_show_provoke_convention (*glint));
    glGetIntegerv (GL_LAYER_PROVOKING_VERTEX, glint);
    fprintf (file, "GL_LAYER_PROVOKING_VERTEX:          %s\n",
      gl_show_provoke_convention (*glint));
  }
  fprintf (file, "...gl info rasterization constants\n");
}

//
//  gl_info_rasterization_state
//
void gl_info_rasterization_state_print() {
  gl_info_rasterization_state_write (stdout);
}
void gl_info_rasterization_state_write (FILE* file) {
  fprintf (file, "gl info rasterization state...\n");

  if (gl_check_context()) {
    GLint     glint  [4];
    GLboolean glbool [4];
    GLfloat   glfloat[4];
    fprintf (file, "  ...rasterizer discard...\n");
    glGetBooleanv (GL_RASTERIZER_DISCARD, glbool);
    fprintf (file, "GL_RASTERIZER_DISCARD:                      %s\n",
      gl_show_boolean (*glbool));

    fprintf (file, "  ...scan conversion...\n");
    glGetFloatv (GL_POINT_SIZE, glfloat );
    fprintf (file, "GL_POINT_SIZE:                              %f\n", *glfloat);
    glGetIntegerv (GL_POINT_FADE_THRESHOLD_SIZE, glint);
    fprintf (file, "GL_POINT_FADE_THRESHOLD_SIZE:               %i\n", *glint);
    glGetIntegerv (GL_POINT_SPRITE_COORD_ORIGIN, glint);
    fprintf (file, "GL_POINT_SPRITE_COORD_ORIGIN:               %s\n",
      gl_show_point_sprite_origin (*glint));
    glGetIntegerv (GL_LINE_WIDTH, glint);
    fprintf (file, "GL_LINE_WIDTH:                              %i\n", *glint);
    glGetIntegerv (GL_POLYGON_MODE, glint);
    fprintf (file, "GL_POLYGON_MODE:                            %s %s\n",
      gl_show_polygon_mode (glint[0]), gl_show_polygon_mode (glint[1]));
    *glbool = glIsEnabled (GL_LINE_SMOOTH);
    fprintf (file, "glIsEnabled (GL_LINE_SMOOTH):               %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_LINE_SMOOTH_HINT, glint);
    fprintf (file, "GL_LINE_SMOOTH_HINT:                        %s\n",
      gl_show_hint (*glint));
    glGetBooleanv (GL_POLYGON_SMOOTH, glbool);
    fprintf (file, "GL_POLYGON_SMOOTH:                          %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_POLYGON_SMOOTH_HINT, glint);
    fprintf (file, "GL_POLYGON_SMOOTH_HINT:                     %s\n",
      gl_show_hint (*glint));

    fprintf (file, "  ...multisampling...\n");
    *glbool = glIsEnabled (GL_MULTISAMPLE);
    fprintf (file, "glIsEnabled (GL_MULTISAMPLE):               %s\n",
      gl_show_boolean (*glbool));
    *glbool = glIsEnabled (GL_SAMPLE_COVERAGE);
    fprintf (file, "glIsEnabled (GL_SAMPLE_COVERAGE):           %s\n",
      gl_show_boolean (*glbool));
    *glbool = glIsEnabled (GL_SAMPLE_ALPHA_TO_COVERAGE);
    fprintf (file, "glIsEnabled (GL_SAMPLE_ALPHA_TO_COVERAGE):  %s\n",
      gl_show_boolean (*glbool));
    *glbool = glIsEnabled (GL_SAMPLE_ALPHA_TO_ONE);
    fprintf (file, "glIsEnabled (GL_SAMPLE_ALPHA_TO_ONE):       %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_SAMPLE_BUFFERS, glint);
    fprintf (file, "GL_SAMPLE_BUFFERS:                          %i\n", *glint);
    glGetIntegerv (GL_SAMPLES, glint);
    fprintf (file, "GL_SAMPLES:                                 %i\n", *glint);
    GLint max_sample_mask_words;
    glGetIntegerv (GL_MAX_SAMPLE_MASK_WORDS, &max_sample_mask_words);
    fprintf (file, "GL_SAMPLE_MASK_VALUE:                      ");
    for (GLint i = 0; i < max_sample_mask_words; ++i) {
      glGetIntegeri_v (GL_SAMPLE_MASK_VALUE, i, glint);
      fprintf (file, " %x", *glint);
    }
    fprintf (file, "\n");
    glGetFloatv (GL_SAMPLE_COVERAGE_VALUE, glfloat );
    fprintf (file, "GL_SAMPLE_COVERAGE_VALUE:                   %f\n", *glfloat);
    glGetBooleanv (GL_SAMPLE_COVERAGE_INVERT, glbool);
    fprintf (file, "GL_SAMPLE_COVERAGE_INVERT:                  %s\n",
      gl_show_boolean (*glbool));

    fprintf (file, "  ...primitive parameter interpolation...\n");
    glGetIntegerv (GL_PROVOKING_VERTEX, glint);
    fprintf (file, "GL_PROVOKING_VERTEX:                        %s\n",
      gl_show_provoke_convention (*glint));
  }
  fprintf (file, "...gl info rasterization state\n");
}
