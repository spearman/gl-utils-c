#include "../gl-utils.h"

#define DEF_OUT_STR(_x_) case (_x_): out = #_x_; break;

//
//  gl_show_blend_eq
//
const char* gl_show_blend_eq (const GLenum blend_eq) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (blend_eq) {
      DEF_OUT_STR (GL_FUNC_ADD)
      DEF_OUT_STR (GL_FUNC_SUBTRACT)
      DEF_OUT_STR (GL_FUNC_REVERSE_SUBTRACT)
      DEF_OUT_STR (GL_MIN)
      DEF_OUT_STR (GL_MAX)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_blend_func
//
const char* gl_show_blend_func (const GLenum blend_func) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (blend_func) {
      DEF_OUT_STR (GL_ZERO)
      DEF_OUT_STR (GL_ONE)
      DEF_OUT_STR (GL_SRC_COLOR)
      DEF_OUT_STR (GL_ONE_MINUS_SRC_COLOR)
      DEF_OUT_STR (GL_DST_COLOR)
      DEF_OUT_STR (GL_ONE_MINUS_DST_COLOR)
      DEF_OUT_STR (GL_SRC_ALPHA)
      DEF_OUT_STR (GL_ONE_MINUS_SRC_ALPHA)
      DEF_OUT_STR (GL_DST_ALPHA)
      DEF_OUT_STR (GL_ONE_MINUS_DST_ALPHA)
      DEF_OUT_STR (GL_CONSTANT_COLOR)
      DEF_OUT_STR (GL_ONE_MINUS_CONSTANT_COLOR)
      DEF_OUT_STR (GL_CONSTANT_ALPHA)
      DEF_OUT_STR (GL_ONE_MINUS_CONSTANT_ALPHA)
      DEF_OUT_STR (GL_SRC_ALPHA_SATURATE)
      DEF_OUT_STR (GL_SRC1_COLOR)
      DEF_OUT_STR (GL_ONE_MINUS_SRC1_COLOR)
      DEF_OUT_STR (GL_SRC1_ALPHA)
      DEF_OUT_STR (GL_ONE_MINUS_SRC1_ALPHA)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_boolean
//
const char* gl_show_boolean (const GLboolean boolean) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (boolean) {
      DEF_OUT_STR (GL_FALSE)
      DEF_OUT_STR (GL_TRUE)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_clamp_read_color
//
const char* gl_show_clamp_read_color (const GLenum clamp) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (clamp) {
      DEF_OUT_STR (GL_FALSE)
      DEF_OUT_STR (GL_TRUE)
      DEF_OUT_STR (GL_FIXED_ONLY)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_color_buffer
//
const char* gl_show_color_buffer (const GLenum color_buffer) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (color_buffer) {
      DEF_OUT_STR (GL_NONE)
      // default framebuffer
      DEF_OUT_STR (GL_FRONT_LEFT)
      DEF_OUT_STR (GL_FRONT_RIGHT)
      DEF_OUT_STR (GL_BACK_LEFT)
      DEF_OUT_STR (GL_BACK_RIGHT)
      DEF_OUT_STR (GL_FRONT)
      DEF_OUT_STR (GL_BACK)
      DEF_OUT_STR (GL_LEFT)
      DEF_OUT_STR (GL_RIGHT)
      DEF_OUT_STR (GL_FRONT_AND_BACK)
      // FBOs
      DEF_OUT_STR (GL_COLOR_ATTACHMENT0)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT1)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT2)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT3)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT4)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT5)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT6)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT7)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT8)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT9)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT10)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT11)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT12)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT13)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT14)
      DEF_OUT_STR (GL_COLOR_ATTACHMENT15)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_cull_face_mode
