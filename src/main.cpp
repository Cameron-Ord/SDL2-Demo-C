#include <SDL2/SDL.h>
#include "item.h"
int main(int argc, char ** arg)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window * win = SDL_CreateWindow("title", 30, 30, 600, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer * screen = SDL_CreateRenderer(win, -1, 0);

    item bob;
    bob.setRenderer(screen);
    bob.loadImage("dagoth.png");
    bool run = true;
    double ang = 0;
    int s = 30;

    while(run)
    {
        SDL_Event ev;
        while(SDL_PollEvent(&ev))
        {
            switch(ev.type)
            {
                case SDL_QUIT:
                run = false;
                break;
            }
        }

        bob.setSize(s,s);
        bob.draw(ang);
        SDL_RenderPresent(screen);
        ang++;
        s++;

    }

    SDL_DestroyWindow(win);
    SDL_Quit();

}
