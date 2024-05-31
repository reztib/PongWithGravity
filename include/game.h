#ifndef GAME_H
#define GAME_H

#include <SDL.h>  // Include SDL header

// Define a structure to represent a game object (e.g., paddle, ball)
typedef struct {
    float x, y;            // Position of the object
    float width, height;   // Dimensions of the object
    float velocity_x, velocity_y;  // Velocity of the object
} GameObject;

// Function to initialize the game objects (paddle and ball)
void initGame(GameObject *paddle, GameObject *ball);

// Function to update the game logic (e.g., object positions, collisions)
void updateGame(GameObject *paddle, GameObject *ball);

// Function to handle events (e.g., user input, window events)
void handleEvents(SDL_Event *event, int *running, GameObject *paddle);

#endif // GAME_H