//
const char* gl_show_cull_face_mode (const GLenum mode) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (mode) {
      DEF_OUT_STR (GL_FRONT)
      DEF_OUT_STR (GL_BACK)
      DEF_OUT_STR (GL_FRONT_AND_BACK)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_depth_func
//
const char* gl_show_depth_func (const GLenum depth_func) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (depth_func) {
      DEF_OUT_STR (GL_NEVER)
      DEF_OUT_STR (GL_LESS)
      DEF_OUT_STR (GL_EQUAL)
      DEF_OUT_STR (GL_LEQUAL )
      DEF_OUT_STR (GL_GREATER)
      DEF_OUT_STR (GL_NOTEQUAL)
      DEF_OUT_STR (GL_GEQUAL )
      DEF_OUT_STR (GL_ALWAYS)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_error
//
const char* gl_show_error (const GLenum error) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (error) {
      DEF_OUT_STR (GL_NO_ERROR)
      DEF_OUT_STR (GL_INVALID_ENUM)
      DEF_OUT_STR (GL_INVALID_VALUE)
      DEF_OUT_STR (GL_INVALID_OPERATION)
      DEF_OUT_STR (GL_OUT_OF_MEMORY)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_hint
//
const char* gl_show_hint (const GLenum hint) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (hint) {
      DEF_OUT_STR (GL_DONT_CARE)
      DEF_OUT_STR (GL_FASTEST)
      DEF_OUT_STR (GL_NICEST)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_image_format
//
const char* gl_show_image_format (const GLenum image_format) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (image_format) {
      /* OpenGL 1.1 */
      DEF_OUT_STR (GL_R3_G3_B2)
      DEF_OUT_STR (GL_RGB4)
      DEF_OUT_STR (GL_RGB5)
      DEF_OUT_STR (GL_RGB8)
      DEF_OUT_STR (GL_RGB10)
      DEF_OUT_STR (GL_RGB12)
      DEF_OUT_STR (GL_RGB16)
      DEF_OUT_STR (GL_RGBA2)
      DEF_OUT_STR (GL_RGBA4)
      DEF_OUT_STR (GL_RGB5_A1)
      DEF_OUT_STR (GL_RGBA8)
      DEF_OUT_STR (GL_RGB10_A2)
      DEF_OUT_STR (GL_RGBA12)
      DEF_OUT_STR (GL_RGBA16)
      /* OpenGL 1.3 */
      DEF_OUT_STR (GL_COMPRESSED_RGB)
      DEF_OUT_STR (GL_COMPRESSED_RGBA)
      DEF_OUT_STR (GL_COMPRESSED_ALPHA)
      /* OpenGL 1.4 */
      DEF_OUT_STR (GL_DEPTH_COMPONENT16)
      DEF_OUT_STR (GL_DEPTH_COMPONENT24)
      DEF_OUT_STR (GL_DEPTH_COMPONENT32)
      /* OpenGL 2.1 */
      DEF_OUT_STR (GL_SRGB8)
      DEF_OUT_STR (GL_SRGB8_ALPHA8)
      DEF_OUT_STR (GL_COMPRESSED_SRGB)
      DEF_OUT_STR (GL_COMPRESSED_SRGB_ALPHA)
      /* OpenGL 3.0 */
      DEF_OUT_STR (GL_RGBA32F)
      DEF_OUT_STR (GL_RGB32F)
      DEF_OUT_STR (GL_RGBA16F)
      DEF_OUT_STR (GL_RGB16F)
      DEF_OUT_STR (GL_R11F_G11F_B10F)
      DEF_OUT_STR (GL_RGB9_E5)
      DEF_OUT_STR (GL_RGBA32UI)
      DEF_OUT_STR (GL_RGB32UI)
      DEF_OUT_STR (GL_RGBA16UI)
      DEF_OUT_STR (GL_RGB16UI)
      DEF_OUT_STR (GL_RGBA8UI)
      DEF_OUT_STR (GL_RGB8UI)
      DEF_OUT_STR (GL_RGBA32I)
      DEF_OUT_STR (GL_RGB32I)
      DEF_OUT_STR (GL_RGBA16I)
      DEF_OUT_STR (GL_RGB16I)
      DEF_OUT_STR (GL_RGBA8I)
      DEF_OUT_STR (GL_RGB8I)
      DEF_OUT_STR (GL_R8)
      DEF_OUT_STR (GL_R16)
      DEF_OUT_STR (GL_RG8)
      DEF_OUT_STR (GL_R16F)
      DEF_OUT_STR (GL_R32F)
      DEF_OUT_STR (GL_RG16F)
      DEF_OUT_STR (GL_RG32F)
      DEF_OUT_STR (GL_R8I)
      DEF_OUT_STR (GL_R8UI)
      DEF_OUT_STR (GL_R16I)
      DEF_OUT_STR (GL_R16UI)
      DEF_OUT_STR (GL_R32I)
      DEF_OUT_STR (GL_R32UI)
      DEF_OUT_STR (GL_RG8I)
      DEF_OUT_STR (GL_RG8UI)
      DEF_OUT_STR (GL_RG16I)
      DEF_OUT_STR (GL_RG16UI)
      DEF_OUT_STR (GL_RG32I)
      DEF_OUT_STR (GL_RG32UI)
      DEF_OUT_STR (GL_DEPTH_COMPONENT32F)
      DEF_OUT_STR (GL_DEPTH24_STENCIL8)
      DEF_OUT_STR (GL_DEPTH32F_STENCIL8)
      DEF_OUT_STR (GL_STENCIL_INDEX1)
      DEF_OUT_STR (GL_STENCIL_INDEX4)
      DEF_OUT_STR (GL_STENCIL_INDEX8)
      DEF_OUT_STR (GL_STENCIL_INDEX16)
      DEF_OUT_STR (GL_COMPRESSED_RED)
      DEF_OUT_STR (GL_COMPRESSED_RG)
      DEF_OUT_STR (GL_COMPRESSED_RED_RGTC1)
      DEF_OUT_STR (GL_COMPRESSED_SIGNED_RED_RGTC1)
      DEF_OUT_STR (GL_COMPRESSED_RG_RGTC2)
      DEF_OUT_STR (GL_COMPRESSED_SIGNED_RG_RGTC2)
      /* OpenGL 3.1 */
      DEF_OUT_STR (GL_R8_SNORM)
      DEF_OUT_STR (GL_RG8_SNORM)
      DEF_OUT_STR (GL_RGB8_SNORM)
      DEF_OUT_STR (GL_RGBA8_SNORM)
      DEF_OUT_STR (GL_R16_SNORM)
      DEF_OUT_STR (GL_RG16_SNORM)
      DEF_OUT_STR (GL_RGB16_SNORM)
      DEF_OUT_STR (GL_RGBA16_SNORM)
      /* OpenGL 3.3 */
      DEF_OUT_STR (GL_RGB10_A2UI)
      /* OpenGL 4.1 */
      DEF_OUT_STR (GL_RGB565)
      /* OpenGL 4.2 */
      DEF_OUT_STR (GL_COMPRESSED_RGBA_BPTC_UNORM)
      DEF_OUT_STR (GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM)
      DEF_OUT_STR (GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT)
      DEF_OUT_STR (GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT)
      /* OpenGL 4.3 */
      DEF_OUT_STR (GL_COMPRESSED_RGB8_ETC2)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ETC2)
      DEF_OUT_STR (GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2)
      DEF_OUT_STR (GL_COMPRESSED_RGBA8_ETC2_EAC)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC)
      DEF_OUT_STR (GL_COMPRESSED_R11_EAC)
      DEF_OUT_STR (GL_COMPRESSED_SIGNED_R11_EAC)
      DEF_OUT_STR (GL_COMPRESSED_RG11_EAC)
      DEF_OUT_STR (GL_COMPRESSED_SIGNED_RG11_EAC)
      /* EXT S3 Texture Compression (S3TC) extension */
      DEF_OUT_STR (GL_COMPRESSED_RGB_S3TC_DXT1_EXT)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_S3TC_DXT1_EXT)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_S3TC_DXT3_EXT)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_S3TC_DXT5_EXT)
      /* OES compressed paletted texture extension */
      DEF_OUT_STR (GL_PALETTE4_RGB8_OES)
      DEF_OUT_STR (GL_PALETTE4_RGBA8_OES)
      DEF_OUT_STR (GL_PALETTE4_R5_G6_B5_OES)
      DEF_OUT_STR (GL_PALETTE4_RGBA4_OES)
      DEF_OUT_STR (GL_PALETTE4_RGB5_A1_OES)
      DEF_OUT_STR (GL_PALETTE8_RGB8_OES)
      DEF_OUT_STR (GL_PALETTE8_RGBA8_OES)
      DEF_OUT_STR (GL_PALETTE8_R5_G6_B5_OES)
      DEF_OUT_STR (GL_PALETTE8_RGBA4_OES)
      DEF_OUT_STR (GL_PALETTE8_RGB5_A1_OES)
      /* KHR Adaptable Scalable Texture (ASTC) extension */
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_4x4_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_5x4_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_5x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_6x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_6x6_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_8x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_8x6_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_8x8_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_10x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_10x6_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_10x8_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_10x10_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_12x10_KHR)
      DEF_OUT_STR (GL_COMPRESSED_RGBA_ASTC_12x12_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR)
      DEF_OUT_STR (GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_logic_op
//
const char* gl_show_logic_op (const GLenum logic_op) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (logic_op) {
      DEF_OUT_STR (GL_CLEAR)
      DEF_OUT_STR (GL_AND)
      DEF_OUT_STR (GL_AND_REVERSE)
      DEF_OUT_STR (GL_AND_INVERTED)
      DEF_OUT_STR (GL_COPY)
      DEF_OUT_STR (GL_NOOP)
      DEF_OUT_STR (GL_XOR)
      DEF_OUT_STR (GL_OR)
      DEF_OUT_STR (GL_NOR)
      DEF_OUT_STR (GL_EQUIV)
      DEF_OUT_STR (GL_INVERT)
      DEF_OUT_STR (GL_OR_REVERSE)
      DEF_OUT_STR (GL_COPY_INVERTED)
      DEF_OUT_STR (GL_OR_INVERTED)
      DEF_OUT_STR (GL_NAND)
      DEF_OUT_STR (GL_SET)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_pixel_data_format
//
const char* gl_show_pixel_data_format (const GLenum pixel_data_format) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (pixel_data_format) {
      DEF_OUT_STR (GL_STENCIL_INDEX)
      DEF_OUT_STR (GL_DEPTH_COMPONENT)
      DEF_OUT_STR (GL_DEPTH_STENCIL)
      DEF_OUT_STR (GL_RED)
      DEF_OUT_STR (GL_GREEN)
      DEF_OUT_STR (GL_BLUE)
      DEF_OUT_STR (GL_RGB)
      DEF_OUT_STR (GL_BGR)
      DEF_OUT_STR (GL_RGBA)
      DEF_OUT_STR (GL_BGRA)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_pixel_data_type
//
const char* gl_show_pixel_data_type (const GLenum pixel_data_type) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (pixel_data_type) {
      DEF_OUT_STR (GL_UNSIGNED_BYTE)
      DEF_OUT_STR (GL_BYTE)
      DEF_OUT_STR (GL_UNSIGNED_SHORT)
      DEF_OUT_STR (GL_SHORT)
      DEF_OUT_STR (GL_UNSIGNED_INT)
      DEF_OUT_STR (GL_INT)
      DEF_OUT_STR (GL_HALF_FLOAT)
      DEF_OUT_STR (GL_FLOAT)
      DEF_OUT_STR (GL_UNSIGNED_BYTE_3_3_2)
      DEF_OUT_STR (GL_UNSIGNED_BYTE_2_3_3_REV)
      DEF_OUT_STR (GL_UNSIGNED_SHORT_5_6_5)
      DEF_OUT_STR (GL_UNSIGNED_SHORT_5_6_5_REV)
      DEF_OUT_STR (GL_UNSIGNED_SHORT_4_4_4_4)
      DEF_OUT_STR (GL_UNSIGNED_SHORT_4_4_4_4_REV)
      DEF_OUT_STR (GL_UNSIGNED_SHORT_5_5_5_1)
      DEF_OUT_STR (GL_UNSIGNED_SHORT_1_5_5_5_REV)
      DEF_OUT_STR (GL_UNSIGNED_INT_8_8_8_8)
      DEF_OUT_STR (GL_UNSIGNED_INT_8_8_8_8_REV)
      DEF_OUT_STR (GL_UNSIGNED_INT_10_10_10_2)
      DEF_OUT_STR (GL_UNSIGNED_INT_2_10_10_10_REV)
      DEF_OUT_STR (GL_UNSIGNED_INT_24_8)
      DEF_OUT_STR (GL_UNSIGNED_INT_10F_11F_11F_REV)
      DEF_OUT_STR (GL_UNSIGNED_INT_5_9_9_9_REV)
      DEF_OUT_STR (GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_point_sprite_origin
//
const char* gl_show_point_sprite_origin (const GLenum origin) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (origin) {
      DEF_OUT_STR (GL_LOWER_LEFT)
      DEF_OUT_STR (GL_UPPER_LEFT)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_polygon_mode
//
const char* gl_show_polygon_mode (const GLenum mode) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (mode) {
      DEF_OUT_STR (GL_LINE)
      DEF_OUT_STR (GL_POINT)
      DEF_OUT_STR (GL_FILL)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_provoke_convention
//
const char* gl_show_provoke_convention (const GLenum provoke_convention) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (provoke_convention) {
      DEF_OUT_STR (GL_PROVOKING_VERTEX)
      DEF_OUT_STR (GL_LAST_VERTEX_CONVENTION)
      DEF_OUT_STR (GL_FIRST_VERTEX_CONVENTION)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_rw_access
//
const char* gl_show_rw_access (const GLenum rw_access) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (rw_access) {
      DEF_OUT_STR (GL_READ_ONLY)
      DEF_OUT_STR (GL_WRITE_ONLY)
      DEF_OUT_STR (GL_READ_WRITE)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_stencil_op
//
const char* gl_show_stencil_op (const GLenum stencil_op) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (stencil_op) {
      DEF_OUT_STR (GL_KEEP)
      DEF_OUT_STR (GL_REPLACE)
      DEF_OUT_STR (GL_INCR)
      DEF_OUT_STR (GL_DECR)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_texture_unit
//
const char* gl_show_texture_unit (const GLenum texture_unit) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (texture_unit) {
      DEF_OUT_STR (GL_TEXTURE0)
      DEF_OUT_STR (GL_TEXTURE1)
      DEF_OUT_STR (GL_TEXTURE2)
      DEF_OUT_STR (GL_TEXTURE3)
      DEF_OUT_STR (GL_TEXTURE4)
      DEF_OUT_STR (GL_TEXTURE5)
      DEF_OUT_STR (GL_TEXTURE6)
      DEF_OUT_STR (GL_TEXTURE7)
      DEF_OUT_STR (GL_TEXTURE8)
      DEF_OUT_STR (GL_TEXTURE9)
      DEF_OUT_STR (GL_TEXTURE10)
      DEF_OUT_STR (GL_TEXTURE11)
      DEF_OUT_STR (GL_TEXTURE12)
      DEF_OUT_STR (GL_TEXTURE13)
      DEF_OUT_STR (GL_TEXTURE14)
      DEF_OUT_STR (GL_TEXTURE15)
      DEF_OUT_STR (GL_TEXTURE16)
      DEF_OUT_STR (GL_TEXTURE17)
      DEF_OUT_STR (GL_TEXTURE18)
      DEF_OUT_STR (GL_TEXTURE19)
      DEF_OUT_STR (GL_TEXTURE20)
      DEF_OUT_STR (GL_TEXTURE21)
      DEF_OUT_STR (GL_TEXTURE22)
      DEF_OUT_STR (GL_TEXTURE23)
      DEF_OUT_STR (GL_TEXTURE24)
      DEF_OUT_STR (GL_TEXTURE25)
      DEF_OUT_STR (GL_TEXTURE26)
      DEF_OUT_STR (GL_TEXTURE27)
      DEF_OUT_STR (GL_TEXTURE28)
      DEF_OUT_STR (GL_TEXTURE29)
      DEF_OUT_STR (GL_TEXTURE30)
      DEF_OUT_STR (GL_TEXTURE31)
      default: assert(0); break;
    }
  }
  return out;
}

//
//  gl_show_winding
//
const char* gl_show_winding (const GLenum winding) {
  const char* out = NULL;
  if (gl_check_context()) {
    switch (winding) {
      DEF_OUT_STR (GL_CCW)
      DEF_OUT_STR (GL_CW)
      default: assert(0); break;
    }
  }
  return out;
}
