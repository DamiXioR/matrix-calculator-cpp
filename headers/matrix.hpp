#pragma once
#include <vector>

class Matrix {
public:
    Matrix(unsigned rows, unsigned columns);
    ~Matrix();

    void printMatrix();

private:
    std::vector<std::vector<int>>* matrix_;
};