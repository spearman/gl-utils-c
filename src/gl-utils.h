#pragma once

/*!
@mainpage
@section environment_variables Environment variables

The following environment variables can be set:

- `GL_UTILS_FATAL_ERRORS` -- if set, raise an assertion when an error is
  encountered by `gl_check_error()`.

@section gl_overview OpenGL overview

- OpenGL Context
    - `gl_info_context_constant_write()`
    - `gl_info_context_state_write()`
    - `gl_info_context_glsl_versions_write()`
    - `gl_info_context_extensions_write()`
    - `gl_info_context_compressed_tex_fmts_write()`
- Shader shader_programs
    - `gl_info_shader_program_constant_write()`
    - `gl_info_shader_program_state_write()`
    - `gl_info_shader_program_buffers_write()`
- Framebuffers
    - `gl_info_framebuffer_constant_write()`
    - `gl_info_framebuffer_state_write()`
- Textures
    - `gl_info_texture_constant_write()`
    - `gl_info_texture_state_write()`
- Image load/store
    - `gl_info_image_loadstore_constant_write()`
    - `gl_info_image_loadstore_state_write()`
- Vertex specification
    - `gl_info_vertex_specification_constant_write()`
    - `gl_info_vertex_specification_state_write()`
- [Vertex rendering pipeline](#vertex_rendering)
    - `gl_info_vertex_rendering_constant_write()`
    - `gl_info_vertex_rendering_state_write()`
- Compute shaders
    - `gl_info_compute_shader_constant_write()`
    - `gl_info_compute_shader_state_write()`
- Pixel transfer
    - `gl_info_pixel_transfer_constant_write()`
    - `gl_info_pixel_transfer_state_write()`
- Synchronization
    - `gl_info_synchronization_constant_write()`
    - `gl_info_synchronization_state_write()`
- Asynchronous Queries
    - `gl_info_asynchronous_queries_constant_write()`
    - `gl_info_asynchronous_queries_state_write()`
- Debug output
    - `gl_info_debug_output_constant_write()`
    - `gl_info_debug_output_state_write()`

Rendering commands can be either drawing ([vertex
rendering](#vertex_rendering)), framebuffer clearing, framebuffer blitting, or
compute dispatch commands, where the first three write into the active draw
color buffer(s) of the currently bound framebuffer.


@subsection vertex_rendering Vertex rendering pipeline overview

Vertex data (attributes) that have been specified within a Vertex Array Object
(VAO) are sent through the vertex rendering pipeline by issuing *draw commands*
(`gl*Draw*`), writing fragment shader output into the active draw color
buffer(s) of the currently bound framebuffer.

Pipeline overview where `(*)` indicates a "programmable" stage:

1. Vertex processing -- <BR>
  `gl_info_vertex_processing_constant_write()` <BR>
  `gl_info_vertex_processing_state_write()`
    1. Vertex shader (*)
    2. Tessellation
        1. Early primitive assembly
        2. Tessellation control shader (*)
        3. Tessellation primitive generator
        4. Tessellation evaluation shader (*)
    3. Geometry
        1. Early primitive assembly
        2. Geometry shader (*)
2. Vertex post-processing -- <BR>
  `gl_info_vertex_postprocessing_constant_write()` <BR>
  `gl_info_vertex_postprocessing_state_write()`
    1. Transform feedback
    2. Clipping
    3. Perspective divide
    4. Viewport transform
3. Primitive assembly -- <BR>
  `gl_info_primitive_assembly_constant_write()` <BR>
  `gl_info_primitive_assembly_state_write()`
    1. Face culling
4. Rasterization -- <BR>
  `gl_info_rasterization_constant_write()` <BR>
  `gl_info_rasterization_state_write()`
    1. Rasterizer discard
    2. Scan conversion
    3. Multisampling
    4. Primitive parameter interpolation
5. Early Per-sample Operations -- <BR>
  `gl_info_persample_early_constant_write()` <BR>
  `gl_info_persample_early_state_write()`
    1. Pixel ownership test
    2. Scissor test
6. Fragment shader (*) -- <BR>
  `gl_info_fragment_shader_constant_write()` <BR>
  `gl_info_fragment_shader_state_write()`
7. Per-sample processing -- <BR>
  `gl_info_persample_processing_constant_write()` <BR>
  `gl_info_persample_processing_state_write()`
    1. Multisampling
    2. Stencil test
    3. Depth test
    4. Occlusion query update
    5. Blending
    6. sRGB conversion
    7. Dithering
    8. Logical operations
    9. Write mask

Some parts of the pipeline are involved in other *rendering commands*:

- *Framebuffer clearing* -- affected by rasterizer discard (4.a), pixel
  ownership test (5.a), scissor test (5.b) and write mask (7.i)
- *Framebuffer blitting* -- affected by pixel ownership test (5.a) and scissor
  test (5.b)

*/

//! @file gl-utils.h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <glad/glad.h>

/* gl-utils/info.c */
void gl_info_constant_print                       ();
void gl_info_constant_write                       (FILE* file);
void gl_info_state_print                          ();
void gl_info_state_write                          (FILE* file);

/* gl-utils/info/context.c */
void gl_info_context_constant_print               ();
void gl_info_context_constant_write               (FILE* file);
void gl_info_context_state_print                  ();
void gl_info_context_state_write                  (FILE* file);

void gl_info_context_glsl_versions_print          ();
void gl_info_context_glsl_versions_write          (FILE* file);
void gl_info_context_extensions_print             ();
void gl_info_context_extensions_write             (FILE* file);
void gl_info_context_compressed_tex_fmts_print    ();
void gl_info_context_compressed_tex_fmts_write    (FILE* file);

