//
//  matrix.cpp
//  coursera
//
//  Created by Денис Домашевич on 10/6/18.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>

class Matrix {
public:
    Matrix() {
        this -> num_rows = 0;
        this -> num_columns = 0;
    }
    
    Matrix(const int64_t num_rows, const int64_t num_columns) {
        Reset(num_rows, num_columns);
    }
    
    void Reset(const int64_t num_rows, const int64_t num_columns) {
        if(num_rows < 0) {
            throw std::out_of_range("num_rows must be >= 0");
        }
        if(num_columns < 0) {
            throw std::out_of_range("num_columns must be >= 0");
        }
        
        this -> num_rows = num_rows;
        this -> num_columns = num_columns;
        matrix.resize(num_rows, std::vector <int64_t>(num_columns));
    }
     
    int64_t At(const int64_t row, const int64_t colum) const {
        return matrix.at(row).at(colum);
    }
     
    int64_t &At(const int64_t row, const int64_t colum) {
        return matrix.at(row).at(colum);
    }
    
    int64_t GetNumRows() const {
        return num_rows;
    }
    
    int64_t GetNumColumns() const {
        return num_columns;
    }
    
private:
    int64_t num_rows;
    int64_t num_columns;
    std::vector < std::vector <int64_t> > matrix;
};

bool operator == (const Matrix &A, const Matrix &B) {
    if(A.GetNumRows() != B.GetNumRows() || A.GetNumColumns() != B.GetNumColumns()) {
        return false;
    }
    for(size_t i = 0; i < A.GetNumRows(); ++i) {
        for(size_t j = 0; j < A.GetNumColumns(); ++j) {
            if(A.At(i, j) != B.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

Matrix operator + (const Matrix &A, const Matrix &B) {
    if(A.GetNumRows() != B.GetNumRows()) {
        throw std::invalid_argument("Mismatched number of rows");
    }
    if(A.GetNumColumns() != B.GetNumColumns()) {
        throw std::invalid_argument("Mismatched number of columns");
    }
    
    Matrix sum(A.GetNumRows(), A.GetNumColumns());
    for(size_t i = 0; i < A.GetNumRows(); ++i) {
        for(size_t j = 0; j < A.GetNumColumns(); ++j) {
            sum.At(i, j) = A.At(i, j) +  B.At(i, j);
        }
    }
    return sum;
}

std::istream& operator >> (std::istream& in, Matrix& matrix) {
    int64_t num_rows, num_columns;
    in >> num_rows >> num_columns;
    
    matrix.Reset(num_rows, num_columns);
    for(size_t i = 0; i < num_rows; ++i) {
        for(size_t j = 0; j < num_columns; ++j) {
            in >> matrix.At(i, j);
        }
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const Matrix& matrix) {
    std::cout << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << std::endl;
    for(size_t i = 0; i < matrix.GetNumRows(); ++i) {
        for(size_t j = 0; j < matrix.GetNumColumns(); ++j) {
            out << matrix.At(i, j) << ' ';
        }
        out << std::endl;
    }
    return out;
}

int main(int argc, const char * argv[]) {
   
    Matrix one;
    Matrix two;
    
    std::cin >> one >> two;
    std::cout << one + two << std::endl;

    return 0;
}

