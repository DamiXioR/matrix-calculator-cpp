#include <gtest/gtest.h>

#include <string>
#include <vector>
#include "matrix.hpp"

class MatrixTest : public ::testing::Test {
public:
    ~MatrixTest()
    {
        delete newMatrixContent;
        delete newMatrixContentWithAccessByColumns;
        delete testMatrix;
    }

    Matrix* testMatrix = nullptr;

    //Matrix size

    const unsigned testRows5 = 5;
    const unsigned testColumns7 = 7;
    const unsigned testRows10 = 10;
    const unsigned testColumns1 = 1;
    const unsigned testRows3 = 3;
    const unsigned testColumns3 = 3;

    //Row inputs

    std::vector<std::string> testStringInputOnlyDigits{
        {"1 "},
        {"1 -2 "},
        {"1 2 3 "},
        {"1 2 3 4 "},
        {"1 2 3 4 5 "},
        {"1 2 3 4 5 6 "},
        {"1 2 3 4 5 6 7 "},
        {"1 2 3 4 5 6 7 8 "},
        {"1 2 3 4 5 6 7 8 9 "},
        {"1 2 3 4 5 6 7 8 9 10 "},
        {"1 2 3 4 5 6 7 8 9 10 11"}};

    std::vector<std::vector<double>> digitsEqualToStringInputOnlyDigits{
        {1},
        {1, -2},
        {1, 2, 3},
        {1, 2, 3, 4},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6, 7},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};

    std::vector<std::string> tesyStringInputMixedDigitsAndCharacters{
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

    std::string emptyRow = "         ";

    std::vector<std::vector<double>>* newMatrixContent = new std::vector<std::vector<double>>{
        {1, 2, 3},
        {10, 6, 1},
        {2, 1, 2},
    };

    std::vector<std::vector<double>>* newMatrixContentWithAccessByColumns = new std::vector<std::vector<double>>{
        {1, 10, 2},
        {2, 6, 1},
        {3, 1, 2},
    };
};

// IMPORTANT! testMatrix freed in MatrixTest dtor, you haven't delete it at the end of every test case
// except when you alloc new memory more than one time in one test case

TEST_F(MatrixTest, ShouldCreateMatrixWithSpecifiedNumsOfRowsAndColumns)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    EXPECT_EQ(testMatrix->getMatrix().size(), testRows5);
    for (auto& everyRow : testMatrix->getMatrix()) {
        EXPECT_EQ(everyRow.size(), testColumns7);
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    EXPECT_EQ(testMatrix->getMatrix().size(), testRows10);
    for (auto& everyRow : testMatrix->getMatrix()) {
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
    for (auto& everyInput : tesyStringInputMixedDigitsAndCharacters) {
        EXPECT_FALSE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    for (auto& everyInput : tesyStringInputMixedDigitsAndCharacters) {
        EXPECT_FALSE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows5, testColumns7);
    for (auto& everyInput : testStringInputOnlyDigits) {
        EXPECT_TRUE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    for (auto& everyInput : testStringInputOnlyDigits) {
        EXPECT_TRUE(testMatrix->isInputValuesConsistsDigits(everyInput));
    }
}

TEST_F(MatrixTest, ShouldReturnTrueWhenRowsInputIsEqualToColumnsSizeAndFalseWhenNot)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    unsigned numOfDigits = 1;

    for (auto& everyInput : testStringInputOnlyDigits) {
        if (numOfDigits == testColumns7) {
            EXPECT_TRUE(testMatrix->isInputValuesEqualToColumnsSize((everyInput)));
        }
        else {
            EXPECT_FALSE(testMatrix->isInputValuesEqualToColumnsSize((everyInput)));
        }
        numOfDigits++;
    }
    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    numOfDigits = 1;

    for (auto& everyInput : testStringInputOnlyDigits) {
        if (numOfDigits == testColumns1) {
            EXPECT_TRUE(testMatrix->isInputValuesEqualToColumnsSize((everyInput)));
        }
        else {
            EXPECT_FALSE(testMatrix->isInputValuesEqualToColumnsSize((everyInput)));
        }
        numOfDigits++;
    }
}

TEST_F(MatrixTest, ShouldReturnTrueWhenAllInputIsCorrect)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    unsigned numOfDigits = 1;

    for (auto& everyInput : testStringInputOnlyDigits) {
        if (numOfDigits == testColumns7) {
            EXPECT_TRUE(testMatrix->isTemporaryRowInputCorrect((everyInput)));
        }
        else {
            EXPECT_FALSE(testMatrix->isTemporaryRowInputCorrect((everyInput)));
        }
        numOfDigits++;
    }

    for (auto& everyInput : tesyStringInputMixedDigitsAndCharacters) {
        EXPECT_FALSE(testMatrix->isTemporaryRowInputCorrect(everyInput));
    }

    //when row is empty
    EXPECT_FALSE(testMatrix->isTemporaryRowInputCorrect(emptyRow));

    delete testMatrix;

    testMatrix = new Matrix(testRows10, testColumns1);
    numOfDigits = 1;

    for (auto& everyInput : testStringInputOnlyDigits) {
        if (numOfDigits == testColumns1) {
            EXPECT_TRUE(testMatrix->isTemporaryRowInputCorrect((everyInput)));
        }
        else {
            EXPECT_FALSE(testMatrix->isTemporaryRowInputCorrect((everyInput)));
        }
        numOfDigits++;
    }

    for (auto& everyInput : tesyStringInputMixedDigitsAndCharacters) {
        EXPECT_FALSE(testMatrix->isTemporaryRowInputCorrect(everyInput));
    }

    //when row is empty
    EXPECT_FALSE(testMatrix->isTemporaryRowInputCorrect(emptyRow));
}

TEST_F(MatrixTest, ShouldReturnVectorOfIntsFromTemporaryRowInput)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    std::vector<double> testVectorOfInts;
    unsigned counter = 0;
    for (auto everyVectorOfInts : digitsEqualToStringInputOnlyDigits) {
        testVectorOfInts = testMatrix->createVectorOfIntsFromTemporaryRowInput(testStringInputOnlyDigits[counter]);
        EXPECT_EQ(testVectorOfInts, everyVectorOfInts);
        counter++;
    }
}

