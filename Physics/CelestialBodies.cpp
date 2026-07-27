#include "C:\Users\ryans\Desktop\Code\BlackholeSim\Math\Vector3.h"
#include "CelestialBodies.h"

CelestialBodies::CelestialBodies(std::string name, double mass, const Vector3& position, const Vector3& velocity):name(std::move(name)), mass(mass), position(position), velocity(velocity), acceleration(0, 0, 0){}

// implementation of gravity + gravity acceleration:

Vector3 CelestialBodies::Gravity(const CelestialBodies& other) const {

    //Newton gravity formula
    double constexpr G = 6.67430e-11;

    double distance = (other.position - position).length();
    Vector3 unitDirection = (other.position - position).normalize();

    double accelerationMagnitude = (G * other.mass) / (distance*distance);

    return unitDirection * accelerationMagnitude;

};

void CelestialBodies::update(double dt) {
    acceleration = Gravity(*this);
    velocity = velocity + acceleration * dt;
    position = position + velocity * dt;
};