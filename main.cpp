/* ========================================================================== */
//  CSC1060 at FRCC
//  Carrick De Min
//  Capstone Project
//  v0.4.0
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

// ANSI color code and other macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#define newline "\n"

// global constants
constexpr int STANDARD_RESOLUTION_WIDTH = 640;
constexpr int STANDARD_RESOLUTION_HEIGHT = 480;
constexpr int MOVING_RESOLUTION_HEIGHT = 320;
constexpr int MOVING_RESOLUTION_WIDTH = 240;
const std::array<std::string, 4> msgType = {"SYSTEM", "ERROR", "SETUP", "WARN"}; // strOut() helpful labels

// global structs
struct Vec3 {       // for 3d space
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

struct Vec2 {       // for 2D space
    double x = 0.0;
    double y = 0.0;
};

struct  Engine {

};

struct BlackHole {
    Vec2 position;
    double mass;
    double radius;
};

struct Ray {
    double x; double y;
    Vec2 direction;

};

int main() {

    TerminalInfoHeader();
    SDL_Delay(500);

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

    StrOut("Local Variables Initialized.", msgType[2]);


    //intial warnings and output
    StrOut("CSC1060 - Capstone Project", "info");
    StrOut("By Carrick De Min, Fall 2026", "info");
    StrOut("This program is under development and may not function as expected.", msgType[3]);


    // initialize sdl2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        StrOut(std::string("SDL_Init failed: ") + SDL_GetError(), msgType[1]);
        return 1;
    }

    SDL_Event event;

    StrOut("SDL2 Initialized.", msgType[2]);


    // structs required for sdl2
    SDL_Window* window = SDL_CreateWindow(
        "CSC1060 Capstone Project",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT,
        SDL_WINDOW_SHOWN
        );
    if (!window) {
        StrOut(std::string("CreateWindow failed: ") + SDL_GetError(), msgType[1]);
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );
    if (!renderer) {
        StrOut(std::string("CreateRenderer failed: ") + SDL_GetError(), msgType[1]);
        return 1;
    }

    SDL_Texture* pixelBufferTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888, // 32-bit format for 8 bits per channel
        SDL_TEXTUREACCESS_STREAMING, // allows fast cpu to gpu updates
        STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT // screen resolution
        );
    if (!pixelBufferTexture) {
        StrOut(std::string("CreateTexture failed: ") + SDL_GetError(), msgType[1]);
        return 1;
    }

    StrOut("SDL2 Structs Initialized.", msgType[2]);

    // create canvas pixel buffer in memory
    //auto* pixelBuffer = new uint32_t[STANDARD_RESOLUTION_WIDTH * STANDARD_RESOLUTION_HEIGHT] ;
    std::vector<uint32_t> pixelBuffer(STANDARD_RESOLUTION_WIDTH * STANDARD_RESOLUTION_HEIGHT, 0);
    int bufferStart = y * STANDARD_RESOLUTION_WIDTH + x;
    pixelBuffer[bufferStart] = (r << 24U) | (g << 16U) | (b << 8U) | a;
    StrOut("Pixel Buffer Initialized.", msgType[2]);


    unsigned int i = 0;

    // window loop
    StrOut("Starting Program Loop...", msgType[0]);
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

        // update pixel buffer
         for (int py = 200; py < 280; py++) {
            for (int px = 280; px < 360; px++) {
                SetPixel(pixelBuffer.data(), STANDARD_RESOLUTION_WIDTH, STANDARD_RESOLUTION_HEIGHT, px, py, r, g, b, a);
            }
        }


        // update render texture (pixel buffer)
        SDL_UpdateTexture(
            pixelBufferTexture,
            nullptr,                   // NULL updates the entire texture
            pixelBuffer.data(),            // Pointer to our raw CPU buffer
            STANDARD_RESOLUTION_WIDTH * sizeof(uint32_t) // Pitch: number of bytes in one row of pixels
        );

        // render loop
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, pixelBufferTexture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(25);

        std::cout << i << newline;
        i += 1;
    }
    StrOut("Closing Program Loop...", msgType[0]);

    // clean up memory on app close
    delete[] pixelBuffer.data();
    StrOut("Pixel Buffer Deleted", msgType[3]);

    SDL_DestroyTexture(pixelBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    StrOut("SDL Structs Deleted", msgType[3]);

    return 0;
}
