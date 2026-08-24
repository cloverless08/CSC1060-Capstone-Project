#include <iostream>
#include <string>
#include <cmath>
#include <GLFW/glfw3.h>
#include <cstdlib>

int testFunction(int num) {
    std::cout << "Your number is: " << num << std::endl;
    return 0;
}

int main() {
    int var = 10;
    var = static_cast<double>(var);


    std::cout << var << std::endl;
    std::cin >> var;
    std::cout << var << std::endl;
    testFunction(var);

    const std::string str1 = "Hello, World!";
    int num1;
    int num2;

    std::cout << "Enter two numbers to add." << std::endl;
    std::cin >> num1;
    std::cin >> num2;

    std::cout << num1 + num2 << std::endl;
    std::cout << sqrt(num1 + num2) << std::endl;
    std::cout << str1 << std::endl;

    return 0;
}
