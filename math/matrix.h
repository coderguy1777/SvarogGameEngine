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
    public: 
        Matrix(uint r_size, u_int c_size) {
            matrix = new T*[r_size];
            for(unsigned int i = 0; i < r_size; i++) {
                matrix[i] = new T[c_size];
            }
        }

        ~Matrix() {
            delete [] *matrix;
            delete [] matrix;
        }

        void set_matrix_value(uint r_spot, uint col_spot, T value);
        T get_matrix_value(uint r_spot, uint col_spot) const;
        uint get_row_size() const;
        uint get_col_size() const;
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
            Matrix<T>resultant_mat(mat_a.get_row_size(), mat_a.get_col_size()):
            for(unsigned int i = 0; i < resultant_mat.get_row_size(); ++i) {
                for(unsigned int j = 0; j < resultant_mat.get_col_size(); ++j) {
                    auto r_value = this->get_matrix_value(i, j) - mat_a.get_matrix_value(i, j);
                    resultant_matrix.set_matrix_value(i, j, r_value);
                }
            }      
            return resultant_mat;
        }

        Matrix<T>operator/(Matrix<T>const&mat_a) {
            Matrix<T>resultant_mat(mat_a.get_row_size(), mat_a.get_col_size()):
            for(unsigned int i = 0; i < resultant_mat.get_row_size(); ++i) {
                for(unsigned int j = 0; j < resultant_mat.get_col_size(); ++j) {
                    auto r_value = this->get_matrix_value(i, j) / mat_a.get_matrix_value(i, j);
                    resultant_matrix.set_matrix_value(i, j, r_value);
                }
            }      
            return resultant_mat;
        }
};

template<typename T>
void Matrix<T>::set_matrix_value(uint r_spot, uint c_spot, T value) {
    if(r_spot > get_row_size() || c_spot > get_col_size () || (r_spot < 0 && c_spot < 0) ) {
        spdlog::error("one of the following errors has happened with a matrix, either one of the row values is too small.");
        spdlog::error("or the other following error has occurred, with that being the row spot or column spot for setting the matrix value is bigger than the row or column size.");
    } else {
        matrix[r_spot][c_spot] = value;
    }

    if(r_spot == 0 || c_spot == 0) {
        matrix[r_spot][c_spot] = value;
    } else {
        matrix[r_spot - 1][c_spot - 1] = value;
    }
}

template<typename T>
T Matrix<T>::get_matrix_value(uint r_spot, uint c_spot) const {
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