#include <iostream>

using namespace std;

// Declaration: the return type, the name of the function, and parameters (if any)
// Definition: the body of the function (code to be executed)
// Declared functions are not executed immediately. 
// They are "saved for later use", and will be executed later, when they are called.

// Declare isPrime function
// return true if parametr is prime
// otherwise return false
// Time complexity = O(sqrt(n))
bool isPrime(int);

int main() {
    
    // Declare number
    int number;

    // Input number
    cout << "Enter a natural number: ";
    cin >> number;

    // Call isPrime(int) function.
    // Print Yes, <number> is a prime number if <number> is prime.
    // Print No, <number> isn't a prime number if <number> isn't prime.
    if (isPrime(number)) cout << "Yes, " << number << " is a prime number\n";
    else cout << "No, " << number << " isn't a prime number\n";

    return 0;
}

// Define isPrime function
bool isPrime(int number) {
    if (number == 1) return false;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}
