#include <gtest/gtest.h>

#include "matrix.hpp"
#include "matrixManager.hpp"

class MatrixManagerTest : public ::testing::Test {
public:
    MatrixManager* matrixManager = nullptr;
    Matrix* firstMatrix = nullptr;
    Matrix* secondMatrix = nullptr;
    Matrix* thirdMatrix = nullptr;

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

    std::vector<std::vector<double>>* cMatrixContent = new std::vector<std::vector<double>>{
        {5, 6, 7},
        {-5, 26, 12},
        {0, 2, 1},
    };

    ~MatrixManagerTest()
    {
        delete matrixManager;
        delete firstMatrix;
        delete secondMatrix;
        delete thirdMatrix;
        delete aMatrixContent;
        delete bMatrixContent;
        delete cMatrixContent;
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
}

TEST_F(MatrixManagerTest, ShouldAddTwoMatrixesAndReturnMatrixConsistSum)
{
    matrixManager = new MatrixManager();
    firstMatrix = new Matrix(3, 3);
    secondMatrix = new Matrix(3, 3);
    thirdMatrix = new Matrix();
    char a = 'a';
    char b = 'b';

    [[maybe_unused]] auto extractedfirstMatrix = firstMatrix->getMatrix();
    [[maybe_unused]] auto extractedsecondMatrix = secondMatrix->getMatrix();

    extractedfirstMatrix = aMatrixContent;
    extractedsecondMatrix = bMatrixContent;

    delete thirdMatrix;
    thirdMatrix = matrixManager->addTwoMatrixes(a, b);
    auto extractedThirdMatrix = thirdMatrix->getMatrix();

    EXPECT_EQ(*extractedThirdMatrix, *cMatrixContent);

}
