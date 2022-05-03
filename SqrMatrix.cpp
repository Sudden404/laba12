//
// Created by User on 02.05.2022.
//

#include "SqrMatrix.h"


SqrMatrix::SqrMatrix(size_t n){
    this -> n = n;
    this -> matrix_add = new double* [n];
    for(int i = 0;i<n;i++)
        this -> matrix_add[i] = new double [n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            this -> matrix_add[i][j] = 0;
}
SqrMatrix::SqrMatrix(){
    this->n = 0;
    matrix_add = nullptr;
}
SqrMatrix::~SqrMatrix(){
        if (this ->n > 0) {
            printf("%d",n);
            for (int i = 0; i < n; i++)
                delete[] matrix_add[i];
            delete[] matrix_add;
        }
}
/*SqrMatrix& SqrMatrix::operator=(const SqrMatrix& a){
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
}*/
void SqrMatrix::Print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%.2f\t",matrix_add[i][j]);
        printf("\n");
    }
    for(int i = 0; i< n; i++)
        printf("-------");
    printf("\n");
}
void SqrMatrix::Set(const int& i,const int& j,const double& val){
    if ((i <= n) && (j <= n) && (i >= 1) && (j>= 1))
        this -> matrix_add[i-1][j-1] = val;
}
void SqrMatrix::Sum(SqrMatrix& a,SqrMatrix& b){
    if (a.n != b.n){
        printf("Error,...");
        return;
    }
    if (n != a.n){
        for(int i = 0; i < n; i++)
            delete[] matrix_add[i];
        delete[] matrix_add;
        this ->n = a.n;

        matrix_add = new double* [n];
        for(int i = 0;i<n;i++)
            matrix_add[i] = new double [n];
    }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix_add[i][j] = (a.matrix_add[i][j] + b.matrix_add[i][j]);

}
void SqrMatrix::Multiply(SqrMatrix& a,SqrMatrix& b){
    if (a.n != b.n){
        printf("Error,...");
        return;
    }
    if (n != a.n){
        for(int i = 0; i < n; i++)
            delete[] matrix_add[i];
        delete[] matrix_add;
        this ->n = a.n;

        matrix_add = new double* [n];
        for(int i = 0;i<n;i++)
            matrix_add[i] = new double [n];

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            double key = 0;
            for(int r = 0; r < n; r++){
                key += (a.matrix_add[i][r] * b.matrix_add[r][j]);
            }
            matrix_add[i][j] = key;
        }
    }
}
void SqrMatrix::Sub(SqrMatrix& a,SqrMatrix& b){
    if (a.n != b.n){
        printf("Error,...");
        return;
    }
    if (n != a.n){
        for(int i = 0; i < n; i++)
            delete[] matrix_add[i];
        delete[] matrix_add;
        this ->n = a.n;

        matrix_add = new double* [n];
        for(int i = 0;i<n;i++)
            matrix_add[i] = new double [n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix_add[i][j] = (a.matrix_add[i][j] - b.matrix_add[i][j]);
}
void SqrMatrix::Multiply(SqrMatrix& a,const int& b){
    if (n != a.n){
        for(int i = 0; i < n; i++)
            delete[] matrix_add[i];
        delete[] matrix_add;
        this ->n = a.n;

        matrix_add = new double* [n];
        for(int i = 0;i<n;i++)
            matrix_add[i] = new double [n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix_add[i][j] = (a.matrix_add[i][j] * b);
}
void SqrMatrix::Div(SqrMatrix& a,SqrMatrix& b){
    if (a.n != b.n){
        printf("Error,...");
        return;
    }
    if (this -> n != a.n){
        for(int i = 0; i < n; i++)
            delete[] matrix_add[i];
        delete[] matrix_add;
        this ->n = a.n;

        matrix_add = new double* [n];
        for(int i = 0;i<n;i++)
            matrix_add[i] = new double [n];
    }
    inversion(b.matrix_add,b.n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            double key = 0;
            for(int r = 0; r < n; r++){
                key += (a.matrix_add[i][r] * b.matrix_add[r][j]);
            }
            matrix_add[i][j] = key;
        }}
}
void inversion(double **Original, size_t n){
    double tmp;
    double** Support = new double *[n];
    for (int i = 0; i < n; i++)
        Support[i] = new double [n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            Support[i][j] = 0.0;
            if (i == j)
                Support[i][j] = 1.0;
        }
    for (int k = 0; k < n; k++){
        tmp = Original[k][k];
        for (int j = 0; j < n; j++){
            Original[k][j] = Original[k][j] / tmp;
            Support[k][j] = Support[k][j] / tmp;
        }

        for (int i = k + 1; i < n; i++){
            tmp = Original[i][k];
            for (int j = 0; j < n; j++){
                Original[i][j] -= Original[k][j] * tmp;
                Support[i][j] -= Support[k][j] * tmp;
            }
        }
    }
    for (int k = n - 1; k > 0; k--){
        for (int i = k - 1; i >= 0; i--){
            tmp = Original[i][k];
            for (int j = 0; j < n; j++){
                Original[i][j] -= Original[k][j] * tmp;
                Support[i][j] -= Support[k][j] * tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Original[i][j] = Support[i][j];

    for (int i = 0; i < n; i++)
        delete [] Support[i];
    delete [] Support;
}