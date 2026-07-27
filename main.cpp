#include <GLFW/glfw3.h>
#include "Physics/CelestialBodies.h"
#include "Math/Vector3.h"
#include <bits/stdc++.h>

int main(){

    if (!glfwInit()) {
        std::cout << "GLFW failed because of an unknown error. Please check on your own accord." << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800,600,"Black Hole Simulator", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    CelestialBodies Earth("Earth", 5.9722e24, Vector3(1.496e11, 0, 0),Vector3(0 ,29.78 ,0));
    CelestialBodies Sun("Sun", 1.972e24, Vector3(0, 0, 0), Vector3(0, 0, 0));


    glfwTerminate();
    return 0;
}
