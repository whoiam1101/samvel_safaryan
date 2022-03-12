#include <iostream>

using namespace std;

// 5x = a^2 + b^2

// 5 = 2^2 + 1
// 5 * x ^ 2 = (2x) ^ 2 + x ^ 2

// 9 + 16 = 25
// 9x^2 + 16x^2 = 25x^2

int sqr(int);

int main() {
    int sequence_1[10];
    int sequence_2[10];

    cout << "Example 1: \n";

    for (int i = 1; i <= 10; i++) {
        sequence_1[i - 1] = 5 * sqr(i);

        cout << sequence_1[i - 1] << " = " << 2 * i << "x" << 2 * i << " + " << i << "x"  << i << endl; 
    }

    cout << "\nExample 2: \n";

    for (int i = 1; i <= 10; i++) {
        sequence_1[i - 1] = 25 * sqr(i);

        cout << sequence_1[i - 1] << " = " << 3 * i << "x" << 3 * i << " + " << 4 * i << "x" << 4 * i << endl;
    }

    return 0;
}

int sqr(int x) {
    return x * x;
}
