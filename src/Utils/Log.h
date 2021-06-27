#ifndef LOG_H
#define LOG_H

#include "SDL2/SDL_error.h"

#if defined(DEBUG)
#define LOG_ACTIVE (1)
#else
#define LOG_ACTIVE (0)
#endif

#define Log_SDLError()                                                                             \
  do {                                                                                             \
    if (LOG_ACTIVE)                                                                                \
      fprintf(stderr, "%s:%d:%s(): \r\n%s\r\n", __FILE__, __LINE__, __func__, SDL_GetError());     \
  } while (0)

#define Log_Error(fmt, ...)                                                                        \
  do {                                                                                             \
    if (LOG_ACTIVE)                                                                                \
      fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__);            \
  } while (0)

#define Log(fmt, ...)                                                                              \
  do {                                                                                             \
    if (LOG_ACTIVE) fprintf(stdout, fmt, ##__VA_ARGS__);                                           \
  } while (0)

#endif