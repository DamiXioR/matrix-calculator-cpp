#include "matrix.hpp"
#include <algorithm>
#include <iostream>

Matrix::Matrix(unsigned rows, unsigned columns) : rows_(rows), columns_(columns){
    createEmptyMatrix();
}

Matrix::~Matrix(){
    delete matrix_;
}

void Matrix::createEmptyMatrix(){
    matrix_ = new std::vector<std::vector<int>>(rows_);
    std::for_each(getMatrix()->begin(),getMatrix()->end(),[this](std::vector<int>& everyRow){
        everyRow.resize(getColumns());
    });
}

void Matrix::printMatrix(){
    std::for_each(getMatrix()->begin(),getMatrix()->end(),[](std::vector<int>& everyRow){
        std::for_each(everyRow.begin(),everyRow.end(),[](int& everyRowElement){
            std::cout << everyRowElement << " ";
        });
        std::cout << "\n";
    });
}
