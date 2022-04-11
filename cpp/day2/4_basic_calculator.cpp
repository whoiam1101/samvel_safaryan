#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Implementation function: return true if double type number is zero
// Othewise return false
bool isZero(double x) {
    const double eps = 1e-10;
    
    if (abs(x) < eps) {
        return true;
    }

    return false;
}

int main() {

    // 	Write floating-point values in fixed-point notation
    cout << fixed;

    // Declare first and second number
    double first_number;
    double second_number;

    // Declare math operator
    char math_operator;

    // Read first number
    cout << "Input number 1: ";
    cin >> first_number;

    // Read math operator
    cout << "Input operator: ";
    cin >> math_operator;

    // Read second number
    cout << "Input number 2: ";
    cin >> second_number;

    // Use switch statement for math operator
    switch (math_operator) {
        case '+':
            cout << first_number << " + " << second_number << " = " << first_number + second_number;
            break;

        case '-':
            cout << first_number << " - " << second_number << " = " << first_number - second_number;
            break;

        case '*':
        case 'x':
            cout << first_number << " x " << second_number << " = " << first_number * second_number;
            break;

        case '/':
            // Any number cannot divide by zero!!!!
            if (isZero(second_number)) {
                cout << "Can't divide by zero!!!";
            } else {
                cout << first_number << " / " << second_number << " = " << first_number / second_number;
            }

            break;

        default:
            // This calculator work only +, -, / and x
            cout << "I cannot work with other mathematical operators other than +, -, / and x";
            break;
    }

    cout << endl;

    return 0;
}

