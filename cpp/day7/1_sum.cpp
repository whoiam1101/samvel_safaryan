#include <iostream>

using namespace std;

void sum1(int *, int *, int *);
void sum2(int &, int &, int &);
void sum3(int  , int  , int &);
void sum4(int  , int *, int &);
void sum5(int *, int *, int &);

void _beautifullPrint(string, int, int, int);

int main() {
    // For example
    int a = 13;
    int b = 44;
    int sum;

    sum1(&a, &b, &sum);
    _beautifullPrint("sum1", a, b, sum);

    sum2(a, b, sum);
    _beautifullPrint("sum2", a, b, sum);

    sum3(a, b, sum);
    _beautifullPrint("sum3", a, b, sum);

    sum4(a, &b, sum);
    _beautifullPrint("sum4", a, b, sum);

    sum5(&a, &b, sum);
    _beautifullPrint("sum5", a, b, sum);

    return 0;
}

void sum1(int *a, int *b, int *sum) {
    *sum = *a + *b;
}

void sum2(int &a, int &b, int &sum) {
    sum = a + b;
}

void sum3(int a, int b, int &sum) {
    sum = a + b;
}

void sum4(int a, int *b, int &sum) {
    sum = a + *b;
}

void sum5(int *a, int *b, int &sum) {
    sum = *a + *b;
}

void _beautifullPrint(string s, int a, int b, int sum) {
    cout << s << "(" << a << ", " << b << ") = " << sum << "\n";
}