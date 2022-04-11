#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(time(nullptr));

int _myRandomGenerator(int);

void _min(int *, int);
void _max(int *, int);

int* _findMinAndMaxElementsOfArray(int *, int);

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

    int *min_max_of_array = _findMinAndMaxElementsOfArray(arr, n);

    cout << "min = " << min_max_of_array[0] << endl;
    cout << "max = " << min_max_of_array[1] << endl;

    return 0;
}

void _min(int *a, int b) {
    if (*a > b) {
        *a = b;
    }
}

void _max(int *a, int b) {
    if (*a < b) {
        *a = b;
    }
}

int* _findMinAndMaxElementsOfArray(int *arr, int length) {
    int *min_max = new int[2];
    min_max[0] = *arr;
    min_max[1] = *arr;

    while (length--) {
        _min(min_max, *arr);
        _max(min_max + 1, *arr);

        arr++;
    }

    return min_max;
}

int _myRandomGenerator(int a) {
    return gen() % a;
}