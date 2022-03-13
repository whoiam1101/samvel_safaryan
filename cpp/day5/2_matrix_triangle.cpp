#include <iostream>
#include <ctime>
#include <random>

using namespace std;

// Use MT19937 random generator algorithm
mt19937 gen(time(nullptr));

// Declare my random generators
int my_random_generator(int, int);
int my_random_generator(int);

int main() {
    int n;

    // Read quadratic matrix size
    cout << "Input size: ";
    cin >> n;

    // Matrix size is a const
    const int SIZE = n;

    // Declare matrix n x n
    int matrix[SIZE][SIZE];

    // Declare sum of triangles
    int results[8] = {};

/*
______
|\ 1|
| \ |
|0_\|
______
|2 /|
| / |
|/_3|
______
| \ 5/|
|4 \/7|
|  /\ |
| /_6\|

4 = 0 & 2
5 = 2 & 1
6 = 0 & 3
7 = 3 & 1

*/

    // In matrix fill randomized numbers in range 1-10
    // And print
    // And calculate sum of numbers in triangles
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = my_random_generator(10);

            cout << matrix[i][j] << " ";

            if (i > j) {
                results[0] += matrix[i][j];
            } else if (i < j) {
                results[1] += matrix[i][j];
            }

            if (i + j < SIZE - 1) {
                results[2] += matrix[i][j];

                if (i > j) {
                    results[4] += matrix[i][j];
                } else if (i < j) {
                    results[5] += matrix[i][j];
                }
            } else if (i + j > SIZE - 1) {
                results[3] += matrix[i][j];

                if (i > j) {
                    results[6] += matrix[i][j];
                } else if (i < j) {
                    results[7] += matrix[i][j];
                }
            }
        }

        cout << endl;
    }

    cout << "Sum numbers in triangles\n";

    for (int i = 0; i < 8; i++) {
        cout << results[i] << endl;
    }

    return 0;
}

// Define: return random integer number in range [a, b]
int my_random_generator(int a, int b) {
    return gen() % (b - a + 1) + a;
}

// Define: return random integer number in range [a, b]
int my_random_generator(int a) {
    return my_random_generator(1, 10);
}
