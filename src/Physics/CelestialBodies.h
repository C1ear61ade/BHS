#pragma once
#include "Math/Vector3.h"
#include <string>

class CelestialBodies {

private:
    unsigned int VAO = 0;
    unsigned int VBO = 0;
    unsigned int EBO = 0;
    unsigned int indiceCount = 0;


public:

    std::string name;
    double mass;
    double radius;

    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;

    CelestialBodies(std::string name, double mass, double radius, const Vector3& position, const Vector3& velocity); //Constructors with parameters

    [[nodiscard]] Vector3 Gravity(const CelestialBodies& other) const;

    void initSphere();
    void renderSphere() const;

    void update(const CelestialBodies& other, double dt);

};
