#pragma once
#include <vector>
#include <string>

class Matrix {
public:
    Matrix(unsigned rows, unsigned columns);
    ~Matrix();

    void createEmptyMatrix();
    void setMatrixValues();
    bool isTemporaryRowInputCorrect(std::string temporaryRow);
    bool isInputValuesEqualToColumnsSize(std::string temporaryRow);
    bool isInputValuesConsistsDigits(std::string temporaryRow);

    std::vector<int> createVectorOfIntsFromTemporaryRowInput(std::string temporaryRow);

    void printMatrix();

    std::vector<std::vector<int>>* getMatrix() const
    {
        return matrix_;
    }
    std::size_t getRows() const
    {
        return rows_;
    }

    std::size_t getColumns() const
    {
        return columns_;
    }

private:
    std::vector<std::vector<int>>* matrix_{};
    std::size_t rows_{};
    std::size_t columns_{};
};