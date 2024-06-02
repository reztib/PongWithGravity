#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"
#include "graphics.h"

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (initSDL(&window, &renderer) != 0) {
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("../assets/fonts/PressStart2P-Regular.ttf", 24);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        cleanup(window, renderer, NULL);
        return 1;
    }

    GameState gameState;
    initGame(&gameState);

    GameStateEnum gameStateEnum = STATE_START_SCREEN;

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (gameStateEnum == STATE_START_SCREEN) {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                    gameStateEnum = STATE_PLAYING;
                }
            } else {
                handleEvents(&event, &running, &gameState);
            }
        }

        if (gameStateEnum == STATE_START_SCREEN) {
            renderStartScreen(renderer, font);
        } else {
            updateGame(&gameState);
            render(renderer, &gameState, font);
        }
    }

    cleanup(window, renderer, font);
    return 0;
}