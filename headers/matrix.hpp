#pragma once
#include <vector>

class Matrix {
public:
    Matrix(unsigned rows, unsigned columns);
    ~Matrix();

    void createEmptyMatrix();
    void printMatrix();

private:
    std::vector<std::vector<int>>* matrix_{};
    std::size_t rows_{};
    std::size_t columns_{};
};