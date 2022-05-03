
#include "SqrMatrix.h"

int main() {
    SqrMatrix a(3);
    SqrMatrix b(3);
    b.Set(1, 1, 3.14);
    b.Set(2, 2, 3.14);
    b.Set(3, 3, 3.14);
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
