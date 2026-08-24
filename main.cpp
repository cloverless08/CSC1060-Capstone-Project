#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

int strOut(std::string str) {
    std::cout << str << std::endl;
    return 0;
}

int main()
{
    const char * WINDOW_TITLE = "CSC1060 Black Hole Simulation";
    int width = 640;
    int height = 480;

    strOut("Starting Program...");

    if (!glfwInit()) {
        strOut("Failed to Initialize GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(
        width, height,
        WINDOW_TITLE,
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