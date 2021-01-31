#include "matrix.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>

Matrix::Matrix(unsigned rows, unsigned columns)
    : rows_(rows), columns_(columns)
{
    createEmptyMatrix();
}

Matrix::~Matrix()
{
    delete matrix_;
}

void Matrix::createEmptyMatrix()
{
    matrix_ = new std::vector<std::vector<int>>(rows_);
    std::for_each(getMatrix()->begin(), getMatrix()->end(), [this](std::vector<int>& everyRow) {
        everyRow.resize(getColumns());
    });
}

void Matrix::setMatrixValues()
{
    std::vector<std::vector<int>> temporaryMatrix = *getMatrix();
    std::string temporaryRow = "";
    unsigned rowsCounter = 1;

    std::cout << "Give me an input! Your matrix has " << getRows() << " rows and " << getColumns() << " columns.\n";

    while (rowsCounter <= getRows()) {
        std::getline(std::cin, temporaryRow);
        if (isTemporaryRowInputCorrect(temporaryRow)) {
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
    if (!(isCorrect = isInputValuesConsistsDigits(temporaryRow))) {
        return isCorrect;
    }
    isCorrect = isInputValuesEqualToColumnsSize(temporaryRow);
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
        if (checkedCharacter == ' ') {
            isTrue = true;
        }
        else {
            isTrue = std::isdigit(checkedCharacter);
        }
        return isTrue;
    });
    return isConsistsDigit;
}

std::vector<int> Matrix::createVectorOfIntsFromTemporaryRowInput(std::string temporaryRow)
{
    std::vector<int> digits;
    std::stringstream contentBySpacesSeparator(temporaryRow);
    std::string wholeDigit = "";

    while (contentBySpacesSeparator >> wholeDigit) {
        digits.emplace_back(std::stoi(wholeDigit));
    }

    return digits;
}

void Matrix::printMatrix()
{
    std::for_each(getMatrix()->begin(), getMatrix()->end(), [](std::vector<int>& everyRow) {
        std::for_each(everyRow.begin(), everyRow.end(), [](int& everyRowElement) {
            std::cout << everyRowElement << " ";
        });
        std::cout << "\n";
    });
}