/* gl-utils/info/shader-program.c */
void gl_info_shader_program_constant_print        ();
void gl_info_shader_program_constant_write        (FILE* file);
void gl_info_shader_program_state_print           ();
void gl_info_shader_program_state_write           (FILE* file);
void gl_info_shader_program_buffers_print         ();
void gl_info_shader_program_buffers_write         (FILE* file);

/* gl-utils/info/-.c */
void gl_info_framebuffer_constant_print           ();
void gl_info_framebuffer_constant_write           (FILE* file);
void gl_info_framebuffer_state_print              ();
void gl_info_framebuffer_state_write              (FILE* file);
void gl_info_texture_constant_print               ();
void gl_info_texture_constant_write               (FILE* file);
void gl_info_texture_state_print                  ();
void gl_info_texture_state_write                  (FILE* file);
void gl_info_image_loadstore_constant_print       ();
void gl_info_image_loadstore_constant_write       (FILE* file);
void gl_info_image_loadstore_state_print          ();
void gl_info_image_loadstore_state_write          (FILE* file);
void gl_info_vertex_specification_constant_print  ();
void gl_info_vertex_specification_constant_write  (FILE* file);
void gl_info_vertex_specification_state_print     ();
void gl_info_vertex_specification_state_write     (FILE* file);
void gl_info_compute_shader_constant_print        ();
void gl_info_compute_shader_constant_write        (FILE* file);
void gl_info_compute_shader_state_print           ();
void gl_info_compute_shader_state_write           (FILE* file);
void gl_info_pixel_transfer_constant_print        ();
void gl_info_pixel_transfer_constant_write        (FILE* file);
void gl_info_pixel_transfer_state_print           ();
void gl_info_pixel_transfer_state_write           (FILE* file);
void gl_info_synchronization_constant_print       ();
void gl_info_synchronization_constant_write       (FILE* file);
void gl_info_synchronization_state_print          ();
void gl_info_synchronization_state_write          (FILE* file);
void gl_info_asynchronous_queries_constant_print  ();
void gl_info_asynchronous_queries_constant_write  (FILE* file);
void gl_info_asynchronous_queries_state_print     ();
void gl_info_asynchronous_queries_state_write     (FILE* file);
void gl_info_debug_output_constant_print          ();
void gl_info_debug_output_constant_write          (FILE* file);
void gl_info_debug_output_state_print             ();
void gl_info_debug_output_state_write             (FILE* file);

/* gl-utils/info/vertex-rendering.c */
void gl_info_vertex_rendering_constant_print      ();
void gl_info_vertex_rendering_constant_write      (FILE* file);
void gl_info_vertex_rendering_state_print         ();
void gl_info_vertex_rendering_state_write         (FILE* file);
/* gl-utils/info/vertex-rendering/-.c */
void gl_info_vertex_processing_constant_print     ();
void gl_info_vertex_processing_constant_write     (FILE* file);
void gl_info_vertex_processing_state_print        ();
void gl_info_vertex_processing_state_write        (FILE* file);
void gl_info_vertex_postprocessing_constant_print ();
void gl_info_vertex_postprocessing_constant_write (FILE* file);
void gl_info_vertex_postprocessing_state_print    ();
void gl_info_vertex_postprocessing_state_write    (FILE* file);
void gl_info_primitive_assembly_constant_print    ();
void gl_info_primitive_assembly_constant_write    (FILE* file);
void gl_info_primitive_assembly_state_print       ();
void gl_info_primitive_assembly_state_write       (FILE* file);
void gl_info_rasterization_constant_print         ();
void gl_info_rasterization_constant_write         (FILE* file);
void gl_info_rasterization_state_print            ();
void gl_info_rasterization_state_write            (FILE* file);
void gl_info_persample_early_constant_print       ();
void gl_info_persample_early_constant_write       (FILE* file);
void gl_info_persample_early_state_print          ();
void gl_info_persample_early_state_write          (FILE* file);
void gl_info_fragment_shader_constant_print       ();
void gl_info_fragment_shader_constant_write       (FILE* file);
void gl_info_fragment_shader_state_print          ();
void gl_info_fragment_shader_state_write          (FILE* file);
void gl_info_persample_processing_constant_print  ();
void gl_info_persample_processing_constant_write  (FILE* file);
void gl_info_persample_processing_state_print     ();
void gl_info_persample_processing_state_write     (FILE* file);

const char* gl_show_blend_eq            (const GLenum blend_eq);
const char* gl_show_blend_func          (const GLenum blend_func);
const char* gl_show_boolean             (const GLboolean boolean);
const char* gl_show_clamp_read_color    (const GLenum clamp);
const char* gl_show_color_buffer        (const GLenum color_buffer);
const char* gl_show_cull_face_mode      (const GLenum mode);
const char* gl_show_depth_func          (const GLenum func);
const char* gl_show_error               (const GLenum error);
const char* gl_show_hint                (const GLenum hint);
const char* gl_show_image_format        (const GLenum image_format);
const char* gl_show_logic_op            (const GLenum logic_op);
const char* gl_show_pixel_data_format   (const GLenum fmt);
const char* gl_show_pixel_data_type     (const GLenum type);
const char* gl_show_point_sprite_origin (const GLenum origin);
const char* gl_show_polygon_mode        (const GLenum mode);
const char* gl_show_provoke_convention  (const GLenum provoke_convention);
const char* gl_show_rw_access           (const GLenum rw_access);
const char* gl_show_stencil_op          (const GLenum stencil_op);
const char* gl_show_texture_unit        (const GLenum texture_unit);
const char* gl_show_winding             (const GLenum winding);

bool gl_check_context();
void gl_check_error();
bool gl_extension_is_supported (const char* const extension);

#ifdef TEST
void test_myfun ();
void test_pos_id();
#endif
