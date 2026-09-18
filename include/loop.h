//
// Created by cdemin on 9/10/26.
//

#include <cstdint>

#include <iostream>
#include <vector>
#include "structs.h"

void loop2D(std::vector<uint32_t>& buffer,
    BlackHole& hole, int pixelX, int pixelY,
    const int height, const int width,
    std::array<int,
    4> backgroundColor);

void test_loop(std::vector<uint32_t>& buffer, int pixelX, int pixelY, int height, int width);
