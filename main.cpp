#include <SDL3/SDL.h>
#include <vector>
#include <iostream>

int strOut(std::string str, std::string type = "output") {
    if (type != "output") {
        std::string declare = std::toupper(type);
        std::cout << "[" + declare + "] " << str << std::endl;
    } else {
        std::cout << str << std::endl;
    }
}

int main() {
    // constants
    const int WIDTH = 640;
    const int HEIGHT = 480;
    strOut("Constants Initialized.");

    // variables
    strOut("Variables Initialized.");

    strOut()
}