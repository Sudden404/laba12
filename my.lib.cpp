#include "my.lib.h"

void inversion(double** Original, size_t n){
    double tmp;
    double** Support = new double* [n];
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
void GetMatr(double** mas, double** p, int i, int j, int m){
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<m - 1; ki++){
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj<m - 1; kj++){
            if (kj == j) dj = 1;
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}
double Determinant(double** mas, size_t m){
    int i, k, n;
    double d;
    double **new_mas;
    new_mas = new double * [m];
    for (i = 0; i<m; i++)
        new_mas[i] = new double[m];
    d = 0;
    k = 1;
    n = m - 1;
    if (m == 1) {
        d = mas[0][0];
        return(d);
    }
    if (m == 2) {
        d = (mas[0][0] * mas[1][1]) - (mas[1][0] * mas[0][1]);
        return(d);
    }
    if (m>2) {
        for (i = 0; i<m; i++) {
            GetMatr(mas, new_mas, i, 0, m);
            d = d + k * mas[i][0] * Determinant(new_mas, n);
            k = -k;
        }
    }
    for (i = 0; i<m; i++)
        delete [] new_mas[i];
    delete [] new_mas;
    return(d);
}
void Print_mas(double** mas,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%.2f\t",mas[i][j]);
        printf("\n");
    }
    for(int i = 0; i < n; i++)
        printf("-------");
    printf("\n");
}