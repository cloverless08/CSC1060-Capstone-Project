#include <SDL3/SDL.h>
#include <vector>
#include <iostream>

int strOut(std::string str) {
    std::cout << str << std::endl;
}

int main() {
    // constants
    const int WIDTH = 640;
    const int HEIGHT = 480;
    strOut("Constants Initialized.");

    // structs
    struct Color {
        uint8_t r, g, b, a;
    };
    strOut("Structs Initialized.");

    // variables
    strOut("Variables Initialized.");
}