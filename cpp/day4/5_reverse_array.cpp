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

    cout << "Array: ";

    for (int i = 0; i < SIZE; i++) {
        // Get random number in range [-1000000, 1000000]
        a[i] = my_random_generator(-1000000, 1000000);
        
        // Print a[i]
        cout << a[i] << " ";
    }
    
    cout << "\nReverse array: ";

    // Reversing array and print
    for (int i = 0; i < SIZE; i++) {
        
        if (i < SIZE / 2) {
            // Swap a[i] and a[SIZE - i - 1]
            int tmp = a[i];
            a[i] = a[SIZE - i - 1];
            a[SIZE - i - 1] = tmp;
        }
        
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}

// Define my random generator
// return random number in range [left, right]
int my_random_generator(int left, int right) {
    if (right == left) {
        return left;
    }

    return my_generator() % (right - left) + left;
}
