#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cctype>
#include <array>
#include <random>

// ANSI Color Code Macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// function for clean, dynamic console output with labels
static int strOut(const std::string& msg = "Nothing to output (edit strOut() to fix)", std::string label = "standard") {
    if (label != "standard") {
        for (char &c : label) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); // changes string 'label' to all upper
        }
        if (label == "ERROR") {
            std::cout << RED << "[" + label + "] " << msg << RESET << std::endl; // output with label
        } else if (label == "WARN") {
            std::cout << YELLOW << "[" + label + "] " << msg << RESET << std::endl; // output with label
        } else if (label == "SETUP") {
            std::cout << CYAN << "[" + label + "] " << msg << RESET << std::endl; // output with label
        }
    } else {
        std::cout << RESET << msg << RESET<< std::endl; // output without label
    }

    return 0;
}

int main() {
    // constants
    constexpr int WIDTH = 640;
    constexpr int HEIGHT = 480;
    const std::array<std::string, 4> msgType = {"SYSTEM", "ERROR", "SETUP", "WARN"}; // strOut() helpful labels
    strOut("Constants Initialized.", msgType[2]);

    // variables
    bool running = true;
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
    SDL_Event event;
    strOut("SDL2 Initialized.", msgType[2]);

    // clears screen to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // window loop
    while (running) {
        // poll all events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // temp
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, 0, WIDTH, HEIGHT);
        SDL_RenderDrawLine(renderer, WIDTH, 0, 0, HEIGHT);
        SDL_RenderPresent(renderer);
        SDL_Delay(25);
    }

    return 0;
}