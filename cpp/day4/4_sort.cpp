#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

// MT19937 is a portable Mersenne Twister random number generator
mt19937 my_generator(time(nullptr));

// Declare my random generator
double my_random_generator(int, int);

int main() {
    // Declare number
    // <number> is a count of elements in array
    int number;

    // Input number
    cout << "Size of array: ";
    cin >> number;

    // Array size = <number>
    // Declare int array
    const int SIZE = number;
    double a[SIZE];

    // Print array before sorting
    cout << "Array       : ";

    for (int i = 0; i < SIZE; i++) {
        // Get random number
        a[i] = my_random_generator(-1000, 1000);
        
        // Print a[i]
        cout << a[i] << " ";
    }

    // Sorted array
    // Time complexity = O(SIZE^2)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (a[i] > a[j]) {
                // Swap two elements of array
                double tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    // Print array after sorting
    cout << "\nSorted array: ";

    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}

// Define my random generator
// Change my old  random generator for return random double number
// return random number in range [left, right]
double my_random_generator(int left, int right) {
    left *= left * left;
    right *= right * right;

    int random_number = my_generator() % (right - left + 1) + left;

    return cbrt((double) random_number);
}