TEST_F(MatrixTest, ShouldLoadMatrixContent)
{
    testMatrix = new Matrix();

    testMatrix->loadExternalMatrix(newMatrixContent);

    EXPECT_EQ(testMatrix->getMatrix(), *newMatrixContent);
    EXPECT_EQ(testMatrix->getRows(), testRows3);
    EXPECT_EQ(testMatrix->getColumns(), testColumns3);
}

TEST_F(MatrixTest, ShouldCreateMatrixWithAccessByColumns)
{
    testMatrix = new Matrix(testRows5, testColumns7);
    testMatrix->loadExternalMatrix(newMatrixContent);

    EXPECT_EQ(testMatrix->getMatrixWithAccessByColumns(), *newMatrixContentWithAccessByColumns);
}

TEST_F(MatrixTest, ShouldCopyMatrixWithCopyCtor)
{
    Matrix firstMatrix = Matrix(testRows5, testColumns7);
    firstMatrix.loadExternalMatrix(newMatrixContent);
    Matrix secondMatrix = Matrix(firstMatrix);

    EXPECT_EQ(firstMatrix.getMatrix(), *newMatrixContent);
    EXPECT_EQ(firstMatrix.getMatrixWithAccessByColumns(), *newMatrixContentWithAccessByColumns);
    EXPECT_EQ(secondMatrix.getMatrix(), *newMatrixContent);
    EXPECT_EQ(secondMatrix.getMatrixWithAccessByColumns(), *newMatrixContentWithAccessByColumns);
}

TEST_F(MatrixTest, ShouldCopyMatrixWithCopyAssignmentOperator)
{
    Matrix firstMatrix = Matrix(testRows5, testColumns7);
    firstMatrix.loadExternalMatrix(newMatrixContent);
    Matrix secondMatrix;
    secondMatrix = firstMatrix;

    EXPECT_EQ(firstMatrix.getMatrix(), *newMatrixContent);
    EXPECT_EQ(firstMatrix.getMatrixWithAccessByColumns(), *newMatrixContentWithAccessByColumns);
    EXPECT_EQ(secondMatrix.getMatrix(), *newMatrixContent);
    EXPECT_EQ(secondMatrix.getMatrixWithAccessByColumns(), *newMatrixContentWithAccessByColumns);
}
