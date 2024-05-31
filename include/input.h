#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "game.h"

// Function to handle key down events
void handleKeyDown(SDL_Keycode key, GameObject *paddle);

// Function to handle key up events
void handleKeyUp(SDL_Keycode key, GameObject *paddle);

#endif // INPUT_H
