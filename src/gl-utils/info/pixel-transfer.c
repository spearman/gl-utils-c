#include "../../gl-utils.h"

//
//  gl_info_pixel_transfer_constant
//
void gl_info_pixel_transfer_constant_print() {
  gl_info_pixel_transfer_constant_write (stdout);
}
void gl_info_pixel_transfer_constant_write (FILE* file) {
  fprintf (file, "gl info pixel transfer constants...\n");
  if (gl_check_context()) {
    GLint glint[4];
    glGetIntegerv (GL_IMPLEMENTATION_COLOR_READ_FORMAT, glint);
    fprintf (file, "GL_IMPLEMENTATION_COLOR_READ_FORMAT:  %s\n",
      gl_show_pixel_data_format (*glint));
    glGetIntegerv (GL_IMPLEMENTATION_COLOR_READ_TYPE, glint);
    fprintf (file, "GL_IMPLEMENTATION_COLOR_READ_TYPE:    %s\n",
      gl_show_pixel_data_type (*glint));
  }
  fprintf (file, "...gl info pixel transfer constants\n");
}

//
//  gl_info_pixel_transfer_state
//
void gl_info_pixel_transfer_state_print() {
  gl_info_pixel_transfer_state_write (stdout);
}
void gl_info_pixel_transfer_state_write (FILE* file) {
  fprintf (file, "gl info pixel transfer state...\n");
  if (gl_check_context()) {
    GLint     glint [4];
    GLboolean glbool[4];
    glGetIntegerv (GL_PIXEL_PACK_BUFFER_BINDING, glint);
    fprintf (file, "GL_PIXEL_PACK_BUFFER_BINDING:       %i\n", *glint);
    glGetIntegerv (GL_PIXEL_UNPACK_BUFFER_BINDING, glint);
    fprintf (file, "GL_PIXEL_UNPACK_BUFFER_BINDING:     %i\n", *glint);
    glGetIntegerv (GL_PACK_ALIGNMENT, glint);
    fprintf (file, "GL_PACK_ALIGNMENT:                  %i\n", *glint);
    glGetIntegerv (GL_PACK_IMAGE_HEIGHT, glint);
    fprintf (file, "GL_PACK_IMAGE_HEIGHT:               %i\n", *glint);
    glGetIntegerv (GL_PACK_ROW_LENGTH, glint);
    fprintf (file, "GL_PACK_ROW_LENGTH:                 %i\n", *glint);
    glGetIntegerv (GL_PACK_SKIP_IMAGES, glint);
    fprintf (file, "GL_PACK_SKIP_IMAGES:                %i\n", *glint);
    glGetIntegerv (GL_PACK_SKIP_PIXELS, glint);
    fprintf (file, "GL_PACK_SKIP_PIXELS:                %i\n", *glint);
    glGetIntegerv (GL_PACK_SKIP_ROWS, glint);
    fprintf (file, "GL_PACK_SKIP_ROWS:                  %i\n", *glint);
    glGetBooleanv (GL_PACK_SWAP_BYTES, glbool);
    fprintf (file, "GL_PACK_SWAP_BYTES:                 %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_PACK_LSB_FIRST, glbool);
    fprintf (file, "GL_PACK_LSB_FIRST:                  %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_PACK_COMPRESSED_BLOCK_SIZE, glint);
    fprintf (file, "GL_PACK_COMPRESSED_BLOCK_SIZE:      %i\n", *glint);
    glGetIntegerv (GL_PACK_COMPRESSED_BLOCK_WIDTH, glint);
    fprintf (file, "GL_PACK_COMPRESSED_BLOCK_WIDTH:     %i\n", *glint);
    glGetIntegerv (GL_PACK_COMPRESSED_BLOCK_HEIGHT, glint);
    fprintf (file, "GL_PACK_COMPRESSED_BLOCK_HEIGHT:    %i\n", *glint);
    glGetIntegerv (GL_PACK_COMPRESSED_BLOCK_DEPTH, glint);
    fprintf (file, "GL_PACK_COMPRESSED_BLOCK_DEPTH:     %i\n", *glint);
    glGetIntegerv (GL_UNPACK_ALIGNMENT, glint);
    fprintf (file, "GL_UNPACK_ALIGNMENT:                %i\n", *glint);
    glGetIntegerv (GL_UNPACK_IMAGE_HEIGHT, glint);
    fprintf (file, "GL_UNPACK_IMAGE_HEIGHT:             %i\n", *glint);
    glGetIntegerv (GL_UNPACK_ROW_LENGTH, glint);
    fprintf (file, "GL_UNPACK_ROW_LENGTH:               %i\n", *glint);
    glGetIntegerv (GL_UNPACK_SKIP_IMAGES, glint);
    fprintf (file, "GL_UNPACK_SKIP_IMAGES:              %i\n", *glint);
    glGetIntegerv (GL_UNPACK_SKIP_PIXELS, glint);
    fprintf (file, "GL_UNPACK_SKIP_PIXELS:              %i\n", *glint);
    glGetIntegerv (GL_UNPACK_SKIP_ROWS, glint);
    fprintf (file, "GL_UNPACK_SKIP_ROWS:                %i\n", *glint);
    glGetBooleanv (GL_UNPACK_SWAP_BYTES, glbool);
    fprintf (file, "GL_UNPACK_SWAP_BYTES:               %s\n",
      gl_show_boolean (*glbool));
    glGetBooleanv (GL_UNPACK_LSB_FIRST, glbool);
    fprintf (file, "GL_UNPACK_LSB_FIRST:                %s\n",
      gl_show_boolean (*glbool));
    glGetIntegerv (GL_UNPACK_COMPRESSED_BLOCK_SIZE, glint);
    fprintf (file, "GL_UNPACK_COMPRESSED_BLOCK_SIZE:    %i\n", *glint);
    glGetIntegerv (GL_UNPACK_COMPRESSED_BLOCK_WIDTH, glint);
    fprintf (file, "GL_UNPACK_COMPRESSED_BLOCK_WIDTH:   %i\n", *glint);
    glGetIntegerv (GL_UNPACK_COMPRESSED_BLOCK_HEIGHT, glint);
    fprintf (file, "GL_UNPACK_COMPRESSED_BLOCK_HEIGHT:  %i\n", *glint);
    glGetIntegerv (GL_UNPACK_COMPRESSED_BLOCK_DEPTH, glint);
    fprintf (file, "GL_UNPACK_COMPRESSED_BLOCK_DEPTH:   %i\n", *glint);
    glGetIntegerv (GL_CLAMP_READ_COLOR, glint);
    fprintf (file, "GL_CLAMP_READ_COLOR:                %s\n",
      gl_show_clamp_read_color (*glint));
  }
  fprintf (file, "...gl info pixel transfer state\n");
}
