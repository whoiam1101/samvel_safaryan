#include <iostream>

using namespace std;

bool _isInRange(int, int, int);

void _swap(char*, char*);

int main() {
    try {
        string number;

        cout << "Input number: ";
        cin >> number;

        int first_pos, second_pos;

        cout << "Input positions to swap: ";
        cin >> first_pos >> second_pos;

        if (number[0] == '-') {
            first_pos++;
            second_pos++;
        }

        if (!_isInRange(0, number.size(), first_pos) || !_isInRange(0, number.size(), second_pos)) {
            throw "Index Out of Bound Exception";
        }

        _swap(&number[first_pos - 1], &number[second_pos - 1]);

        cout << "Output: " << number << endl;
    } catch (const char* message) {
        cout << message << endl;
    }

    return 0;
}

// a in [left, right) ?
bool _isInRange(int left, int right, int a) {
    return left <= a && a < right;
}

void _swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}