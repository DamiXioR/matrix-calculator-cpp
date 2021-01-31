#include <gtest/gtest.h>

#include <vector>
#include "matrix.hpp"

class MatrixTest : public ::testing::Test {
public:
    ~MatrixTest()
    {
        delete testMatrix;
    }

    Matrix* testMatrix = nullptr;
    const unsigned testRows5 = 5;
    const unsigned testColumns7 = 7;
    const unsigned testRows10 = 10;
    const unsigned testColumns1 = 1;
};

// IMPORTANT! testMatrix freed in MatrixTest dtor, you haven't delete it at the end of every test case
// except when you alloc new memory more than one time in one test case

TEST_F(MatrixTest, ShouldCreateMatrixWithSpecifiedNumsOfRowsAndColumns)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    EXPECT_EQ(testMatrix->getMatrix()->size(), testRows5);
    for (auto& everyRow : *testMatrix->getMatrix()) {
        EXPECT_EQ(everyRow.size(), testColumns7);
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    EXPECT_EQ(testMatrix->getMatrix()->size(), testRows10);
    for (auto& everyRow : *testMatrix->getMatrix()) {
        EXPECT_EQ(everyRow.size(), testColumns1);
    }
}

TEST_F(MatrixTest, ShouldReturnValueOfRowsOrColumns)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    EXPECT_EQ(testMatrix->getRows(), testRows5);
    EXPECT_EQ(testMatrix->getColumns(), testColumns7);
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    EXPECT_EQ(testMatrix->getRows(), testRows10);
    EXPECT_EQ(testMatrix->getColumns(), testColumns1);
}
