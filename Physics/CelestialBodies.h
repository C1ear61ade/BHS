#pragma once
#include <string>

class CelestialBodies {
public:

    std::string name;
    double mass;

    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;

    CelestialBodies(std::string name, double mass, const Vector3& position, const Vector3& velocity); //Constructors with parameters

    [[nodiscard]] Vector3 Gravity(const CelestialBodies& other) const;

    void update(double dt);

};
