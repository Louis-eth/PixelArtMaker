/*
main.c
-----------
* Made by https://github.com/Louiss-exe *
----------
Role: main function of the program
----------
compil : gcc src/*.c -o bin/PIXEL_ART_MAKER -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
*/

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "constants.h"

int main(int argc, char **argv)
{

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Init Video", window, renderer);
    
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Create Window and Renderer", window, renderer);
    
    SDL_Surface *icon = IMG_Load("src/icon.png");
    SDL_SetWindowIcon(window,icon);
    SDL_FreeSurface(icon);
    SDL_SetWindowTitle(window,"PIXEL ART MAKER");


    SDL_Rect rect[NB_BLOCKS_WIDTH][NB_BLOCKS_HEIGHT];
    doGrid(&renderer,rect);

    struct color CHOSEN_COLOR = BLUE;
    SDL_bool program_launched = SDL_TRUE;
    SDL_bool clic[2] = {SDL_FALSE, SDL_FALSE};
    SDL_Event event;
    while (program_launched)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            program_launched = SDL_FALSE;
            break;

        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                setColor(&renderer,CHOSEN_COLOR);
                colorBlock(&renderer,event,rect);
                clic[LEFT] = SDL_TRUE;
                break;

            case SDL_BUTTON_RIGHT:
                setColor(&renderer,BACKGROUND);
                colorBlock(&renderer,event,rect);
                clic[RIGHT] = SDL_TRUE;
                break;
            }
        break;

        case SDL_MOUSEBUTTONUP:
            switch (event.button.button) 
            {
            case SDL_BUTTON_LEFT:
                clic[LEFT] = SDL_FALSE;
                break;
            case SDL_BUTTON_RIGHT:
                clic[RIGHT] = SDL_FALSE;
                break;
            }
        break;

        case SDL_MOUSEMOTION:
            if (clic[LEFT] == SDL_TRUE)
            {
                setColor(&renderer,CHOSEN_COLOR);
                colorBlock(&renderer,event,rect);
            }
            if (clic[RIGHT] == SDL_TRUE)
            {
                setColor(&renderer,BACKGROUND);
                colorBlock(&renderer,event,rect);
            }
        break;

        case SDL_KEYDOWN:         
            switch(event.key.keysym.sym){    
                case SDLK_1: CHOSEN_COLOR = BLUE;break;
                case SDLK_2: CHOSEN_COLOR = PURPLE;break;
                case SDLK_3: CHOSEN_COLOR = RED;break;
                case SDLK_4: CHOSEN_COLOR = GREEN;break;
                case SDLK_5: CHOSEN_COLOR = YELLOW;break;
                case SDLK_6: CHOSEN_COLOR = ORANGE;break;
                case SDLK_7: CHOSEN_COLOR = GREY;break;

                case SDLK_c: doGrid(&renderer,rect);break;
            }
        break;
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}