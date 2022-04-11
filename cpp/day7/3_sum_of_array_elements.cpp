#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(time(nullptr));

int _sumOfArrayElements(int *, int);

int _myRandomGenerator(int);

int main() {
    // size
    int n;

    cout << "Input size:";
    cin >> n;

    // array
    int *arr = new int[n];

    // fill and print
    arr[0] = _myRandomGenerator(10);

    cout << "sum(" << arr[0];

    for (int i = 1; i < n; i++) {
        arr[i] = _myRandomGenerator(10);

        cout << ", " << arr[i];
    }

    // calculate sum and print
    cout << ") = " << _sumOfArrayElements(arr, n) << endl;

    return 0;
}

int _sumOfArrayElements(int *arr, int length) {
    int sum = 0;

    while (length--) {
        sum += *arr;
        arr++;
    }

    return sum;
}

int _myRandomGenerator(int a) {
    return gen() % a;
}