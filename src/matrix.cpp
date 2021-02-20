#include "matrix.hpp"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

Matrix::Matrix(unsigned rows, unsigned columns)
    : rows_(rows), columns_(columns)
{
    createEmptyMatrix();
    createMatrixWithAccessByColumns();
}

Matrix::Matrix(const Matrix& anotherMatrix)
{
    rows_ = anotherMatrix.rows_;
    columns_ = anotherMatrix.columns_;
    matrix_ = new std::vector<std::vector<double>>(rows_);
    *matrix_ = *(anotherMatrix.matrix_);
    matrixWithAccessByColumns_ = new std::vector<std::vector<double>>(columns_);
    *matrixWithAccessByColumns_ = *(anotherMatrix.matrixWithAccessByColumns_);
}

Matrix& Matrix::operator=(Matrix& anotherMatrix)
{
    rows_ = anotherMatrix.rows_;
    columns_ = anotherMatrix.columns_;
    delete matrix_;
    matrix_ = new std::vector<std::vector<double>>(rows_);
    *matrix_ = *(anotherMatrix.matrix_);
    delete matrixWithAccessByColumns_;
    matrixWithAccessByColumns_ = new std::vector<std::vector<double>>(columns_);
    *matrixWithAccessByColumns_ = *(anotherMatrix.matrixWithAccessByColumns_);
    return *this;
}

Matrix::~Matrix()
{
    delete matrix_;
    delete matrixWithAccessByColumns_;
}

void Matrix::createEmptyMatrix()
{
    matrix_ = new std::vector<std::vector<double>>(rows_);
    std::for_each(matrix_->begin(), matrix_->end(), [this](std::vector<double>& everyRow) {
        everyRow.resize(columns_);
    });
}

void Matrix::createMatrixWithAccessByColumns()
{
    if (matrixWithAccessByColumns_ != nullptr) {
        delete matrixWithAccessByColumns_;
    }
    matrixWithAccessByColumns_ = new std::vector<std::vector<double>>(columns_);

    std::for_each(matrix_->begin(), matrix_->end(),
                  [this](std::vector<double> sourceMatrixRow) {
                      unsigned counter = 0;
                      for (auto& value : sourceMatrixRow) {
                          (*matrixWithAccessByColumns_)[counter++].push_back(value);
                      }
                  });
}

void Matrix::setMatrixValues()
{
    std::string temporaryRow = "";
    unsigned rowsCounter = 0;

    std::cout << "Give me an input! Your matrix has " << rows_ << " rows and " << columns_ << " columns.\n";

    while (rowsCounter < rows_) {
        std::getline(std::cin, temporaryRow);
        if (isTemporaryRowInputCorrect(temporaryRow)) {
            (*matrix_)[rowsCounter] = createVectorOfIntsFromTemporaryRowInput(temporaryRow);
            rowsCounter++;
        }
        else {
            std::cout << "Wrong input. Matrix size [" << rows_ << "x" << columns_ << "]. Please try again!\n";
        }
    }
    createMatrixWithAccessByColumns();
}

bool Matrix::loadExternalMatrix(std::vector<std::vector<double>>* anotherMatrix)
{
    bool isCorrect = true;
    *matrix_ = *anotherMatrix;
    rows_ = matrix_->size();

    columns_ = matrix_->front().size();
    for_each(matrix_->begin(), matrix_->end(), [this, &isCorrect](std::vector<double> everyRow) {
        if (columns_ != everyRow.size()) {
            isCorrect = false;
        }
    });
    if (isCorrect) {
        createMatrixWithAccessByColumns();
    }
    return isCorrect;
}

bool Matrix::isTemporaryRowInputCorrect(std::string temporaryRow)
{
    bool isCorrect = true;
    if (isCorrect = temporaryRow.empty()) {
        return !isCorrect;
    }
    if (!(isCorrect = isInputValuesConsistsDigits(temporaryRow))) {
        return isCorrect;
    }
    if (!(isCorrect = isInputValuesEqualToColumnsSize(temporaryRow))) {
        return isCorrect;
    }
    return isCorrect;
}

bool Matrix::isInputValuesEqualToColumnsSize(std::string temporaryRow)
{
    std::stringstream contentBySpacesSeparator(temporaryRow);
    std::string everyContent = "";
    unsigned valuesCounter = 0;
    while (contentBySpacesSeparator >> everyContent) {
        valuesCounter++;
    }
    bool isEqual = true;
    if (valuesCounter > columns_ || valuesCounter < columns_) {
        isEqual = false;
    }
    return isEqual;
}

bool Matrix::isInputValuesConsistsDigits(std::string temporaryRow)
{
    bool isConsistsDigit = true;
    isConsistsDigit = std::all_of(temporaryRow.begin(), temporaryRow.end(), [&isConsistsDigit](char checkedCharacter) {
        bool isTrue = true;
        if ((checkedCharacter == ' ') || (checkedCharacter == '-')) {
            isTrue = true;
        }
        else {
            isTrue = std::isdigit(checkedCharacter);
        }
        return isTrue;
    });
    return isConsistsDigit;
}

std::vector<double> Matrix::createVectorOfIntsFromTemporaryRowInput(std::string temporaryRow)
{
    std::vector<double> digits;
    std::stringstream contentBySpacesSeparator(temporaryRow);
    std::string wholeDigit = "";

    while (contentBySpacesSeparator >> wholeDigit) {
        digits.emplace_back(std::stoi(wholeDigit));
    }

    return digits;
}

void Matrix::printMatrix()
{
    std::for_each(matrix_->begin(), matrix_->end(), [](std::vector<double>& everyRow) {
        std::for_each(everyRow.begin(), everyRow.end(), [](double everyRowElement) {
            std::cout << std::right << std::setw(10) << everyRowElement << "| ";
        });
        std::cout << "\n";
    });
}
