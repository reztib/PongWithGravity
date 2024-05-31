#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>  // Include SDL header for SDL functionalities
#include <SDL2/SDL_ttf.h>  // Include SDL_ttf header for font rendering

// Define a structure to represent a game object (e.g., paddle, ball)
typedef struct {
    float x, y;  // Position of the object
    float width, height;  // Dimensions of the object
    float velocity_x, velocity_y;  // Velocity of the object
} GameObject;

// Define a structure to represent the overall game state
typedef struct {
    GameObject paddle;  // Paddle game object
    GameObject ball;  // Ball game object
    int score;  // Player's score
} GameState;

// Define an enumeration for different game states
typedef enum {
    STATE_START_SCREEN,  // State for the start screen
    STATE_PLAYING,  // State for the playing mode
} GameStateEnum;

// Function to initialize the game objects (paddle and ball)
void initGame(GameState *gameState);

// Function to update the game logic (e.g., object positions, collisions)
void updateGame(GameState *gameState);

// Function to handle events (e.g., user input, window events)
void handleEvents(SDL_Event *event, int *running, GameState *gameState);

// Function to render the start screen
void renderStartScreen(SDL_Renderer *renderer, TTF_Font *font);

// Function to render the game objects (paddle, ball) and score
void render(SDL_Renderer *renderer, GameState *gameState, TTF_Font *font);

// Function to clean up SDL resources (window, renderer, font)
void cleanup(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font);

#endif // GAME_H
