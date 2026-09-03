//
// Created by cdemin on 9/3/26.
//

#pragma once

#ifndef CSC1060_CAPSTONE_PROJECT_LOOP_H
#define CSC1060_CAPSTONE_PROJECT_LOOP_H
#include <cstdint>

#endif //CSC1060_CAPSTONE_PROJECT_LOOP_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/valarray_after.h>

struct Vec2 {
    double x, y;
};

void loop(std::vector<uint32_t> pixelBuffer, int width, int height, Vec2& rayDir, unsigned long long i);
