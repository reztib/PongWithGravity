#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "game.h"
#include "graphics.h"

void print_directory_contents(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Contents of %s:\n", path);
    while ((entry = readdir(dp))) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (initSDL(&window, &renderer) != 0) {
        return 1;
    }

    // Print the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
        print_directory_contents("..");  // Print contents of parent directory
        print_directory_contents("../assets");  // Print contents of assets directory
        print_directory_contents("../assets/fonts");  // Print contents of fonts directory
    } else {
        perror("getcwd() error");
        return 1;
    }

    // Check if the font file exists
    const char *fontPath = "../assets/fonts/PressStart2P-Regular.ttf";
    if (access(fontPath, F_OK) != -1) {
        printf("Font file exists: %s\n", fontPath);
    } else {
        printf("Font file does not exist: %s\n", fontPath);
        cleanup(window, renderer, NULL);
        return 1;
    }

    TTF_Font *font = TTF_OpenFont(fontPath, 12);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        cleanup(window, renderer, NULL);
        return 1;
    }

    GameState gameState;
    initGame(&gameState);

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            handleEvents(&event, &running, &gameState);
        }

        updateGame(&gameState);
        render(renderer, &gameState, font);
    }

    cleanup(window, renderer, font);
    return 0;
}