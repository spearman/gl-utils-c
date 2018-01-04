/// To request an OpenGL 3.3 core profile, the environment variable
/// `GL_UTILS_REQUEST_3_3_CORE` may be set.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>

#include <SDL2/SDL.h>

#include "gl-utils.h"

const uint64_t CYCLE_FRAMES = 180;

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

//
//  sdl_check_error
//
void sdl_check_error() {
  const char* error_message = SDL_GetError();
  const char* empty_string = "";
  if (error_message == empty_string) {
    printf ("SDL ERROR: sdl error message: %s\n", error_message);
    SDL_ClearError();
  }
}

//
//  sdl_gl_cleanup
//
void sdl_gl_cleanup (SDL_GLContext context, SDL_Window* window) {
  SDL_GL_DeleteContext (context);
  SDL_DestroyWindow (window);
  SDL_Quit();
}

//
//  color_cycle
//
float color_cycle (const uint64_t frame, const uint64_t cycle_length) {
  const uint64_t mod_frame  = frame % cycle_length;
  const double   frac_cycle = (double) mod_frame / (double) cycle_length;
  assert (0.0 <= frac_cycle);
  assert (frac_cycle < 1.0);
  double out;
  if (frac_cycle < 0.5) {
    const double val = frac_cycle * (-6.0) + 2.0;
    out = fmin (1.0, fmax (0.0, val));
  } else {
    const double val = frac_cycle * 6.0 - 4.0;
    out = fmin (1.0, fmax (0.0, val));
  }
  out = (-0.5 *cos (out * M_PI)) + 0.5; // smooth the transition
  return (float) out;
}

//
//  color_cycle_rgb
//
void color_cycle_rgb (
  const uint64_t frame, const uint64_t cycle_length,
  float* r, float* g, float* b
) {
  const uint64_t one_third_cycle = cycle_length / 3;
  const uint64_t two_third_cycle = (2 * cycle_length) / 3;
  const double green_factor = 144.0/255.0;
  const double red_factor = 210.0/255.0;
  *b = color_cycle (frame, cycle_length);
  *g = green_factor * color_cycle (frame + two_third_cycle, cycle_length);
  *r = red_factor * color_cycle (frame + one_third_cycle, cycle_length);
}

///////////////////////////////////////////////////////////////////////////////
//  main                                                                     //
///////////////////////////////////////////////////////////////////////////////

/// Note SDL2 requires on Windows that the `main` function signature has the
/// arguments `argc` and `argv`, although they are not used here.
///
/// Environment variables that may be set:
///
/// - `GL_UTILS_REQUEST_3_3_CORE` -- if set, SDL will set GL attributes
/// indicating / that an OpenGL 3.3 core profile should be requested (even
/// if the system supports newer OpenGL versions).

