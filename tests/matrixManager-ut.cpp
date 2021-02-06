#include <gtest/gtest.h>

#include "matrix.hpp"
#include "matrixManager.hpp"

class MatrixManagerTest : public ::testing::Test {
public:
    MatrixManager* matrixManager = nullptr;
    Matrix* firstMatrix = nullptr;
    Matrix* secondMatrix = nullptr;
    Matrix* thirdMatrix = nullptr;

    char a = 'a';
    char b = 'b';

    std::vector<std::vector<double>>* aMatrixContent = new std::vector<std::vector<double>>{
        {1, 2, 3},
        {10, 6, 1},
        {2, 1, 2},
    };

    std::vector<std::vector<double>>* bMatrixContent = new std::vector<std::vector<double>>{
        {4, 4, 4},
        {-15, 20, 11},
        {-2, -1, -1},
    };

    std::vector<std::vector<double>>* cMatrixContentSumAB = new std::vector<std::vector<double>>{
        {5, 6, 7},
        {-5, 26, 12},
        {0, 0, 1},
    };

    std::vector<std::vector<double>>* dMatrixContentSubstractAB = new std::vector<std::vector<double>>{
        {-3, -2, -1},
        {25, -14, -10},
        {4, 2, 3},
    };

    ~MatrixManagerTest()
    {
        delete matrixManager;
        delete firstMatrix;
        delete secondMatrix;
        delete thirdMatrix;
        delete aMatrixContent;
        delete bMatrixContent;
        delete cMatrixContentSumAB;
        delete dMatrixContentSubstractAB;
    }
};

TEST_F(MatrixManagerTest, ShouldAddNewMatrixToMatrixHolderWhenKeyNotExists)
{
    matrixManager = new MatrixManager();
    firstMatrix = new Matrix(3, 2);
    secondMatrix = new Matrix(3, 2);
    char a = 'a';
    char b = 'b';

    EXPECT_TRUE(matrixManager->addNewMatrix(a, firstMatrix));
    EXPECT_TRUE(matrixManager->addNewMatrix(b, secondMatrix));
}

TEST_F(MatrixManagerTest, ShouldAddTwoMatrixesAndReturnMatrixConsistSum)
{
    matrixManager = new MatrixManager();
    firstMatrix = new Matrix(3, 3);
    secondMatrix = new Matrix(3, 3);

    firstMatrix->loadExternalMatrix(aMatrixContent);
    secondMatrix->loadExternalMatrix(bMatrixContent);

    matrixManager->addNewMatrix(a, firstMatrix);
    matrixManager->addNewMatrix(b, secondMatrix);

    thirdMatrix = matrixManager->addTwoMatrixes(a, b);

    EXPECT_EQ(thirdMatrix->getMatrix(), *cMatrixContentSumAB);
}

TEST_F(MatrixManagerTest, ShouldSubstractTwoMatrixesAndReturnMatrixConsistSubstract)
{
    matrixManager = new MatrixManager();
    firstMatrix = new Matrix(3, 3);
    secondMatrix = new Matrix(3, 3);

    firstMatrix->loadExternalMatrix(aMatrixContent);
    secondMatrix->loadExternalMatrix(bMatrixContent);

    matrixManager->addNewMatrix(a, firstMatrix);
    matrixManager->addNewMatrix(b, secondMatrix);

    thirdMatrix = matrixManager->substractTwoMatrixes(a, b);

    EXPECT_EQ(thirdMatrix->getMatrix(), *dMatrixContentSubstractAB);
}
