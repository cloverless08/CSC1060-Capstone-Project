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

int loop() {
    return 0;
}

void test_loop(std::vector<uint32_t>& buffer, int pixelX, int pixelY, int height, int width) { // old loop that draws a gradient as i was learning
    // normalize pixels into UV coordinates
    double u = (double)pixelX / height;
    double v = (double)pixelY / width;

    Vec2 rayDir = {u,v};

    double length = std::sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y); // simple pythagorean theorem yo
    if (length > 0.0001) { // avoids NaN or division by zero at the centerpoint
        rayDir.x /= length;
        rayDir.y /= length;
    }

    // de-normalize, basically converts back into rgba
    int pixelR = (int)((rayDir.x * 0.5 + 0.5) * 255);
    int pixelG = (int)((rayDir.y * 0.5 + 0.5) * 255);
    //int pixelB = i;
    int pixelB = 255;

    SetPixel(buffer.data(), width, height,
        pixelX, pixelY, pixelR, pixelG, pixelB,
        255);
}