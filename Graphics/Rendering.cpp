#include "Physics/CelestialBodies.h"
#include <vector>
#include <cmath>

void CelestialBodies::renderSphere() const {

    struct coors {
        float x, y, z;
    };

    std::vector<coors> vertices;
    std::vector<unsigned int> indices;

    constexpr int latitudeSegments = 32, longitudeSegments = 32;

    //Generate and saving Vertcies:
    for (int i = 0; i <= longitudeSegments; i++) {
        double alpha = M_PI * i / latitudeSegments;

        double sinAlpha = sin(alpha);
        double cosAlpha = cos(alpha);

        for (int j = 0; j <= latitudeSegments; j++) {
            double beta = 2 * M_PI * j / longitudeSegments;

            double sinBeta = sin(beta);
            double cosBeta = cos(beta);

            double x = sinAlpha * cosBeta, y =cosAlpha, z = sinAlpha * sinBeta;

            vertices.push_back({float(x), float(y), float(z)});
        }

    }

    //Connecting Vertices


}