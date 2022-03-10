#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Use MT19937 random generator
mt19937 generator(time(nullptr));

// Declare my random generator function
double my_random_generator(int, int);

int main() {

    // Declare size of matrix
    const int SIZE = 3;

    // Declare matrix 3x3
    double matrix2D[SIZE][SIZE];

    // Declare sum_numbers_in_triangles
    double sum_numbers_in_triangles = 0.0;

    // Genearate random numbers in range [1, 10] and fill array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // (i, j)-th element = random number in  range [1, 10]
            matrix2D[i][j] = my_random_generator(1, 10);

            // Print matrix elements
            cout << matrix2D[i][j] << " ";
            
            // Add all elements in sum_numbers_in_triangles
            sum_numbers_in_triangles += matrix2D[i][j];
        }

        cout << endl;
    }

    // Only the centre element of matrix isn't in triangles of matrix  
    sum_numbers_in_triangles -= matrix2D[1][1];

    // Print sum_numbers_in_triangles
    cout << "Output: " << sum_numbers_in_triangles << endl;

    return 0;
}

// Define my_random_generator
// return random double number in range [left, right]
double my_random_generator(int left, int right) {
    left *= left * left;
    right *= right * right;

    double rnd_number = generator() % (right - left + 1) + left + 0.0;

    return cbrt(rnd_number);
}


