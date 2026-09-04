#include "Graphics/Rendering.cpp"
#include "Physics/CelestialBodies.h"
#include "Math/Vector3.h"
#include "Graphics/GUI-initiator.h"
#include <bits/stdc++.h>

//----------------------------------------------------------------------------------------------------------------
//Variable defining:

bool spawnBlackHole;

//----------------------------------------------------------------------------------------------------------------
struct Position {
    double bodyX;
    double bodyY;
};

Position CelestialBodyPosition(const Vector3& position, int windowWidth, int windowLength) {
    constexpr double scale = 1e9;
    return {windowWidth / 2.0 + position.x / scale, windowLength / 2.0 + position.y / scale};
}

int main(){
    GLFWwindow* window = GUIinitiate(1200, 800, "BHS_DEVELOPEMENT");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        //Starting ImGui frames:
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        glClearColor(0.0f,0.0f,0.0f,1.0f); //Note: Parameters are RGB and the last one is opacity
        glClear(GL_COLOR_BUFFER_BIT);

        //UI window for parameters:
        ImGui::NewFrame();
        ImGui::Begin("Celestial Body Parameters");
        ImGui::Checkbox("Black Hole", &spawnBlackHole);
        ImGui::End();
        ImGui::Render(); //Render UI
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window); //Show finished frame
    }

    CelestialBodies Earth("Earth",5.9722e24,6371000.0,Vector3(1.496e11, 0, 0),Vector3(0 ,29780 ,0));
    CelestialBodies Sun("Sun", 1.989e30, 696340000.0, Vector3(0, 0, 0), Vector3(0, 0, 0));

    //Shutdown operations to prevent memory leaks:
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
