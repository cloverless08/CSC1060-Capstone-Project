#include <SDL3/SDL.h>
#include <vector>
#include <iostream>

int strOut(std::string str, std::string type = "output") {
   if (type == "debug") {
       std::cout << "[DEBUG] " << str << std::endl;
   } else if (type == "error") {
       std::cout << "[ERROR} " << str << std::endl;
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