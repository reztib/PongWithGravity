#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"
#include "graphics.h"

int main() {
    // Initialize SDL window and renderer
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (initSDL(&window, &renderer) != 0) { // Check if initialization was successful
        return 1; // Return error code if initialization failed
    }

    // Load font for rendering text
    TTF_Font *font = TTF_OpenFont("../assets/fonts/PressStart2P-Regular.ttf", 24);
    if (font == NULL) { // Check if font loading was successful
        printf("TTF_OpenFont Error: %s\n", TTF_GetError()); // Print error message
        cleanup(window, renderer, font); // Clean up resources
        return 1; // Return error code
    }

    // Initialize game state
    GameState gameState;
    initGame(&gameState);

    // Define game state enum for managing game states
    GameStateEnum gameStateEnum = STATE_START_SCREEN;

    // Variable to control the game loop
    int running = 1;

    // SDL event structure for handling events
    SDL_Event event;

    // Main game loop
    while (running) {
        while (SDL_PollEvent(&event)) { // Poll SDL events
            if (gameStateEnum == STATE_START_SCREEN) { // Check if game is in start screen state
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) { // Check if Enter key is pressed
                    gameStateEnum = STATE_PLAYING; // Change game state to playing
                }
            } else { // Handle events during gameplay
                handleEvents(&event, &running, &gameState);
            }
        }

        if (gameStateEnum == STATE_START_SCREEN) { // Render start screen if game is in start screen state
            renderStartScreen(renderer, font);
        } else { // Update and render game during gameplay
            updateGame(&gameState);
            render(renderer, &gameState, font);
        }
    }

    cleanup(window, renderer, font); // Clean up resources
    return 0; // Return success code
}
