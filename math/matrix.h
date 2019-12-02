#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <cmath>
#include "spdlog/spdlog.h"

template<typename T>
class Matrix {
    private: 
        T** matrix;
        uint row_size;
        uint col_size;
        void init_mat() {
            for(uint i = 0; i < row_size; ++i) {
                for(uint j = 0; j < col_size; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
    public: 
        Matrix(uint r_size, u_int c_size) {
            row_size = r_size;
            col_size = c_size;
            matrix = new T*[r_size];
            for(unsigned int i = 0; i < r_size; i++) {
                matrix[i] = new T[c_size];
            }
            init_mat();
        }

        ~Matrix() {
            delete [] *matrix;
            delete [] matrix;
        }

        Matrix<T> operator+(Matrix<T>const&mat_a) {
            Matrix<T>resultant_mat(mat_a.get_row_size(), mat_a.get_col_size());
            for(unsigned int i = 0; i < resultant_mat.get_row_size(); ++i) {
                for(unsigned int j = 0; j < resultant_mat.get_col_size(); ++j) {
                    auto resultant_value = this->get_matrix_value(i, j) + mat_a.get_matrix_value(i, j);
                    resultant_mat.set_matrix_value(i, j, resultant_value);
                }
            }
            return resultant_mat;
        }

        Matrix<T>operator-(Matrix<T>const&mat_a) {
            Matrix<T>resultant_mat(mat_a.get_row_size(), mat_a.get_col_size());
            for(unsigned int i = 0; i < resultant_mat.get_row_size(); ++i) {
                for(unsigned int j = 0; j < resultant_mat.get_col_size(); ++j) {
                    auto r_value = this->get_matrix_value(i, j) - mat_a.get_matrix_value(i, j);
                    resultant_mat.set_matrix_value(i, j, r_value);
                }
            }      
            return resultant_mat;
        }

        Matrix<T>operator/(Matrix<T>const&mat_a) {
            Matrix<T>resultant_mat(mat_a.get_row_size(), mat_a.get_col_size());
            for(unsigned int i = 0; i < resultant_mat.get_row_size(); ++i) {
                for(unsigned int j = 0; j < resultant_mat.get_col_size(); ++j) {
                    auto r_value = this->get_matrix_value(i, j) / mat_a.get_matrix_value(i, j);
                    resultant_mat.set_matrix_value(i, j, r_value);
                }
            }      
            return resultant_mat;
        }

        void matrix_print_test(Matrix<T>const&mat_one, Matrix<T>const&mat_two);
        void set_matrix_value(uint r_spot, uint col_spot, T value);
        T get_matrix_value(uint r_spot, uint col_spot);
        uint get_row_size() const;
        uint get_col_size() const;
};

template<typename T>
void Matrix<T>::matrix_print_test(Matrix<T>const&mat_one, Matrix<T>const&mat_two) {
    auto mat_one_col = 0;
    auto mat_two_row = 0;
    for(unsigned int i = 0; i < mat_one.get_row_size() - 1; i++) {
        auto value_to_print = mat_one.get_matrix_value(i, mat_one_col);
        spdlog::info(value_to_print);
        if(i == mat_one.get_row_size() - 1 && mat_one_col < mat_one.get_col_size() - 1) {
            mat_one_col = mat_one_col + 1;
        }
    }
}

template<typename T>
void Matrix<T>::set_matrix_value(uint r_spot, uint c_spot, T value) {
    if(r_spot > get_row_size() || c_spot > get_col_size() || (r_spot < 0 && c_spot < 0) ) {
        spdlog::error("one of the following errors has happened with a matrix, either one of the row values is too small.");
        spdlog::error("or the other following error has occurred, with that being the row spot or column spot for setting the matrix value is bigger than the row or column size.");
    } 

    if(r_spot == 0 || c_spot == 0) {
        matrix[r_spot][c_spot] = value;
    } else {
        matrix[r_spot][c_spot] = value;
    }
}

template<typename T>
T Matrix<T>::get_matrix_value(uint r_spot, uint c_spot) {
    return matrix[r_spot][c_spot];
}

template<typename T>
uint Matrix<T>::get_row_size() const {
    return row_size;
}

template<typename T>
uint Matrix<T>::get_col_size() const {
    return col_size;
}
#endif