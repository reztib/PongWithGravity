cmake_minimum_required(VERSION 3.10)
project(PongWithGravity C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Find the SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include directories
include_directories(include)

# Add the source files
set(SOURCE_FILES
        src/main.c
        src/game.c
        src/graphics.c
        src/input.c
        include/game.h
        include/graphics.h
        include/input.h)

# Add the executable target
add_executable(PongWithGravity ${SOURCE_FILES})

# Link SDL2 library
target_link_libraries(PongWithGravity ${SDL2_LIBRARIES})
