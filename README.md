# Snake-Game-SDL2

## Description

This repository consists of a recreation of the classic game: Snake. The purpose of this project is to familiarise myself with more low level concepts that happen within the computer when programming, hence the usage of C++. Additionally, uses the SDL2 library for graphics.

## Instructions

To open this project in Visual Studio, you will need the additional include and library dependancies from the SDL2 library. These include:

- SDL2
- SDL2_image
- SDL2_ttf

Install these and create an include folder within the project directory with the header files (for include files) and a lib containing the x64 and x86 libraries (this project was made and debugged using x64 so folder by default used is $(ProjectDir)\lib\x64)

## Preview

![GIF of snake game running](snake-game-preview.gif)

## Known Issues / Bugs

- Visual Glitch when new body of snake is added
- Game may not fail when new body of snake is added as the head moves out of bounds
- Chance that the apple spawns in a location that is covered by the snake body

## Credits

Visual Assets: https://opengameart.org/content/snake-game-assets
