#include "Physics/CelestialBodies.h"
#include "Math/Vector3.h"
#include "Graphics/GUI-initiator.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <bits/stdc++.h>

//----------------------------------------------------------------------------------------------------------------

//Variable defining:
bool spawnBlackHole;
float radiusMultiplier = 1.0f;
float massMultiplier = 1.0f;

//----------------------------------------------------------------------------------------------------------------

//Structure + Function defining:
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

    //Get shader files:
    std::cout << "Working directory: " << std::filesystem::current_path() << '\n';
    std::ifstream vertexfile("../Graphics/shaders/sphere.vert");
    std::ifstream fragmentfile("../Graphics/shaders/sphere.frag");

    //Check if files are open:
    if (!vertexfile.is_open() || !fragmentfile.is_open()) {
        std::cerr << "Could not open shader files!\n";
        return -1;
    }

    std::stringstream vertexStream, fragmentStream;
    vertexStream << vertexfile.rdbuf();
    fragmentStream << fragmentfile.rdbuf();

    vertexfile.close();
    fragmentfile.close();

    std::string vertexCode = vertexStream.str();
    std::string fragmentCode = fragmentStream.str();

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    //Compile shaders:
    unsigned int vertexShaders = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaders, 1, &vertexSource, nullptr);
    glCompileShader(vertexShaders);

    //Shader checkers:
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShaders, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShaders, 512, nullptr, infoLog);
        std::cerr << "Vertex shader failed: \n" << infoLog << '\n';
    }

    //Compile fragment shaders:
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    //Fragment checker:
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "Fragment shader failed:\n" << infoLog << '\n';
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShaders);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader program failed: \n" << infoLog << '\n';
    }

    glDeleteShader(vertexShaders);
    glDeleteShader(fragmentShader);

    //Celestial Body creation:
    CelestialBodies Earth("Earth",5.9722e24,6371000.0,Vector3(1.496e11, 0, 0),Vector3(0 ,29780 ,0));
    CelestialBodies Sun("Sun", 1.989e30, 696340000.0, Vector3(0, 0, 0), Vector3(0, 0, 0));

    Earth.initSphere();
    Sun.initSphere();

    //UI creation:
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        //Starting ImGui frames:
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        glClearColor(0.0f,0.0f,0.0f,1.0f); //Note: Parameters are RGB and the last one is opacity
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Render in bodies:
        glUseProgram(shaderProgram);
        Earth.renderSphere();
        Sun.renderSphere();

        //UI window for parameters:
        ImGui::NewFrame();
        ImGui::Begin("Celestial Body Parameters");
        ImGui::Checkbox("Black Hole", &spawnBlackHole);
        ImGui::SliderFloat("Earth radius", &radiusMultiplier, 0.5f, 2.0f);
        ImGui::SliderFloat("Earth mass", &massMultiplier, 0.5f, 2.0f);
        ImGui::End();
        ImGui::Render(); //Render UI
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        //Celestial Body logic:
        Earth.radius = 6371000.0 * radiusMultiplier;
        Earth.mass = 5.9722e24 * massMultiplier;

        glfwSwapBuffers(window); //Show finished frame
    }

    //Shutdown operations to prevent memory leaks:
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
