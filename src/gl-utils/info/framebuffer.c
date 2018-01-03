#include "../../gl-utils.h"

//
//  gl_info_framebuffer_constant
//
void gl_info_framebuffer_constant_print() {
  gl_info_framebuffer_constant_write (stdout);
}
void gl_info_framebuffer_constant_write (FILE* file) {
  fprintf (file, "gl info framebuffer constants...\n");
  if (gl_check_context()) {
    // version information
    GLint gl_major_version, gl_minor_version;
    glGetIntegerv (GL_MAJOR_VERSION, &gl_major_version);
    glGetIntegerv (GL_MINOR_VERSION, &gl_minor_version);

    GLint     glint [4];
    GLboolean glbool[4];
    glGetBooleanv (GL_DOUBLEBUFFER, glbool);
    fprintf (file, "GL_DOUBLEBUFFER:            %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_STEREO, glbool);
    fprintf (file, "GL_STEREO:                  %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_MAX_COLOR_ATTACHMENTS, glint);
    fprintf (file, "GL_MAX_COLOR_ATTACHMENTS:   %i\n", *glint);
    // gl 4.3
    if (4 < gl_major_version
      || (4 == gl_major_version && 3 <= gl_major_version))
    {
      glGetIntegerv (GL_MAX_FRAMEBUFFER_WIDTH, glint);
      fprintf (file, "GL_MAX_FRAMEBUFFER_WIDTH:   %i\n", *glint);
      glGetIntegerv (GL_MAX_FRAMEBUFFER_HEIGHT, glint);
      fprintf (file, "GL_MAX_FRAMEBUFFER_HEIGHT:  %i\n", *glint);
      glGetIntegerv (GL_MAX_FRAMEBUFFER_LAYERS, glint);
      fprintf (file, "GL_MAX_FRAMEBUFFER_LAYERS:  %i\n", *glint);
    }
  }
  fprintf (file, "...gl info framebuffer constants\n");
}

//
//  gl_info_framebuffer_state
//
void gl_info_framebuffer_state_print() {
  gl_info_framebuffer_state_write (stdout);
}
void gl_info_framebuffer_state_write (FILE* file) {
  fprintf (file, "gl info framebuffer state...\n");
  if (gl_check_context()) {
    GLint   glint  [4];
    GLfloat glfloat[4];
    glGetIntegerv (GL_READ_FRAMEBUFFER_BINDING, glint);
    fprintf (file, "GL_READ_FRAMEBUFFER_BINDING:    %i\n", *glint);
    glGetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, glint);
    fprintf (file, "GL_DRAW_FRAMEBUFFER_BINDING:    %i\n", *glint);
    glGetFloatv (GL_COLOR_CLEAR_VALUE, glfloat);
    fprintf (file, "GL_COLOR_CLEAR_VALUE:           %f %f %f %f\n",
      glfloat[0], glfloat[1], glfloat[2], glfloat[3]);
    glGetFloatv (GL_DEPTH_CLEAR_VALUE, glfloat);
    fprintf (file, "GL_DEPTH_CLEAR_VALUE (float):   %f\n", *glfloat);
    glGetIntegerv (GL_DEPTH_CLEAR_VALUE, glint);
    fprintf (file, "GL_DEPTH_CLEAR_VALUE (integer): %i\n", *glint);
    glGetIntegerv (GL_RENDERBUFFER_BINDING, glint);
    fprintf (file, "GL_RENDERBUFFER_BINDING:        %i\n", *glint);
    glGetIntegerv (GL_READ_BUFFER, glint);
    fprintf (file, "GL_READ_BUFFER:                 %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER, glint);
    fprintf (file, "GL_DRAW_BUFFER:                 %s\n",
      gl_show_color_buffer (*glint));

    GLint max_draw_buffers;
    glGetIntegerv (GL_MAX_DRAW_BUFFERS, &max_draw_buffers);
    glGetIntegerv (GL_DRAW_BUFFER0, glint);
    fprintf (file, "GL_DRAW_BUFFER0:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER1, glint);
    fprintf (file, "GL_DRAW_BUFFER1:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER2, glint);
    fprintf (file, "GL_DRAW_BUFFER2:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER3, glint);
    fprintf (file, "GL_DRAW_BUFFER3:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER4, glint);
    fprintf (file, "GL_DRAW_BUFFER4:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER5, glint);
    fprintf (file, "GL_DRAW_BUFFER5:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER6, glint);
    fprintf (file, "GL_DRAW_BUFFER6:                %s\n",
      gl_show_color_buffer (*glint));
    glGetIntegerv (GL_DRAW_BUFFER7, glint);
    fprintf (file, "GL_DRAW_BUFFER7:                %s\n",
      gl_show_color_buffer (*glint));
    if (8 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER8, glint);
      fprintf (file, "GL_DRAW_BUFFER8:                %s\n",
        gl_show_color_buffer (*glint));
    }
    if (9 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER9, glint);
      fprintf (file, "GL_DRAW_BUFFER9:                %s\n",
        gl_show_color_buffer (*glint));
    }
    if (10 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER10, glint);
      fprintf (file, "GL_DRAW_BUFFER10:               %s\n",
        gl_show_color_buffer (*glint));
    }
    if (11 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER11, glint);
      fprintf (file, "GL_DRAW_BUFFER11:               %s\n",
        gl_show_color_buffer (*glint));
    }
    if (12 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER12, glint);
      fprintf (file, "GL_DRAW_BUFFER12:               %s\n",
        gl_show_color_buffer (*glint));
    }
    if (13 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER13, glint);
      fprintf (file, "GL_DRAW_BUFFER13:               %s\n",
        gl_show_color_buffer (*glint));
    }
    if (14 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER14, glint);
      fprintf (file, "GL_DRAW_BUFFER14:               %s\n",
        gl_show_color_buffer (*glint));
    }
    if (15 < max_draw_buffers) {
      glGetIntegerv (GL_DRAW_BUFFER15, glint);
      fprintf (file, "GL_DRAW_BUFFER15:               %s\n",
        gl_show_color_buffer (*glint));
    }
  }
  fprintf (file, "...gl info framebuffer state\n");
}
