//
// Created by User on 02.05.2022.
//

#ifndef LABA12_SQRMATRIX_H
#define LABA12_SQRMATRIX_H
#include <iostream>


class SqrMatrix {
private:
    double** matrix_add;
    size_t n;
public:
    SqrMatrix(size_t n);
    SqrMatrix();
    ~SqrMatrix();
    SqrMatrix& operator = (const SqrMatrix& a){
        if(&a == this){
            return *this;
        }
        for(int i = 0; i < n; i++)
            delete[] matrix_add[i];
        delete[] matrix_add;
        n = a.n;

        matrix_add = new double* [n];
        for(int i = 0;i<n;i++)
            matrix_add[i] = new double [n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                matrix_add[i][j] = a.matrix_add[i][j];

        return *this;
    }
    void Print();
    void Sum(SqrMatrix&, SqrMatrix&);
    void Sub(SqrMatrix&, SqrMatrix&);
    void Multiply(SqrMatrix&, SqrMatrix&);
    void Multiply(SqrMatrix&,const int&);
    void Set(const int&,const int&,const double&);
    void Div(SqrMatrix&, SqrMatrix&);
};
void inversion(double**,size_t);

#endif //LABA12_SQRMATRIX_H
