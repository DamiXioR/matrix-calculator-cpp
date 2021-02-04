#pragma once

#include <map>
#include <vector>
#include "matrix.hpp"

class MatrixManager {
public:
    MatrixManager();
    ~MatrixManager();
    Matrix addNewMatrix(Matrix newMatrix);
    Matrix addTwoMatrixes(char firstMatrixKey, char secondMatrixKey);
    std::map<char, Matrix>* getMatrixHolder() const
    {
        return matrixHolder_;
    }

private:
    std::map<char, Matrix>* matrixHolder_;
};
