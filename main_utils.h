//
// Created by cdemin on 8/25/26.
//
#include <cstdint>
#pragma once

#ifndef CSC1060_CAPSTONE_PROJECT_MAIN_UTILS_H
#define CSC1060_CAPSTONE_PROJECT_MAIN_UTILS_H
#include <string>

#endif //CSC1060_CAPSTONE_PROJECT_MAIN_UTILS_H

int strOut(const std::string msg = "Nothing to output (edit strOut() to fix)", std::string label = "standard");

int randInt(int rangeMin, int rangeMax);

void SetPixel(uint32_t* buffer, int width, int height, int x, int y, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255);