#include <gtest/gtest.h>

#include <string>
#include <vector>
#include "matrix.hpp"

class MatrixTest : public ::testing::Test {
public:
    ~MatrixTest()
    {
        delete testMatrix;
    }

    Matrix* testMatrix = nullptr;

    //Matrix size

    const unsigned testRows5 = 5;
    const unsigned testColumns7 = 7;
    const unsigned testRows10 = 10;
    const unsigned testColumns1 = 1;

    //Row inputs

    std::vector<std::string> testInputOnlyDigits{
        {"2 "},
        {"1 "},
        {"1 2 "},
        {"1 2 3 "},
        {"1 2 3 4 "},
        {"1 2 3 4 5 "},
        {"1 2 3 4 5 6 "},
        {"1 2 3 4 5 6 7 8 "},
        {"1 2 3 4 5 6 7 8 9 "},
        {"1 2 3 4 5 6 7 8 9 10 "},
        {"1 2 3 4 5 6 7 8 9 10 11"}};

    std::vector<std::string> testInputMixedDigitsOrCharacters{
        {"x "},
        {"1c "},
        {"a1 "},
        {"1 2 gg"},
        {"1 2 !@3 "},
        {"1 2 $!3 4a "},
        {"1 2 3 4 5a "},
        {"1 2 3 4 *(c5 6 "},
        {"1 2 3 4 5 6 7 8 &%"},
        {"1 2 3 4 5 6 7 8 9 tg"},
        {"1 2 3 a5g4 5 6 7 8 9 10 "},
        {"1!@# 2 3 4 5 6 7 8 9 10 11"},
        {"                    1 2 3 4 5 @$!"}};
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

TEST_F(MatrixTest, ShouldReturnTrueOnlyWhenRowsInputConsistOnlyDigits)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    for (auto& everyInput : testInputMixedDigitsOrCharacters) {
        EXPECT_FALSE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    for (auto& everyInput : testInputMixedDigitsOrCharacters) {
        EXPECT_FALSE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows5, testColumns7);
    for (auto& everyInput : testInputOnlyDigits) {
        EXPECT_TRUE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    for (auto& everyInput : testInputOnlyDigits) {
        EXPECT_TRUE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
}
