#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

int strOut(std::string str) {
    std::cout << str << std::endl;
    return 0;
}

int main()
{
    strOut("Starting Program...");

    if (!glfwInit()) {
        strOut("Failed to Initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(
        640, 480,
        "CSC1060 - Black Hole",
        nullptr,
        nullptr
    );

    if (!window)
    {
        glfwTerminate();
        strOut("Window Creation Failed");
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}