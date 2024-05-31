#include <string.h>
#include "graphics.h"

int initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create SDL window
    *window = SDL_CreateWindow("Pong with Gravity", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Create SDL renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        SDL_DestroyWindow(*window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() != 0) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return -1;
    }

    return 0;
}

void render(SDL_Renderer *renderer, GameState *gameState, TTF_Font *font) {
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render paddle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect paddleRect = { (int)gameState->paddle.x, (int)gameState->paddle.y, (int)gameState->paddle.width, (int)gameState->paddle.height };
    SDL_RenderFillRect(renderer, &paddleRect);

    // Render ball
    SDL_Rect ballRect = { (int)gameState->ball.x, (int)gameState->ball.y, (int)gameState->ball.width, (int)gameState->ball.height };
    SDL_RenderFillRect(renderer, &ballRect);

    // Render score
    renderScore(renderer, font, gameState->score);

    // Present the renderer
    SDL_RenderPresent(renderer);
}

void renderStartScreen(SDL_Renderer *renderer, TTF_Font *font) {
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Set color for start screen text
    SDL_Color startScreenColor = {255, 255, 255};

    // Render start screen text
    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, "Welcome to Pong With Gravity! \n Press Enter to Start", startScreenColor, 0);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface);
    SDL_Rect renderQuad = {320 - text_width / 2, 240 - text_height / 2, text_width, text_height};
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(renderer);
}

void renderScore(SDL_Renderer *renderer, TTF_Font *font, int score) {
    // Render score text
    char scoreText[100];
    sprintf(scoreText, "Score: %d", score);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface);
    SDL_Rect renderQuad = {10, 10, text_width, text_height};
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
    SDL_DestroyTexture(texture);
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font) {
    // Clean up SDL_ttf
    TTF_CloseFont(font);
    TTF_Quit();

    // Clean up SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
