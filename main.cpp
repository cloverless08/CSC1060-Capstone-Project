/* ========================================================================== */
//  CSC1060 at FRCC
//  Carrick De Min
//  Capstone Project
//  v0.3.3
/* ========================================================================== */

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <array>
#include <random>
#include <string>
#include <cmath>
#include <cctype>

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

std::vector<double> loopCalculation(Vec3 ray) {
    // call for every tick of simulation, temp for now
    ray.x = randInt(0,STANDARD_RESOLUTION_HEIGHT);
    ray.y = randInt(0,STANDARD_RESOLUTION_HEIGHT);
    ray.z = randInt(0,STANDARD_RESOLUTION_HEIGHT);
    return {ray.x, ray.y, ray.z};
};

int main() {

    // variables
    bool running = true;
    double camDistance;
    double camPitch;
    double camYaw;

    Vec3 ray;

    int x = 0;
    int y = 0;
    int r = 255; // color red
    int g = 255; // color green
    int b = 255; // color blue
    int a = 255; // color alpha (transparency)

    strOut("Local Variables Initialized.", msgType[2]);

    //intial warnings and output
    strOut("CSC1060 - Capstone Project", "info");
    strOut("By Carrick De Min, Fall 2026", "info");
    strOut("This program is under development and may not function as expected.", msgType[3]);

    // structs required for sdl2
    SDL_Window* window = SDL_CreateWindow(
        "Pixel Buffer Demo",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT,
        SDL_WINDOW_SHOWN
        );
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );
    SDL_Texture* pixelBufferTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888, // 32-bit format for 8 bits per channel
        SDL_TEXTUREACCESS_STREAMING, // allows fast cpu to gpu updates
        STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT // screen resolution
        );
    strOut("SDL2 Structs Initialized.", msgType[2]);

    // create canvas pixel buffer in memory
    //auto* pixelBuffer = new uint32_t[STANDARD_RESOLUTION_WIDTH * STANDARD_RESOLUTION_HEIGHT] ;
    std::vector<uint32_t> pixelBuffer(STANDARD_RESOLUTION_WIDTH * STANDARD_RESOLUTION_WIDTH, 0);
    int bufferStart = y * STANDARD_RESOLUTION_WIDTH + x;
    pixelBuffer[bufferStart] = (r << 24U) | (g << 16U) | (b << 8U) | a;
    strOut("Pixel Buffer Initialized.", msgType[2]);

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

        //loop variables
        std::vector<double> xyz = loopCalculation(ray);
        std::vector<double> xyz2 = loopCalculation(ray);

        // update pixel buffer
        SetPixel(
            pixelBuffer.data(),
            STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT,
            (STANDARD_RESOLUTION_WIDTH / 2), (STANDARD_RESOLUTION_HEIGHT / 2),
            r, g, b, a
            );

        // update render texture (pixel buffer)
        SDL_UpdateTexture(
            pixelBufferTexture,
            nullptr,                   // NULL updates the entire texture
            pixelBuffer.data(),            // Pointer to our raw CPU buffer
            STANDARD_RESOLUTION_WIDTH * sizeof(uint32_t) // Pitch: number of bytes in one row of pixels
        );

        // render loop
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, pixelBufferTexture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);

    }

    // clean up memory on app close
    //delete[] pixelBuffer;
    strOut("Pixel Buffer Deleted", msgType[3]);

    SDL_DestroyTexture(pixelBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    strOut("SDL Structs Deleted", msgType[3]);

    return 0;
}
