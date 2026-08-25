#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cctype>
#include <array>

// function for clean console output with labels
int strOut(const std::string msg = "Nothing to output (edit strOut() to fix)", std::string label = "standard") {
    if (label != "standard") {
        for (char &c : label) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); // changes string 'type' to all upper
        }
        std::cout << "[" + label + "] " << msg << std::endl; // output with label
    } else {
        std::cout << msg << std::endl; // output without label
    }

    return 0;
}

int main() {
    // constants
    const int WIDTH = 640;
    const int HEIGHT = 480;
    std::array<std::string, 4> msgType = {"SYSTEM", "ERROR", "SETUP", "WARN"}; // strOut() helpful labels
    strOut("Constants Initialized.", msgType[2]);

    // variables
    int var = 10;
    strOut("Variables Initialized.", msgType[2]);

    // create canvas (pixel buffer) in memory
    uint32_t pixelBuffer[WIDTH * HEIGHT];
    strOut("Pixel Buffer Initialized.", msgType[2]);

    // structs required for sdl2
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    strOut("SDL2 Structs Initialized.", msgType[2]);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    //SDL_RenderSetScale(renderer, 1, 1);
    strOut("SDL2 Initialized.", msgType[2]);

    // clears screen to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    return 0;
}