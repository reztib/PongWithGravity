#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;       // Pointer to the SDL window
    SDL_Renderer *renderer = NULL;   // Pointer to the SDL renderer

    // Initialize SDL, create a window and renderer
    if (initSDL(&window, &renderer) != 0) {
        return 1;   // Return 1 if initialization fails
    }

    GameObject paddle, ball;  // Create paddle and ball game objects
    initGame(&paddle, &ball); // Initialize the game objects

    int running = 1;          // Variable to control the game loop
    SDL_Event event;          // SDL event structure to handle events

    // Main game loop
    while (running) {
        // Poll and handle events
        while (SDL_PollEvent(&event)) {
            handleEvents(&event, &running, &paddle); // Handle user input and events
        }

        updateGame(&paddle, &ball); // Update game logic

        // Clear the screen with black color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render(renderer, &paddle, &ball); // Render the game objects

        SDL_RenderPresent(renderer); // Present the updated screen
    }

    cleanup(window, renderer); // Clean up and quit SDL
    return 0; // Return 0 on successful exit
}
