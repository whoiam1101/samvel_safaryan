#include <iostream>
#include <ctime>
#include <random>

using namespace std;

mt19937 gen(time(nullptr));

int _myRandomGenerator(int, int);

int main() {
    int length;

    cout << "Input length of sequence: ";
    cin >> length;

    int* arr = new int[length];

    int* start_el = arr;
    int length_part = 0;

    for (int* ptr = arr; ptr < arr + length; ptr++) {
        *ptr = _myRandomGenerator(-20, 20);
        cout << *ptr << " ";
    }

    for (int* ptr = arr; ptr < arr + length; ptr++) {
        int *tmp_start_el = ptr;
        int tmp_length_part = 1;

        while (tmp_start_el < arr + length - 1 && *tmp_start_el <= *(tmp_start_el + 1)) {
            tmp_length_part++;
            tmp_start_el++;
        }

        if (tmp_length_part > length_part) {
            start_el = ptr;
            length_part = tmp_length_part;
        }

        ptr = tmp_start_el;
    }

    cout << "\nOutput: ";

    for (int* i = start_el; i < start_el + length_part; i++) {
        cout << *i << " ";
    }

    cout << endl;
}

int _myRandomGenerator(int left, int right) {
    return gen() % (right - left + 1) + left;
}