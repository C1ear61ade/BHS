#include <array>
#pragma once

class Matrix4 {

    private:
        std::array<std::array<double, 4>, 4> dataMatrix{};

    public:
        Matrix4(); //Constructor

        [[nodiscard]] double get(int a, int b) const; // Retrieve a value from the 4x4 matrix WITHOUT changing anything in the matrix
        void set(int row, int column, double value); // Changes value of the vector.


        //Matrix Operations
        Matrix4 operator + (const Matrix4& other) const;
        Matrix4 operator - (const Matrix4& other) const;
        Matrix4 operator * (double scalar) const;
        Matrix4 operator / (double scalar) const;

};

