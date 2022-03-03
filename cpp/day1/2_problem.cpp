#include <iostream>

using namespace std;

int main() {

    // Declare number
    int number;

    // Read number while number doesn't belong [0, 10]
    do {
        
        cout << "Please enter the number from 1 to 10\n";
        cout << "$ ";

        // Read number
        cin >> number;

    } while (!(0 <= number && number <= 10));

    cout << "Multiplication table of " << number << ":\n";

    for (int i = 0; i <= 10; i++) {
        // Print number x number = number format
        cout << i << " x " << number << " = " << i * number << endl;
    }

    return 0;
}
