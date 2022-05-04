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
    bool operator == (const SqrMatrix& a);
    SqrMatrix& operator = (const SqrMatrix& a);
    void Print() const;
    void Sum(SqrMatrix&, SqrMatrix&);
    void Sub(SqrMatrix&, SqrMatrix&);
    void Multiply(SqrMatrix&, SqrMatrix&);
    void Multiply(SqrMatrix&,const int&);
    void Set(const int&,const int&,const double&);
    void Div(SqrMatrix&, SqrMatrix&);
};
/*void inversion(double**, size_t);
double Determinant(double**, size_t);
void GetMatr(double**, double**, int i, int j, int m);
void Print_mas(double**, int);*/

#endif //LABA12_SQRMATRIX_H
