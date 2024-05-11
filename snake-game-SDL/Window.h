#pragma once

#include <SDL.h>
#include <iostream>

class Window {
public:
    Window();
    ~Window();
    bool init();
    void eventLoop();

private:
    SDL_Window* window;
};
