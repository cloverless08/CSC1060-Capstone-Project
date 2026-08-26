/*
 *      CSC1060 at FRCC
 *      Carrick De Min
 *      Capstone Project
 *      v0.3.3
 */

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cctype>
#include <array>
#include <random>
#include <string>

// local headers
#include "main_utils.h"

// ANSI color code macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
    // constants
    constexpr int STANDARD_RESOLUTION_WIDTH = 640;
    constexpr int STANDARD_RESOLUTION_HEIGHT = 480;
    constexpr int MOVING_RESOLUTION_HEIGHT = 320;
    constexpr int MOVING_RESOLUTION_WIDTH = 240;
    const std::array<std::string, 4> msgType = {"SYSTEM", "ERROR", "SETUP", "WARN"}; // strOut() helpful labels
    strOut("Constants Initialized.", msgType[2]);

    // variables
    bool running = true;
    double camDistance;
    double camPitch;
    double camYaw;
    strOut("Variables Initialized.", msgType[2]);

    strOut("This program is under development and may not function as expected.", msgType[3]);

    // structs
    struct Vec3 {
        double x;
        double y;
        double z;
    };
    strOut("Structs Initialized.", msgType[2]);

    // create canvas (pixel buffer) in memory
    uint32_t pixelBuffer[STANDARD_RESOLUTION_WIDTH * STANDARD_RESOLUTION_HEIGHT];
    strOut("Pixel Buffer Initialized.", msgType[2]);

    // structs required for sdl2
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    strOut("SDL2 Structs Initialized.", msgType[2]);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT, 0, &window, &renderer);
    //SDL_RenderSetScale(renderer, 1, 1);
    SDL_Event event;
    strOut("SDL2 Initialized.", msgType[2]);

    // clears screen to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_Delay(1000);
    
    // window loop
    while (running) {
        // poll all events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                //key presssssss
            }
        }

        // temp
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawLine(renderer, 0, 0, STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, STANDARD_RESOLUTION_WIDTH, 0, 0, STANDARD_RESOLUTION_HEIGHT);
        SDL_RenderPresent(renderer);
        SDL_Delay(25);
    }

    return 0;
}