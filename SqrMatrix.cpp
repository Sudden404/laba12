#include "SqrMatrix.h"
#include "my.lib.h"

bool SqrMatrix::operator == (const SqrMatrix& a){
    if (this -> n != a.n)
        return false;
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
            if(this->matrix_add[i][j] != a.matrix_add[i][j])
                return false;
    return true;
}
SqrMatrix& SqrMatrix::operator = (const SqrMatrix& a){
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
            for (int i = 0; i < n; i++)
                delete[] matrix_add[i];
            delete[] matrix_add;
        }
}
void SqrMatrix::Print()const{
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
void SqrMatrix::Div(SqrMatrix& a,SqrMatrix &b){
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
    double** Original = new double* [n];
    for (int i = 0; i < n; i++)
        Original[i] = new double [n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Original[i][j] = b.matrix_add[i][j];
    double key = Determinant(Original,b.n);
    printf("det = %.2f\n",key);
    printf("-----------\n");
    if (key == 0){
        printf("error,determinant = 0");
        return;
    }
    inversion(Original,b.n);
    Print_mas(Original,b.n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            double key = 0;
            for(int r = 0; r < n; r++){
                key += (a.matrix_add[i][r] * Original[r][j]);
            }
            matrix_add[i][j] = key;
        }
    }
    for (int i = 0; i < n; i++)
        delete [] Original[i];
    delete [] Original;
}
