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

#endif //LABA12_SQRMATRIX_H
