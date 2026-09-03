//
// Created by cdemin on 9/3/26.
//

#include "loop.h"
#include "main_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/valarray_after.h>



void loop(std::vector<uint32_t> pixelBuffer, int width, int height, Vec2 rayDir, unsigned long long i) {
    for (int pixelY = 0; pixelY < height; pixelY++) {
        for (int pixelX = 0; pixelX< width; pixelX++) {
            // normalize pixels into UV coordinates
            double u = (double)pixelX / width;
            double v = (double)pixelY / height;

            Vec2 rayDir = {u,v};

            double length = std::sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y); // simple pythagorean theorem yo
            if (length > 0.0001) { // avoids NaN or division by zero at the centerpoint
                rayDir.x /= length;
                rayDir.y /= length;
            }

            // de-normalize, basically converts back into rgba
            int pixelR = (int)((rayDir.x * 0.5 + 0.5) * 255);
            int pixelG = (int)((rayDir.y * 0.5 + 0.5) * 255);
            int pixelB = i;

            SetPixel(pixelBuffer.data(), width, height, pixelX, pixelY, pixelR, pixelG, pixelB, 255);
        }
    }
}
