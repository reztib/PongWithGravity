#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"
#include "graphics.h"

int main() {
    // Initialize SDL window and renderer
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Initialize SDL and check for errors
    if (initSDL(&window, &renderer) != 0) {
        return 1;
    }

    // Load the font for rendering text
    TTF_Font *font = TTF_OpenFont("../assets/fonts/PressStart2P-Regular.ttf", 24);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        cleanup(window, renderer, NULL);
        return 1;
    }

    // Initialize the game state
    GameState gameState;
    initGame(&gameState);

    // Set the initial game state to start screen
    GameStateEnum gameStateEnum = STATE_START_SCREEN;

    // Flag to control the main loop
    int running = 1;
    SDL_Event event;

    // Render the start screen if the game is in the start screen state
    if (gameStateEnum == STATE_START_SCREEN) {
        renderStartScreen(renderer, font);
    }

    // Main loop
    while (running) {
        // Process events
        while (SDL_PollEvent(&event)) {
            // Check if the game is in the start screen state
            if (gameStateEnum == STATE_START_SCREEN) {
                // Check for key press to start the game
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                    gameStateEnum = STATE_PLAYING;
                }
            } else {
                // Handle events during gameplay
                handleEvents(&event, &running, &gameState);
            }
        }

        // Update and render the game if not in the start screen state
        if (gameStateEnum != STATE_START_SCREEN) {
            updateGame(&gameState);
            render(renderer, &gameState, font);
        }
    }

    // Clean up resources
    cleanup(window, renderer, font);
    return 0;
}
