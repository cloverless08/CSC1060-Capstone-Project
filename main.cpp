#include <SDL3/SDL.h>
#include <vector>
#include <iostream>
#include <cctype>

int strOut(std::string str, std::string type = "standard") {
    if (type != "standard") {
        for (char &c : type) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }
        std::cout << "[" + type + "] " << str << std::endl;
    } else {
        std::cout << str << std::endl;
    }

    return 0;
}

int main() {
    // constants
    const int WIDTH = 640;
    const int HEIGHT = 480;
    strOut("Constants Initialized.");

    // variables
    int var = 10;
    strOut("Variables Initialized.");
}