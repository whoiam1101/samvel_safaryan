#include <iostream>

using namespace std;

// In number theory, a perfect number is a positive integer that is equal to the sum of its positive divisors

// Declare isPerfectNumber
bool isPerfectNumber(int);

int main() {
    // Declare number
    int number;

    // Input number
    cout << "Is input number a perfect number?\n";
    cout << "Please enter a natural number.\n";
    cout << "Input: ";
    cin >> number;

    // Tell yes if number is perfect, and no otherwise
    cout << "Output: " << (isPerfectNumber(number) ? "Yes\n" : "No\n");

    return 0;
}

// Define isPerfectNumber
// Time complexity = O(sqrt(number))
bool isPerfectNumber(int number) {
    int sum_of_divisors = 1;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            sum_of_divisors += i + number / i;
        }
    }

    return sum_of_divisors == number;
}

