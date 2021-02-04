#include "allHeaders.hpp"

#include <iostream>

int main(){

    Matrix* matrix = new Matrix(2,3);
    matrix->setMatrixValues();
    matrix->printMatrix();

    Matrix* matrixB = new Matrix(2,3);
    matrixB->setMatrixValues();
    matrixB->printMatrix();
    
    MatrixManager* mManager = new MatrixManager();
    mManager->addNewMatrix('a', *matrix);
    mManager->addNewMatrix('b',*matrixB);

    Matrix matrixC = mManager->addTwoMatrixes('a','b');
    matrixC.printMatrix();

    delete mManager;
    delete matrix;
    delete matrixB;
    
    return 0;
}
