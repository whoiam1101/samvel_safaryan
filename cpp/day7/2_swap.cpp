#include <iostream>

using namespace std;

void swap(int &, int &);
void swap(int *, int *);

int main() {
    int a = 1;
    int b = 2;

    cout << a << " " << b << endl;

    swap(a, b);
    cout << a << " " << b << endl;

    swap(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
