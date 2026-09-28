/*
    Creator: C1ear61ade
    Purpose: Declaration of Vector3 class representing a point or direction in 3D space. Contains the x y z position of Celestial bodies for easy calculations
*/

#pragma once

class Vector3{
    public: //Set access to public
        // The x,y,z variables:
        double x;
        double y;
        double z;

        Vector3(double x, double y, double z); //Constructor
        [[nodiscard]] double length() const; //Return length of the vector. Ex. [3,4,5] would yield sqrt(3^2+4^2+5^2) (Pythagorean theorem in 3D space)
        [[nodiscard]] Vector3 normalize() const; //Returns a unit vector

        // Magnitude and Unit vector dot product to find the direction the two vectors are pointing, angle between the vectors, etc.
        [[nodiscard]] double dotProduct(const Vector3& other) const; //Returns a number value

        // Cross product to find surface normals rotations torque angular momentum and orbital mechanics
        [[nodiscard]] Vector3 crossProduct(const Vector3& other) const; //Returns another vector

        //Operators:
        Vector3 operator + (const Vector3& other) const; //Allow two Vector3 to be added together
        Vector3 operator - (const Vector3& other) const; //Allow two Vector3 to be subtracted together
        Vector3 operator * (double scalar) const; //Allow two Vector3 to be multiplied together
        Vector3 operator / (double scalar) const; //Allow two Vector3 to be divided together


};