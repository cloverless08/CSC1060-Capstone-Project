//
// Created by cdemin on 8/25/26.
//

#include "main_utils.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// function for clean, dynamic console output with labels
int strOut(const std::string msg, std::string label) {
    if (label != "standard") {
        for (char &c : label) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); // changes string 'label' to all upper
        }
        if (label == "ERROR") {
            std::cout << RED << "[" + label + "] " << msg << RESET << std::endl; // output with label
        } else if (label == "WARN") {
            std::cout << YELLOW << "[" + label + "] " << msg << RESET << std::endl; // output with label
        } else if (label == "SETUP") {
            std::cout << CYAN << "[" + label + "] " << msg << RESET << std::endl; // output with label
        }
    } else {
        std::cout << RESET << msg << RESET<< std::endl; // output without label
    }

    return 0;
}