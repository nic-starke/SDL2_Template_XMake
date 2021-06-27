#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "Utils/Config.h"
#include "Utils/Defaults.h"
#include "Utils/Log.h"

#define Exit_SDLError()                                                                            \
  do {                                                                                             \
    Log_SDLError();                                                                                \
    exit(EXIT_FAILURE);                                                                            \
  } while (0);

SDL_DisplayMode* pDisplayMode   = NULL;
SDL_Window*      pWindow        = NULL;
SDL_Surface*     pWindowSurface = NULL;

static void
DeInitialise(void) {
  SDL_FreeSurface(pWindowSurface);
  pWindowSurface = NULL;

  SDL_DestroyWindow(pWindow);
  pWindow = NULL;
}

/** @brief To be registered with atexit(). */
static void
ExitHandler(void) {
  printf("%s\r\n", __func__);
  DeInitialise();
  SDL_Quit();
}

static void
Initialise(void) {
  atexit(ExitHandler);

  if (SDL_Init(SDL_INIT_VIDEO) != 0) { Exit_SDLError(); }

  if (SDL_GetCurrentDisplayMode(0, pDisplayMode) != 0) {
    Log_SDLError();
    Log_Error("Setting display mode variables to defaults\r\n");
  };

  pWindow = SDL_CreateWindow(PROJECT_NAME,
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             DEFAULT_WINDOW_WIDTH,
                             DEFAULT_WINDOW_HEIGHT,
                             DEFAULT_WINDOW_FLAGS);

  if (!pWindow) {
    Exit_SDLError();
  } else {
    pWindowSurface = SDL_GetWindowSurface(pWindow);
  }
}

int
main(int argc, char* argv[]) {
  bool quit = false;
  // Log("Starting application version %s\r\n", VERSION);
  Initialise();

  while (!quit) {
    SDL_Delay(5000);
    quit = true;
  }

  Log("Stopping application\r\n");
  exit(EXIT_SUCCESS);
}