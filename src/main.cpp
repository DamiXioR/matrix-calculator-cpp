#include "allHeaders.hpp"

int main(){

    Matrix matrix(5,7);
    matrix.printMatrix();
    matrix.setMatrixValues();
    matrix.printMatrix();
    
    MatrixManager mManager = MatrixManager{};
    mManager.addTwoMatrixes('a','b');

    
    return 0;
}
