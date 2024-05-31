# Pong with Gravity

This project is a simple Pong game with added gravity, developed using SDL2. The game includes a paddle and a ball that moves under the influence of gravity, and the player controls the paddle to keep the ball in play.

## Table of Contents

- [Pong with Gravity](#pong-with-gravity)
    - [Table of Contents](#table-of-contents)
    - [Features](#features)
    - [Requirements](#requirements)
    - [Installation](#installation)
    - [Usage](#usage)
    - [Controls](#controls)
    - [Project Structure](#project-structure)
    - [Contributing](#contributing)
    - [License](#license)
    - [Acknowledgements](#acknowledgements)

## Features

- Basic Pong gameplay with gravity.
- Control the paddle to keep the ball in play.
- Simple and clean code structure for easy understanding and modification.

## Requirements

- SDL2 library
- CMake
- GCC or any other C compiler

## Installation

### SDL2 Installation

#### On Ubuntu:

```sh
sudo apt-get update
sudo apt-get install libsdl2-dev
```

#### On macOS (using Homebrew):

```sh
brew install sdl2
```

### Project Setup

1. Clone the repository:

```sh
git clone https://github.com/felixBtzr/PongWithGravity.git
cd PongWithGravity
```

2. Create a build directory and run CMake:

```sh
mkdir build
cd build
cmake ..
make
```

## Usage

After building the project, you can run the game using the following command in the `build` directory:

```sh
./PongWithGravity
```

## Controls

- `A` or `Left Arrow`: Move paddle left
- `D` or `Right Arrow`: Move paddle right

## Project Structure

```
gravity-pong/
├── include/
│   ├── game.h
│   ├── graphics.h
│   └── input.h
├── src/
│   ├── main.c
│   ├── game.c
│   ├── graphics.c
│   └── input.c
├── assets/
│   ├── fonts/
        └── PressStart2P-Regular.ttf
│   ├── sounds/
│   └── textures/
├── CMakeLists.txt
└── README.md
```

- `include/`: Contains the header files for the game.
- `src/`: Contains the source files for the game logic, graphics, and input handling.
- `assets/`: Directory for game assets like fonts, sounds, and textures (currently empty but can be used for future enhancements).
- `CMakeLists.txt`: The CMake configuration file.
- `README.md`: This file.

## Contributing

Contributions are welcome! If you have any improvements or suggestions, feel free to fork the repository and create a pull request.

1. Fork the repository.
2. Create your feature branch: `git checkout -b feature/my-feature`.
3. Commit your changes: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature/my-feature`.
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/felixBtzr/PongWithGravity/blob/master/LICENSE.md) file for details.

## Acknowledgements

- [SDL2](https://www.libsdl.org/) for providing a powerful and easy-to-use library for multimedia and game development.
- CodeMan38 for designing [this](https://fonts.google.com/specimen/Press+Start+2P) awesome font!