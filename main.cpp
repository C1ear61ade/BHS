#include <GLFW/glfw3.h>
#include "Physics/CelestialBodies.h"
#include "Math/Vector3.h"
#include <bits/stdc++.h>

struct Position {
    double bodyX;
    double bodyY;
};

Position CelestialBodyPosition(const Vector3& position, int windowWidth, int windowLength) {
    constexpr double scale = 1e9;
    return {windowWidth / 2.0 + position.x / scale, windowLength / 2.0 + position.y / scale};
}

void DrawBody(double x, double y, double radius) {
    glBegin(GL_TRIANGLE_FAN);

    glVertex2d(x, y);

    for (int i = 0; i <= 100; i++) {
        double angle = 2.0 * M_PI * i/100;
        double objectX = x + cos(angle) * radius;
        double objecty = y + sin(angle) * radius;

        glVertex2d(objectX, objecty);
    }

    glEnd();
}

int main(){

    CelestialBodies Earth("Earth",5.9722e24,6371000.0,Vector3(1.496e11, 0, 0),Vector3(0 ,29.78 ,0));
    CelestialBodies Sun("Sun", 1.972e24, 696340000.0, Vector3(0, 0, 0), Vector3(0, 0, 0));

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

        int width, height;
        constexpr double scale = 1e9;

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();

        glfwGetFramebufferSize(window, &width, &height);
        glOrtho(0, width, height, 0, -1, 1);

        double Xcenter = width / 2.0;
        double Ycenter = height / 2.0;

        Position sunPosition = CelestialBodyPosition(Sun.position, width, height);
        Position earthPosition = CelestialBodyPosition(Earth.position, width, height);

    }

    glfwTerminate();
    return 0;
}
