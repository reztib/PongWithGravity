#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "graphics.h"

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (initSDL(&window, &renderer) != 0) {
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("../assets/fonts/PressStart2P-Regular.ttf", 12);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        cleanup(window, renderer, NULL);
        return 1;
    }

    GameState gameState;
    initGame(&gameState);

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            handleEvents(&event, &running, &gameState);
        }

        updateGame(&gameState);
        render(renderer, &gameState, font);
    }

    cleanup(window, renderer, font);
    return 0;
}