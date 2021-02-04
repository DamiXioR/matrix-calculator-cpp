#include <gtest/gtest.h>

#include "matrix.hpp"
#include "matrixManager.hpp"

class MatrixManagerTest : public ::testing::Test {
public:
    MatrixManager* matrixManager = nullptr;
    Matrix* firstMatrix = nullptr;
    Matrix* secondMatrix = nullptr;

    ~MatrixManagerTest()
    {
    }
};

TEST_F(MatrixManagerTest, ShouldAddNewMatrixToMatrixHolderWhenKeyNotExists)
{
    matrixManager = new MatrixManager();
    firstMatrix = new Matrix(3, 2);
    secondMatrix = new Matrix(3, 2);
    char a = 'a';
    char b = 'b';

    EXPECT_TRUE(matrixManager->addNewMatrix(a, *firstMatrix));
    EXPECT_TRUE(matrixManager->addNewMatrix(b, *secondMatrix));

    delete matrixManager;
    delete firstMatrix;
    delete secondMatrix;
}
