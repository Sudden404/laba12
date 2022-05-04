#include "SqrMatrix.h"
#include "my.lib.h"

int main() {
    SqrMatrix a(3);
    SqrMatrix b(3);
    for(int i = 1;i<4;i++)
        for(int j = 1;j<4;j++)
            b.Set(i,j,i+j);
    b.Set(1,1,4);
    a.Set(1, 2, 9.82);
    a.Print();
    b.Print();
    SqrMatrix d;
    d.Sum(a,b);
    d.Print();
    d.Multiply(a,b);
    d.Print();
    d.Sub(a,b);
    d.Print();
    d.Multiply(a,2);
    d.Print();
    d.Div(a,b);
    d.Print();
    return 0;
}
