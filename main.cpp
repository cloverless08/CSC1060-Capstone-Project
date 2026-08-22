#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int testFunction(int num) {
    std::cout << "Your number is: " << num << std::endl;
    return 0;
}

int main() {
     double var = 10;
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
