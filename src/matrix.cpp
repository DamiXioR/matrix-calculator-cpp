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
}

Matrix::Matrix(const Matrix& anotherMatrix)
{
    rows_ = anotherMatrix.getRows();
    columns_ = anotherMatrix.getColumns();
    matrix_ = new std::vector<std::vector<double>>(rows_);
    *matrix_ = *(anotherMatrix.getMatrix());
}

Matrix& Matrix::operator=(Matrix& anotherMatrix)
{
    rows_ = anotherMatrix.getRows();
    columns_ = anotherMatrix.getColumns();
    matrix_ = new std::vector<std::vector<double>>(rows_);
    *matrix_ = *(anotherMatrix.getMatrix());
    return *this;
}

Matrix::~Matrix()
{
    delete matrix_;
}

void Matrix::createEmptyMatrix()
{
    matrix_ = new std::vector<std::vector<double>>(rows_);
    std::for_each(getMatrix()->begin(), getMatrix()->end(), [this](std::vector<double>& everyRow) {
        everyRow.resize(getColumns());
    });
}

void Matrix::setMatrixValues()
{
    std::vector<std::vector<double>>* temporaryMatrix = getMatrix();
    std::string temporaryRow = "";
    unsigned rowsCounter = 0;

    std::cout << "Give me an input! Your matrix has " << getRows() << " rows and " << getColumns() << " columns.\n";

    while (rowsCounter < getRows()) {
        std::getline(std::cin, temporaryRow);
        if (isTemporaryRowInputCorrect(temporaryRow)) {
            (*temporaryMatrix)[rowsCounter] = createVectorOfIntsFromTemporaryRowInput(temporaryRow);
            rowsCounter++;
        }
        else {
            std::cout << "Wrong input. Matrix size [" << getRows() << "x" << getColumns() << "]. Please try again!\n";
        }
    }
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
    if (valuesCounter > getColumns() || valuesCounter < getColumns()) {
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
    std::for_each(getMatrix()->begin(), getMatrix()->end(), [](std::vector<double>& everyRow) {
        std::for_each(everyRow.begin(), everyRow.end(), [](double everyRowElement) {
            std::cout << std::right << std::setw(10) << everyRowElement << "| ";
        });
        std::cout << "\n";
    });
}
