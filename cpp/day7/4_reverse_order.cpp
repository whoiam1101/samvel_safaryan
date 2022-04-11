#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(time(nullptr));

int _myRandomGenerator(int);

void _printReverseOrder(int *, int);

int main() {
    int n;

    cout << "Input size:";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = _myRandomGenerator(10);

        cout << arr[i] << " ";
    }

    cout << endl;

    _printReverseOrder(arr, n);

    return 0;
}

void _printReverseOrder(int *arr, int length) {
    int *ptr = arr + length - 1;

    while (length--) {
        cout << *ptr << " ";

        ptr--;
    }

    cout << endl;
}

int _myRandomGenerator(int a) {
    return gen() % a;
}