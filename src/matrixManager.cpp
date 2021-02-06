#include "matrixManager.hpp"

#include <algorithm>

MatrixManager::MatrixManager()
{
    matrixHolder_ = new std::map<char, Matrix>();
};

MatrixManager::~MatrixManager()
{
    delete matrixHolder_;
};

bool MatrixManager::addNewMatrix(char key, Matrix* newMatrix)
{
    auto checkIfInserted = matrixHolder_->emplace(key, *newMatrix);
    return checkIfInserted.second;
}

Matrix* MatrixManager::addTwoMatrixes(char firstMatrixKey, char secondMatrixKey)
{
    Matrix* result = new Matrix();
    if (getMatrixHolder()->size() > 1) {
        auto firstMatrixIterator = getMatrixHolder()->find(firstMatrixKey);
        auto secondMatrixIterator = getMatrixHolder()->find(secondMatrixKey);

        if (firstMatrixIterator != getMatrixHolder()->end() && secondMatrixIterator != getMatrixHolder()->end()) {
            std::vector<std::vector<double>> firstMatrix = firstMatrixIterator->second.getMatrix();
            std::vector<std::vector<double>> secondMatrix = secondMatrixIterator->second.getMatrix();

            bool areRowsEqual = firstMatrixIterator->second.getRows() == secondMatrixIterator->second.getRows();
            bool areColumnsEqual = firstMatrixIterator->second.getColumns() == secondMatrixIterator->second.getColumns();

            if (areRowsEqual && areColumnsEqual) {
                std::vector<std::vector<double>>* thirdMatrix = &result->getMatrix();

                std::transform(firstMatrix.begin(), firstMatrix.end(), secondMatrix.begin(), std::back_inserter(*thirdMatrix),
                               [](std::vector<double> firstVector, std::vector<double> secondVector) {
                                   std::vector<double> everyRow;

                                   std::transform(firstVector.begin(), firstVector.end(), secondVector.begin(), std::back_inserter(everyRow),
                                                  [](double firstNum, double secondNum) {
                                                      double sumOfTwoRows = firstNum + secondNum;
                                                      return sumOfTwoRows;
                                                  });
                                   return everyRow;
                               });
            }
        }
    }
    return result;
}
