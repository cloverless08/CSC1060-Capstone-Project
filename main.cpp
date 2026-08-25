#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cctype>
#include <array>

// function for clean console output with labels
int strOut(const std::string str = "Nothing to output (edit strOut() to fix)", std::string type = "standard") {
    if (type != "standard") {
        for (char &c : type) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); // changes string 'type' to all upper
        }
        std::cout << "[" + type + "] " << str << std::endl; // output with label
    } else {
        std::cout << str << std::endl; // output without label
    }

    return 0;
}

int main() {
    // constants
    const int WIDTH = 640;
    const int HEIGHT = 480;
    std::array<std::string, 4> msgType = {"SYSTEM", "ERROR", "SETUP", "WARN"}; // strOut() helpful labels
    strOut("Constants Initialized.", msgType[2]);

    // variables
    int var = 10;
    strOut("Variables Initialized.", msgType[2]);

    // create cancas (pixel buffer) in memory
    uint32_t pixelBuffer[WIDTH * HEIGHT];
    strOut("Pixel Buffer Initialized.", msgType[2]);


    return 0;
}