cmake_minimum_required(VERSION 3.10)
project(PongWithGravity C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Find the SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find the SDL2_ttf library
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

# Include directories
include_directories(include)

# Add the source files
set(SOURCE_FILES
        src/main.c
        src/game.c
        src/graphics.c
        src/input.c
        src/config.c)

# Add the executable target
add_executable(PongWithGravity ${SOURCE_FILES})

# Link SDL2 and SDL2_ttf libraries
target_link_libraries(PongWithGravity SDL2 SDL2_ttf)