int main (int argc, char* argv[]) {
  // avoid "unused variable" warnings
  assert (argc == argc); assert (argv == argv);

  puts ("glutils main...");

  //
  //  initialize
  //
  puts ("initialize...");
  // initialize sdl video subsystem
  if (SDL_Init (SDL_INIT_VIDEO) < 0) {
    puts ("error: sdl init video failed");
    sdl_check_error();
    exit (1);
  }

  // set gl attributes before window creation
  if (getenv ("GL_UTILS_REQUEST_4_5_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 5) < 0) {
      sdl_check_error();
    }
  } else if (getenv ("GL_UTILS_REQUEST_4_4_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
  } else if (getenv ("GL_UTILS_REQUEST_4_3_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 3) < 0) {
      sdl_check_error();
    }
  } else if (getenv ("GL_UTILS_REQUEST_4_2_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 2) < 0) {
      sdl_check_error();
    }
  } else if (getenv ("GL_UTILS_REQUEST_4_1_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 1) < 0) {
      sdl_check_error();
    }
  } else if (getenv ("GL_UTILS_REQUEST_4_0_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 0) < 0) {
      sdl_check_error();
    }
  } else if (getenv ("GL_UTILS_REQUEST_3_3_CORE")) {
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3) < 0) {
      sdl_check_error();
    }
    if (SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 3) < 0) {
      sdl_check_error();
    }
  }

  if (SDL_GL_SetAttribute (
    // core context profile makes deprecated functions unavailable
    // this only seems to take effect if a specific GL version is requested
    // above
    SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE) < 0)
  {
    sdl_check_error();
  }

  if (SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, 24) < 0) {
    sdl_check_error();
  } if (SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1) < 0) {
    sdl_check_error();
  }
  puts ("...SDL GL attributes set...");

  // create new window as child of root window
  SDL_Window* window = SDL_CreateWindow (
    "my sdl window",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // x,y pos
    320, 240,                                       // width,height
    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  if (window == NULL) {
    puts ("error: sdl create window failed");
    sdl_check_error();
    exit (1);
  }
  puts ("...SDL window created...");

  // /!\ Warning: these swap interval settings override the
  // /!\ system vsync settings (nvidia-settings)
  #define IMMEDIATE_UPDATE 0
  #define LATE_SWAP_TEARING -1
  #define ON_VSYNC 1    // wait for vsync
  if (SDL_GL_SetSwapInterval (ON_VSYNC) < 0) {
    sdl_check_error();
  }
  puts ("...SDL GL swap interval set...");

  // create sdl gl context
  SDL_GLContext context = SDL_GL_CreateContext (window);
  if (context == NULL) {
    puts ("error: sdl create gl context failed");
    sdl_check_error();
    exit (1);
  }
  puts ("...SDL OpenGL Context created...");

  // glad init
  if (!gladLoadGL()) {
    puts ("error: glad load gl failed");
    exit (1);
  }
  gl_check_error();
  puts ("...glad OpenGL loaded...");

  puts ("...initialize");
  // end initialize

  //
  // write infos
  //
  puts ("\
*******************************************************************************");
  gl_info_context_constant_print();
  gl_check_error();
  gl_info_context_state_print();
  gl_check_error();
  puts ("\
*******************************************************************************");
  //gl_info_context_glsl_versions_print();
  //gl_info_context_extensions_print();
  //gl_info_context_compressed_tex_fmts_print();
  //gl_check_error();
  /*
  puts ("\
*******************************************************************************");
  */
  //gl_info_shader_program_constant_print();
  //gl_info_shader_program_state_print();
  //gl_info_shader_program_buffers_print();
  //gl_info_framebuffer_constant_print();
  //gl_info_framebuffer_state_print();
  //gl_info_texture_constant_print();
  //gl_info_texture_state_print();
  //gl_info_image_loadstore_constant_print();
  //gl_info_image_loadstore_state_print();
  //gl_info_vertex_specification_constant_print();
  //gl_info_vertex_specification_state_print();
  //gl_info_compute_shader_constant_print();
  //gl_info_compute_shader_state_print();
  //gl_info_pixel_transfer_constant_print();
  //gl_info_pixel_transfer_state_print();
  //gl_info_synchronization_constant_print();
  //gl_info_synchronization_state_print();
  //gl_info_asynchronous_queries_constant_print();
  //gl_info_asynchronous_queries_state_print();
  //gl_info_debug_output_constant_print();
  //gl_info_debug_output_state_print();
  //gl_check_error();
  /*
  puts ("\
*******************************************************************************");
  */
  //gl_info_vertex_rendering_constant_print();
  //gl_info_vertex_rendering_state_print();

  //gl_info_vertex_processing_constant_print();
  //gl_info_vertex_processing_state_print();
  //gl_info_vertex_postprocessing_constant_print();
  //gl_info_vertex_postprocessing_state_print();
  //gl_info_primitive_assembly_constant_print();
  //gl_info_primitive_assembly_state_print();
  //gl_info_rasterization_constant_print();
  //gl_info_rasterization_state_print();
  //gl_info_persample_early_constant_print();
  //gl_info_persample_early_state_print();
  //gl_info_fragment_shader_constant_print();
  //gl_info_fragment_shader_state_print();
  //gl_info_persample_processing_constant_print();
  //gl_info_persample_processing_state_print();
  //gl_check_error();
  puts ("dumping gl constants to stderr...");
  fprintf (stderr, "\
*******************************************************************************\
\n");
  gl_info_constant_write (stderr);
  gl_check_error();
  puts ("dumping gl state to stderr...");
  fprintf (stderr, "\
*******************************************************************************\
\n");
  gl_info_state_write (stderr);
  gl_check_error();
  fprintf (stderr, "\
*******************************************************************************\
\n");
  //assert(0);

  //
  //  main loop
  //
  puts ("run main loop...");
  uint64_t     frame  = 0;
  unsigned int fps    = 0;
  time_t       last_t = time(NULL);
  printf ("start time: %ld\n", (long)last_t);
  while (1) {
    // sdl events
    SDL_Event event;
    bool quit = false;
    while (SDL_PollEvent (&event)) {
      if (event.type == SDL_WINDOWEVENT) {
        int width,height;
        SDL_GL_GetDrawableSize (window, &width, &height);
        glViewport (
          0, 0,   // lower left corner
          width, height);
      } else if (event.type == SDL_KEYDOWN) {
        #ifdef DEBUG
        printf ("key press event time (ms): %u\n", event.key.timestamp);
        printf ("key press event scancode: %u\n",
          event.key.keysym.scancode);
        #endif
        const SDL_Scancode scancode = event.key.keysym.scancode;
        if (scancode == SDL_SCANCODE_Q) {
          quit = true;
          break;
        }
      } else if (event.type == SDL_QUIT) {
        quit = true;
        break;
      }
    }
    // end sdl events
    if (quit) {
      break;
    }

    // render
    float clear_red, clear_green, clear_blue;
    color_cycle_rgb (frame, CYCLE_FRAMES, &clear_red, &clear_green, &clear_blue);
    //printf ("clear color: %f %f %f\n", clear_red, clear_green, clear_blue);
    glClearColor (clear_red, clear_green, clear_blue, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow (window);

    frame += 1;

    // fps timer
    time_t t = time (NULL);
    if (t != last_t) {
      assert (last_t < t);
      last_t = t;
      printf ("fps: %u\n", fps);
      fps = 0;
    } else {
      fps += 1;
    }
  }
  puts ("...run main loop");
  // end main loop

  // cleanup
  sdl_gl_cleanup (context, window);

  puts ("...glutils main");
}
