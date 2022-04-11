#include <iostream>
#include <ctime>
#include <random>

using namespace std;

// MT19937 algorithm
mt19937 gen(time(nullptr));

// Declare my generators of random numbers
int my_generator(int, int);
int my_generator(int);

int main() {
    // Declare size of matrix
    int m, n;

    // Read height
    cout << "Height: ";
    cin >> m;

    // Read width
    cout << "Width : ";
    cin >> n;

    // HEIGHT and WIDTH is a const value
    const int HEIGHT = m;
    const int WIDTH  = n;

    // Declare matrix m x n
    int matrix[HEIGHT][WIDTH];

    // first even line
    int first_even_line = -1;

    // Fill matrix and print
    cout << "Matrix:\n";

    for (int i = 0; i < HEIGHT; i++) {
        bool is_even_line = true;

        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = my_generator(-100, 100);

            cout << matrix[i][j] << " ";

            // If last bit is 1 then number is odd
            if (matrix[i][j] & 1) {
                is_even_line = false;
            }
        }

        // If don't find even line and current line is even
        if (is_even_line && first_even_line == -1) {
            first_even_line = i;
        }

        cout << endl;
    }

    if (first_even_line == -1) {
        cout << "\nNo\n";
    } else {
        cout << "\nThe first even line is " << first_even_line + 1 << endl;
    }

    return 0;
}

// Define my_generator for return random integer number in range m and n
int my_generator(int m, int n) {
    return gen() % (n - m + 1) + m;
}

// Define my_generator for return random integer number in range 1 and n
int my_generator(int n) {
    return my_generator(1, n);
}

