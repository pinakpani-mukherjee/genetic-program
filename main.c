#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// macro for writing errors to terminal for functions with ints as return values
int scc(int code)
{
    if (code < 0)
    {
        fprintf(stderr, "SDL Error :%s\n", SDL_GetError());
        exit(1);
    }
    return code;
}

// macro for writing errors to terminal for functions with pointers as return values
void *scp(void *ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "SDL Error :%s\n", SDL_GetError());
        exit(1);
    }
    return ptr;
}

int main(int argc, char const *argv[])
{
    // SDL can fail so we have to do a check here
    scc(SDL_Init(SDL_INIT_VIDEO));

    SDL_Window *const window = scp(SDL_CreateWindow("Hunger games", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE));

    if (window == NULL)
    {
        printf("SDL Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *const renderer = scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));
    int quit = 0;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1;
                break;

            default:
                break;
            }
        }
        scc(SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255));
        scc(SDL_RenderClear(renderer));
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}
