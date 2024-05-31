#include "graphics.h"

// Initialize SDL, create a window and a renderer
int initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1; // Return -1 on failure
    }

    // Create an SDL window
    *window = SDL_CreateWindow("Pong with Gravity", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit(); // Quit SDL if window creation fails
        return -1; // Return -1 on failure
    }

    // Create an SDL renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        SDL_DestroyWindow(*window); // Destroy the window if renderer creation fails
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit(); // Quit SDL if renderer creation fails
        return -1; // Return -1 on failure
    }

    return 0; // Return 0 on success
}

// Render the game objects (paddle and ball)
void render(SDL_Renderer *renderer, GameObject *paddle, GameObject *ball) {
    // Set the drawing color to white (RGBA)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Define the paddle's rectangle and render it
    SDL_Rect paddleRect = { (int)paddle->x, (int)paddle->y, (int)paddle->width, (int)paddle->height };
    SDL_RenderFillRect(renderer, &paddleRect);

    // Define the ball's rectangle and render it
    SDL_Rect ballRect = { (int)ball->x, (int)ball->y, (int)ball->width, (int)ball->height };
    SDL_RenderFillRect(renderer, &ballRect);
}

// Clean up and quit SDL
void cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer); // Destroy the renderer
    SDL_DestroyWindow(window); // Destroy the window
    SDL_Quit(); // Quit SDL
}
