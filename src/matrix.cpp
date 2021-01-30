#include "matrix.hpp"
#include <algorithm>
#include <iostream>

Matrix::Matrix(unsigned rows, unsigned columns){
    matrix_ = new std::vector<std::vector<int>>(rows);
    std::for_each(matrix_->begin(),matrix_->end(),[columns](std::vector<int>& everyRow){
        everyRow.resize(columns);
    });
}

Matrix::~Matrix(){
    delete matrix_;
}

void Matrix::printMatrix(){
    std::for_each(matrix_->begin(),matrix_->end(),[](std::vector<int>& everyRow){
        std::for_each(everyRow.begin(),everyRow.end(),[](int& everyRowElement){
            std::cout << everyRowElement << " ";
        });
        std::cout << "\n";
    });
}
