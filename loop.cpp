//
// Created by cdemin on 9/10/26.
//

#include "loop.h"

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <array>
#include <random>
#include <string>
#include <cmath>
#include <cctype>
#include "main_utils.h"
#include "structs.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define newline "\n"

int loop(std::vector<uint32_t>& buffer, BlackHole& hole, int pixelX, int pixelY, const int height, const int width) { // loop for pixel color assignments
    // normalize pixels into UV coordinates 0 through 1
    const double xCentered = static_cast<double>((2 * pixelX - width) / height);
    const double yCentered = static_cast<double>((2 * pixelY - height) / height);

    int pixelR;
    int pixelG;
    int pixelB;
    int pixelA;

    Vec2 rayDir = {.x = xCentered, .y = yCentered};

    double length = std::sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y); length > 0.0001; // avoids NaN or division by zero at the centerpoint
    rayDir.x /= length;
    rayDir.y /= length;

    if (length <= hole.radius) {
        // pixel is withing black hole radius
        pixelR = 0;
        pixelG = 0;
        pixelB = 0;
    } else {
        // pixel is outside radius, render background
        pixelR = 255;
        pixelG = 255;
        pixelB = 255;
    }

    SetPixel(buffer.data(), width, height,
        pixelX, pixelY, pixelR, pixelG, pixelB,
        255);
}


void test_loop(std::vector<uint32_t>& buffer, int pixelX, int pixelY, const int height, const int width) { // old loop that draws a gradient as i was learning
    // normalize pixels into UV coordinates 0 sthrough 1
    const double u = static_cast<double>(pixelX) / height;
    const double v = static_cast<double>(pixelY) / width;

    Vec2 rayDir = {.x = u, .y = v};

    if (double length = std::sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y); length > 0.0001) { // avoids NaN or division by zero at the centerpoint
        rayDir.x /= length;
        rayDir.y /= length;
    }

    // de-normalize converts back into rgba
    int pixelR = static_cast<int>((rayDir.x * 0.5 + 0.5) * 255);
    int pixelG = static_cast<int>((rayDir.y * 0.5 + 0.5) * 255);
    //int pixelB = i;
    int pixelB = 255;

    SetPixel(buffer.data(), width, height,
        pixelX, pixelY, pixelR, pixelG, pixelB,
        255);
}