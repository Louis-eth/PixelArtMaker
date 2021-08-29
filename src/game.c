/*
game.c
----------
Role: game functions
*/

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "constants.h"

void SDL_ExitWithError(const char *message, SDL_Window *window, SDL_Renderer *renderer){
    SDL_Log("ERROR : %s > %s\n", message, SDL_GetError());
    if (window != NULL)
        SDL_DestroyWindow(window);
    if (renderer != NULL)
        SDL_DestroyRenderer(renderer);
    SDL_Quit();
    exit(EXIT_FAILURE);
}

int setColor(SDL_Renderer **renderer, const struct color color){
    SDL_SetRenderDrawColor(*renderer,color.r,color.g,color.b,SDL_ALPHA_OPAQUE); 
    return EXIT_SUCCESS;
}
int colorBlock(SDL_Renderer **renderer,SDL_Event event,SDL_Rect rect[][NB_BLOCKS_HEIGHT]){
    SDL_RenderFillRect(*renderer,&rect[event.button.x / BLOCK_SIZE][event.button.y / BLOCK_SIZE]);
    setColor(renderer, LINES);
    SDL_RenderDrawRect(*renderer,&rect[event.button.x / BLOCK_SIZE][event.button.y / BLOCK_SIZE]);

    return EXIT_SUCCESS;
}
int doGrid(SDL_Renderer **renderer,SDL_Rect rect[][NB_BLOCKS_HEIGHT]){
    setColor(renderer, BACKGROUND);
    SDL_RenderClear(*renderer);
    int x = 0;
    int y = 0;

    for (int i = 0; i < WH_SIZE; i += BLOCK_SIZE)
    {
        for (int j = 0; j < WH_SIZE; j += BLOCK_SIZE)
        {
            rect[x][y].x = j;
            rect[x][y].y = i;
            rect[x][y].w = BLOCK_SIZE;
            rect[x][y].h = BLOCK_SIZE;

            if (x < NB_BLOCKS_WIDTH)
                x++;
            if (x == NB_BLOCKS_WIDTH)
            {
                x = 0;
                y++;
            }
        }
    }
    setColor(renderer, LINES);
    SDL_RenderDrawRects(*renderer, *rect, COUNT);

    return EXIT_SUCCESS;
}