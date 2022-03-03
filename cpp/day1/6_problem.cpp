#include <iostream>

using namespace std;

int main() {

    // Declare number
    int number;

    // Read number while number < 0
    do {

        // Read number
        cout << "Enter the nonegative number\n";
        cout << "$ ";
        cin >> number;

    } while (number < 0);

    // Declare factorial = 0!
    unsigned long long factorial = 1ull;

    cout << "Factorial(" << number << ") = ";

    // f(n) = n * f(n - 1)
    // f(0) = 1
    while (number > 0) {
        factorial *= (unsigned long long) number;
        number--;
    }

    // Print factorial of number
    cout << factorial << endl;

    return 0;
}
