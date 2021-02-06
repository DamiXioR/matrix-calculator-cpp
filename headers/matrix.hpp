#pragma once
#include <string>
#include <vector>

class Matrix {
public:
    Matrix(unsigned rows = 0, unsigned columns = 0);
    Matrix(const Matrix& anotherMatrix);
    Matrix& operator=(Matrix& anotherMatrix);
    ~Matrix();

    void createEmptyMatrix();
    void setMatrixValues();
    void swapMatrix(std::vector<std::vector<double>>* anotherMatrix);
    bool isTemporaryRowInputCorrect(std::string temporaryRow);
    bool isInputValuesEqualToColumnsSize(std::string temporaryRow);
    bool isInputValuesConsistsDigits(std::string temporaryRow);

    std::vector<double> createVectorOfIntsFromTemporaryRowInput(std::string temporaryRow);

    void printMatrix();

    std::vector<std::vector<double>>& getMatrix() const
    {
        return *matrix_;
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
    std::vector<std::vector<double>>* matrix_{};
    std::size_t rows_{};
    std::size_t columns_{};
};
