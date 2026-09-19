//
// Created by cdemin on 9/10/26.
//

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <array>

#include "../include/main_utils.h"
#include "../include/structs.h"
#include "../include/loop.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define newline "\n"

void loop2D(std::vector<uint32_t>& buffer, BlackHole& hole, int pixelX, int pixelY, const int height, const int width, std::array<int, 4> backgroundColor) { // loop for pixel color assignments

    // normalize pixels into UV coordinates 0 through 1
    const double xCentered = static_cast<double>((2.0 * pixelX - width) / height);
    const double yCentered = static_cast<double>((2.0 * pixelY - height) / height);

    int pixelR = 255;
    int pixelG = 255;
    int pixelB = 255;
    const int pixelA = 255;

    Vec2 rayDir = {rayDir.x = xCentered, rayDir.y = yCentered};

    double length = std::sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y);

    if (length <= hole.radius) {
        // pixel is withing black hole radius
        pixelR = 0;
        pixelG = 0;
        pixelB = 0;
    } else if (length > hole.radius) {
        // pixel is outside radius, render background
        pixelR = 255;
        pixelG = 255;
        pixelB = 255;
    }

    SetPixel(buffer.data(), width, height,
        pixelX, pixelY, pixelR, pixelG, pixelB,
        255);
}

void loop3D(std::vector<uint32_t>& buffer, BlackHole& hole, int pixelX, int pixelY, const int height, const int width, std::array<int, 4> backgroundColor) {

    // normalize pixels into UV coordinates 0 through 1
    const double xCentered = static_cast<double>((2.0 * pixelX - width) / height);
    const double yCentered = static_cast<double>((2.0 * pixelY - height) / height);

    int pixelR = 255;
    int pixelG = 255;
    int pixelB = 255;
    const int pixelA = 255;

    Vec3 ray{.x=0.0, .y=0.0, .z=0.0};

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

    // convert back to rgba
    int pixelR = static_cast<int>((rayDir.x * 0.5 + 0.5) * 255);
    int pixelG = static_cast<int>((rayDir.y * 0.5 + 0.5) * 255);
    //int pixelB = i;
    int pixelB = 255;

    SetPixel(buffer.data(), width, height,
        pixelX, pixelY, pixelR, pixelG, pixelB,
        255);
}