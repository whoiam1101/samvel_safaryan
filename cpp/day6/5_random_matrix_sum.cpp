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
    
    // Size of quadratic matrix
    int n;

    // Read Size
    cout << "Size of 2 quadratic matrix: ";
    cin >> n;

    // SIZE is a const
    const int SIZE = n;
    
    // Declare A, B matrix
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    
    // Declare A+B matrix
    int APLUSB[SIZE][SIZE];

    // In A fill randomized numbers in range 1-10
    // And print
    cout << "Matrix A:\n";
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = my_generator(10);

            cout << A[i][j] << " ";
        }

        cout << endl;
    }

    // In B fill randomized numbers in range 1-10
    // And print
    cout << "\nMatrix B:\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            B[i][j] = my_generator(10);

            cout << B[i][j] << " ";
        }

        cout << endl;
    }

    // Calculate A+B and save in APLUSB matrix
    // And print
    cout << "\nSum of A and B:\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            APLUSB[i][j] = A[i][j] + B[i][j];

            cout << APLUSB[i][j] << " ";
        }

        cout << endl;
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
