#include "graphics.h"
#include "config.h"

int initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }

    *window = SDL_CreateWindow("Pong with Gravity", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI);
    if (*window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        SDL_DestroyWindow(*window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the playing field boundaries
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect fieldRect = { (int)((SCREEN_WIDTH - PLAYING_FIELD_WIDTH) / 2.0f), (int)((SCREEN_HEIGHT - PLAYING_FIELD_HEIGHT) / 2.0f), (int)PLAYING_FIELD_WIDTH, (int)PLAYING_FIELD_HEIGHT };
    SDL_RenderDrawRect(renderer, &fieldRect);

    // Draw the paddle
    SDL_Rect paddleRect = { (int)(gameState->paddle.x + fieldRect.x), (int)(gameState->paddle.y + fieldRect.y), (int)gameState->paddle.width, (int)gameState->paddle.height };
    SDL_RenderFillRect(renderer, &paddleRect);

    // Draw the ball
    SDL_Rect ballRect = { (int)(gameState->ball.x + fieldRect.x), (int)(gameState->ball.y + fieldRect.y), (int)gameState->ball.width, (int)gameState->ball.height };
    SDL_RenderFillRect(renderer, &ballRect);

    // Render score
    renderScore(renderer, font, gameState->score);

    SDL_RenderPresent(renderer);
}

void renderStartScreen(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Color startScreenColor = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, "Welcome to Pong With Gravity! \n Press Enter to Start", startScreenColor, 0);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface);
    SDL_Rect renderQuad = { (int)(SCREEN_WIDTH / 2.0f - text_width / 2.0f), (int)(SCREEN_HEIGHT / 2.0f - text_height / 2.0f), text_width, text_height };
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(renderer);
}

void renderScore(SDL_Renderer *renderer, TTF_Font *font, int score) {
    char scoreText[100];
    sprintf(scoreText, "Score: %d", score);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface);
    SDL_Rect renderQuad = {10, 1055, text_width, text_height};
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
    SDL_DestroyTexture(texture);
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font) {
    if (font) TTF_CloseFont(font);
    TTF_Quit();
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}