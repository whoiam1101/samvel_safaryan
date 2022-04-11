#include <iostream>

using namespace std;

// Declare print_decimal_to_binary procedure(function)
void print_decimal_to_binary(long long);

int main() {
    // Declare decimal number
    long long decimal_number;

    // Read decimal number
    cout << "Input: ";
    cin >> decimal_number;

    // Print toBinary(decimal_number)
    print_decimal_to_binary(decimal_number);

    return 0;
}

// Define print_decimal_to_binary procedure
// representation 64bit decimal number to binary number
// After: print binary number
void print_decimal_to_binary(long long number) {
    // Count of bits equal to 64
    // I am solve this problem for 64 bits integer number
    const int COUNT_OF_BITS = 64;

    // isNegative = true if number is negative
    // isNegative = false if number is positive
    // I use ternary operator
    // expression ? first_value : second_value
    bool isNegative = (number >= 0) ? false : true;
    
    // If number is negative then for begin, I am convert -number to binary
    if (isNegative) {
        number = -number;
    }

    // Declare binary number array for bits of number
    bool binary_number[COUNT_OF_BITS];

    // The first, binary_number array is fill 0
    // 0 = false
    // 1 = true
    for (int i = 0; i < COUNT_OF_BITS; i++) {
        binary_number[i] = false;
    }

    // Iterator
    int i = 0;

    // Satndart algorithm for representation decimal positive integer number to bianry 
    while (number > 0) {
        binary_number[i] = (number % 2LL == 1LL);
        number >>= 1;
        i++;
    }

    // If number is negative then 
    // number = not(-number) + 1
    if (isNegative) {
        for (int i = 0; i < COUNT_OF_BITS; i++) {
            binary_number[i] = !binary_number[i];
        }

        i = 0;

        while (i < COUNT_OF_BITS - 1 && binary_number[i]) {
            binary_number[i] = false;
            i++;
        }

        binary_number[i] = true;
    }

    // Real binary number is the reverse of binary_nunber array
    i = COUNT_OF_BITS - 1;

    // Ignore started zeroes
    while (i >= 0 && !binary_number[i]) {
        i--;
    }

    // Print 64bit binary number
    cout << "Output: ";

    if (i == -1) {
        cout << "0\n";
        return;
    }

    while (i >= 0) {
        cout << binary_number[i];
        i--;
    }

    cout << endl;
}


