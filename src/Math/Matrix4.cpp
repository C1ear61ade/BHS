#include "Matrix4.h"

Matrix4::Matrix4() { //Constructor
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dataMatrix[i][j] = 0.0; // Set all elements inside matrix to 0
        }
    }
}

double Matrix4::get(int row, int column) const {
    return dataMatrix[row][column]; //Returns value from a position of the matrix
}

void Matrix4::set(int row, int column, double value) {
    dataMatrix[row][column] = value; //Change a value at position (row,column) in the matrix
}

//Operator Implementation:

Matrix4 Matrix4::operator + (const Matrix4& other) const {

    Matrix4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.dataMatrix[i][j] = dataMatrix[i][j] + other.dataMatrix[i][j];
        }
    }
    return result;
}

Matrix4 Matrix4::operator - (const Matrix4& other) const {

    Matrix4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.dataMatrix[i][j] = dataMatrix[i][j] - other.dataMatrix[i][j];
        }
    }
    return result;
}

Matrix4 Matrix4::operator * (double scalar) const {

    Matrix4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.dataMatrix[i][j] = dataMatrix[i][j] * scalar;
        }
    }
    return result;
}

Matrix4 Matrix4::operator / (double scalar) const
{
    Matrix4 result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.dataMatrix[i][j] = dataMatrix[i][j] / scalar;
        }
    }
    return result;
}