#include "../../../gl-utils.h"

//
//  gl_info_vertex_postprocessing_constant
//
void gl_info_vertex_postprocessing_constant_print() {
  gl_info_vertex_postprocessing_constant_write (stdout);
}
void gl_info_vertex_postprocessing_constant_write (FILE* file) {
  fprintf (file, "gl info vertex postprocessing constants...\n");
  if (gl_check_context()) {
    GLint glint[4];

    fprintf (file, "  ...transform feedback...\n");
    glGetIntegerv (GL_MAX_TRANSFORM_FEEDBACK_BUFFERS, glint);
    fprintf (file, "GL_MAX_TRANSFORM_FEEDBACK_BUFFERS:                %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS: %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS, glint);
    fprintf (file, "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS:       %i\n",
      *glint);
    glGetIntegerv (GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS, glint);
    fprintf (file, "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS:    %i\n",
      *glint);

    fprintf (file, "  ...clipping...\n");
    glGetIntegerv (GL_MAX_CLIP_DISTANCES, glint);
    fprintf (file, "GL_MAX_CLIP_DISTANCES:                            %i\n",
      *glint);

    fprintf (file, "  ...perspective divide...\n");

    fprintf (file, "  ...viewport transform...\n");
    glGetIntegerv (GL_MAX_VIEWPORTS, glint);
    fprintf (file, "GL_MAX_VIEWPORTS:                                 %i\n",
      *glint);
    glGetIntegerv (GL_MAX_VIEWPORT_DIMS, glint);
    fprintf (file, "GL_MAX_VIEWPORT_DIMS:                             %i %i\n",
      glint[0], glint[1]);
    glGetIntegerv (GL_VIEWPORT_BOUNDS_RANGE, glint);
    fprintf (file, "GL_VIEWPORT_BOUNDS_RANGE:                         %i %i\n",
      glint[0], glint[1]);
    glGetIntegerv (GL_VIEWPORT_SUBPIXEL_BITS, glint);
    fprintf (file, "GL_VIEWPORT_SUBPIXEL_BITS:                        %i\n",
      *glint);
  }
  fprintf (file, "...gl info vertex postprocessing constants\n");
}

//
//  gl_info_vertex_postprocessing_state
//
void gl_info_vertex_postprocessing_state_print() {
  gl_info_vertex_postprocessing_state_write (stdout);
}
void gl_info_vertex_postprocessing_state_write (FILE* file) {
  fprintf (file, "gl info vertex postprocessing state...\n");
  if (gl_check_context()) {
    GLint     glint  [4];
    GLint64   glint64[4];
    GLboolean glbool [4];
    GLfloat   glfloat[4];

    fprintf (file, "  ...transform feedback...\n");
    glGetIntegerv (GL_TRANSFORM_FEEDBACK_BINDING, glint);
    fprintf (file, "GL_TRANSFORM_FEEDBACK_BINDING:            %i\n",
      *glint);
    glGetBooleanv (GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE, glbool);
    fprintf (file, "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE:      %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED, glbool);
    fprintf (file, "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED:      %s\n",
      gl_show_boolean (*glbool));
    GLint max_transform_feedback_buffer_bindings;
    glGetIntegerv (GL_MAX_TRANSFORM_FEEDBACK_BUFFERS,
      &max_transform_feedback_buffer_bindings);
    for (GLint i = 0; i < max_transform_feedback_buffer_bindings; ++i) {
      glGetIntegeri_v (GL_TRANSFORM_FEEDBACK_BUFFER_BINDING, i, glint);
      fprintf (file, "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING[%2i]: %i\n",
        i, *glint);
      glGetInteger64i_v (GL_TRANSFORM_FEEDBACK_BUFFER_START, i, glint64);
      fprintf (file, "GL_TRANSFORM_FEEDBACK_BUFFER_START  [%2i]: %li\n",
        i, *glint64);
      glGetInteger64i_v (GL_TRANSFORM_FEEDBACK_BUFFER_SIZE, i, glint64);
      fprintf (file, "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE   [%2i]: %li\n",
        i, *glint64);
    }

    fprintf (file, "  ...clipping...\n");
    glGetBooleanv (GL_DEPTH_CLAMP, glbool);
    fprintf (file, "GL_DEPTH_CLAMP:                           %s\n",
      gl_show_boolean (*glbool));
    glGetFloatv (GL_DEPTH_RANGE, glfloat );
    fprintf (file, "GL_DEPTH_RANGE (float):                   %f - %f\n",
      glfloat[0], glfloat[1]);
    glGetIntegerv (GL_DEPTH_RANGE, glint);
    fprintf (file, "GL_DEPTH_RANGE (integer):                 %i - %i\n",
      glint[0], glint[1]);
    glGetBooleanv (GL_CLIP_DISTANCE0, glbool);
    fprintf (file, "GL_CLIP_DISTANCE0:                        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_CLIP_DISTANCE1, glbool);
    fprintf (file, "GL_CLIP_DISTANCE1:                        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_CLIP_DISTANCE2, glbool);
    fprintf (file, "GL_CLIP_DISTANCE2:                        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_CLIP_DISTANCE3, glbool);
    fprintf (file, "GL_CLIP_DISTANCE3:                        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_CLIP_DISTANCE4, glbool);
    fprintf (file, "GL_CLIP_DISTANCE4:                        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_CLIP_DISTANCE5, glbool);
    fprintf (file, "GL_CLIP_DISTANCE5:                        %s\n",
      gl_show_boolean (*glbool));
    /*
    glGetBooleanv (GL_CLIP_DISTANCE6, glbool);
    fprintf (file, "GL_CLIP_DISTANCE6:                        %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_CLIP_DISTANCE7, glbool);
    fprintf (file, "GL_CLIP_DISTANCE7:                        %s\n",
      gl_show_boolean (*glbool));
    */

    fprintf (file, "  ...perspective divide...\n");

    fprintf (file, "  ...viewport transform...\n");
    glGetIntegerv (GL_VIEWPORT, glint);
    fprintf (file, "GL_VIEWPORT:                              %i %i %i %i\n",
      glint[0], glint[1], glint[2], glint[3]);
  }
  fprintf (file, "...gl info vertex postprocessing state\n");
}
