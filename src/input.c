#include "input.h"

void handleKeyPressed(SDL_Keycode key, GameObject *paddle) {
    switch (key) {
        // Move paddle left when 'A' or Left Arrow is pressed
        case SDLK_a:
        case SDLK_LEFT:
            paddle->velocity_x = -5.0f;
            break;
            // Move paddle right when 'D' or Right Arrow is pressed
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 5.0f;
            break;
            // Move paddle up when 'W' or Up Arrow is pressed
        case SDLK_w:
        case SDLK_UP:
            paddle->velocity_y = -5.0f;
            break;
            // Move paddle down when 'S' or Down Arrow is pressed
        case SDLK_s:
        case SDLK_DOWN:
            paddle->velocity_y = 5.0f;
            break;
        default:
            break;
    }
}

void handleKeyReleased(SDL_Keycode key, GameObject *paddle) {
    switch (key) {
        // Stop moving paddle if 'A' or Left Arrow is released
        case SDLK_a:
        case SDLK_LEFT:
            // Stop moving paddle if 'D' or Right Arrow is released
        case SDLK_d:
        case SDLK_RIGHT:
            paddle->velocity_x = 0.0f;
            break;
            // Stop moving paddle if 'W' or Up Arrow is released
        case SDLK_w:
        case SDLK_UP:
            // Stop moving paddle if 'S' or Down Arrow is released
        case SDLK_s:
        case SDLK_DOWN:
            paddle->velocity_y = 0.0f;
            break;
        default:
            break;
    }
}
