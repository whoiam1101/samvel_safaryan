#include <iostream>

using namespace std;

// Declare swap function
void my_swap(double &, double &);

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
    double matrix[HEIGHT][WIDTH + 2];

    cout << "Matrix(" << m << "x" << n << ")\n";

    // Read matrix
    for (int i = 0; i < HEIGHT; i++) {
        // Min and Max numbers position in matrix[i]
        int min_pos = 0;
        int max_pos = 0;

        // Min and Max value in matrix[i]
        double min_value;
        double max_value;

        for (int j = 0; j < WIDTH; j++) {
            // Read matrix[i][j]
            cout << "matrix[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
  
            if (j == 0) {
                min_value = matrix[i][0];
                max_value = matrix[i][0];
            } else {
                // min_value = min(min_value, matrix[i][j])
                if (min_value > matrix[i][j]) {
                    min_value = matrix[i][j];
                    min_pos   = j;
                }

                // max_value = max(max_value, matrix[i][j])
                if (max_value < matrix[i][j]) {
                    max_value = matrix[i][j];
                    max_pos   = j;
                }
            }
        }

        // swap min and max numbers in matrix[i]
        my_swap(matrix[i][min_pos], matrix[i][max_pos]);
    }

    // Print matrix
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

// Define my_swap procedure
void my_swap(double & a, double & b) {
    double temp = a;
    a = b;
    b = temp;
}
