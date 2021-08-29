/*
header.h
-----------
Role: prototypes of game.c functions
*/

#ifndef DEF_HEADER
#define DEF_HEADER

#include "constants.h"

    void SDL_ExitWithError(const char *message, SDL_Window *window, SDL_Renderer *renderer);
    int setColor(SDL_Renderer **renderer, const struct color color);
    int colorBlock(SDL_Renderer **renderer,SDL_Event event,SDL_Rect rect[][NB_BLOCKS_HEIGHT]);
    int doGrid(SDL_Renderer **renderer,SDL_Rect rect[][NB_BLOCKS_HEIGHT]);

#endif