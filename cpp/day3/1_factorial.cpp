#include <iostream>

using namespace std;

// Define factorial function
// n! = (n - 1)! * n
// 0! = 1
// Time complexity = O(number)
unsigned long long factorial(unsigned long long number) {
    if (number == 0ULL) return 1ULL;

    return factorial(number - 1ULL) * number;
}

int main() {
    // Declare function
    unsigned long long number;
    
    // input number
    cout << "Enter the nonnegative integer number: ";
    cin >> number;

    // Output factorial(number)
    cout << "Factorial(" << number << ") = " << factorial(number) << endl;

    return 0;
}
