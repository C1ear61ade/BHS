#include <GLFW/glfw3.h>
#include "Physics/CelestialBodies.h"
#include "Math/Vector3.h"

int main(){
    CelestialBodies Earth("Earth", 5.9722e24, Vector3(1.496e11, 0, 0),Vector3(0 ,29.78 ,0));
    CelestialBodies Sun("Sun", 1.972e24, Vector3(0, 0, 0), Vector3(0, 0, 0));
    return 0;
}
