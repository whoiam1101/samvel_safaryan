#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// MT19937 is a portable Mersenne Twister random number generator
mt19937 my_generator(time(nullptr));

// Declare my random generator
int my_random_generator(int, int);

int main() {
    // Declare number
    // <number> is a count of elements in array
    int number;

    // Input number
    cout << "Input: ";
    cin >> number;

    // Array size = <number>
    // Declare int array
    const int SIZE = number;
    int a[SIZE];

    // Declare max_value
    // At first max_value = -INF
    int max_value = -20000000;

    cout << "Array: ";

    for (int i = 0; i < SIZE; i++) {
        // Get random number in range [-1000000, 1000000]
        a[i] = my_random_generator(-1000000, 1000000);
        
        // Calculate max value in array
        if (a[i] > max_value) {
            max_value = a[i];
        }

        // Print a[i]
        cout << a[i] << " ";
    }

    // Print max value in array
    cout << "\nMax element of array is " << max_value << endl;

    return 0;
}

// Define my random generator
// return random number in range [left, right]
int my_random_generator(int left, int right) {
    return my_generator() % (right - left + 1) + left;
}
