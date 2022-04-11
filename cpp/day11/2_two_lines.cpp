#include <iostream>

using namespace std;

struct Vector {
    int x;
    int y;

    Vector(int x, int y) : x(x), y(y) {}
};

int _isPerpendicular(Vector, Vector);
int _scalareProduct(Vector, Vector);

int main() {
    // 0 - A, 1 - B, 2 - C, 3 - D
    int x[4];
    int y[4];

    cout << "Input:\n";

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    // Vector AB = B - A and Vector CD = D - C
    Vector vector_AB = Vector(x[1] - x[0], y[1] - y[0]);
    Vector vector_CD = Vector(x[3] - x[2], y[3] - y[2]);

    // If the dot product of two vectors is 0 then they are perpendicular
    if (_isPerpendicular(vector_AB, vector_CD)) {
        cout << "Output:\nyes\n";
    } else {
        cout << "Output:\nno\n";
    }

    return 0;
}

int _scalarProduct(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

int _isPerpendicular(Vector a, Vector b) {
    return _scalarProduct(a, b) == 0;
}