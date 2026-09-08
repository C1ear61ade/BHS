#include "Physics/CelestialBodies.h"
#include <vector>
#include <cmath>
#include <glad/gl.h>


void CelestialBodies::initSphere() {
    struct coors {
        float x, y, z;
    };

    std::vector<coors> vertices;
    std::vector<unsigned int> indices;

    constexpr int latitudeSegments = 32, longitudeSegments = 32;
    unsigned int VAO = 0, VBO = 0, EBO = 0;

    //Generate and saving Vertices Coordinates:
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

    //Connecting Vertices Coordinates:
    for (int i = 0; i < longitudeSegments; i++) {
        for (int j = 0; j < latitudeSegments; j++) {

            int firstRow = i * (longitudeSegments + 1) + j, secondRow = firstRow + longitudeSegments + 1;

            indices.push_back(firstRow);
            indices.push_back(secondRow);
            indices.push_back(firstRow + 1);

            indices.push_back(secondRow);
            indices.push_back(secondRow + 1);
            indices.push_back(firstRow + 1);

        }
    }

    indiceCount = static_cast<unsigned int>(indices.size());

    //OpenGL rendering:
    glEnable(GL_DEPTH_TEST);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO); // Bind Vertex Array Object(VAO) to store attribute state
    glBindBuffer(GL_ARRAY_BUFFER,VBO); // Bind Vertex Buffer Objects(VBO) to upload data
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(coors), vertices.data(),GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(coors),nullptr);

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void CelestialBodies::renderSphere() const{

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES,GLsizei(indiceCount), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);

}
