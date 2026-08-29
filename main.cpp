/* ========================================================================== */
//  CSC1060 at FRCC
//  Carrick De Min
//  Capstone Project
//  v0.3.3
/* ========================================================================== */

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

// global constants
constexpr int STANDARD_RESOLUTION_WIDTH = 640;
constexpr int STANDARD_RESOLUTION_HEIGHT = 480;
constexpr int MOVING_RESOLUTION_HEIGHT = 320;
constexpr int MOVING_RESOLUTION_WIDTH = 240;
const std::array<std::string, 4> msgType = {"SYSTEM", "ERROR", "SETUP", "WARN"}; // strOut() helpful labels

// global structs
struct Vec3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

void loop(Vec3 ray) {
    // call for every tick of simulation, empty for now
    std::cout << ray.x << std::endl;
    std::cout << ray.y << std::endl;
    std::cout << ray.y << std::endl;
};

int main() {

    // variables
    bool running = true;
    double camDistance;
    double camPitch;
    double camYaw;
    Vec3 ray;
    strOut("Local Variables Initialized.", msgType[2]);

    strOut("This program is under development and may not function as expected.", msgType[3]);

    // structs
    /*struct Vec3 {
        double x;
        double y;
        double z;
    };
    strOut("Structs Initialized.", msgType[2]);
    */ //moved outside of func main()

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
        int randomX1 = randInt(0, STANDARD_RESOLUTION_WIDTH);
        int randomX2 = randInt(0, STANDARD_RESOLUTION_WIDTH);
        int randomY1 = randInt(0, STANDARD_RESOLUTION_HEIGHT);
        int randomY2 = randInt(0, STANDARD_RESOLUTION_HEIGHT);
        int randomColorR = randInt(0,255);
        int randomColorG = randInt(0,255);
        int randomColorB= randInt(0,255);

        SDL_SetRenderDrawColor(renderer, randomColorR, randomColorG, randomColorB, 255);
        SDL_RenderDrawLine(renderer, randomX1, randomY1, randomX2, randomY2);
        SDL_RenderPresent(renderer);
        SDL_Delay(250);

    }

    return 0;
}
