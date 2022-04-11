#include <iostream>

using namespace std;

int main() {
    
    // Declare month number
    int month_number;

    // This time I don't check is month number in range of [1, 12]
    // Read month number
    cout << "Input month number: ";
    cin >> month_number;

    cout << "Total number of days = ";

    // Use switch statement for check days count in (month_number) month
    switch(month_number) {
        case 1:  cout << 31 << endl; break;
        case 2:  cout << 28 << endl; break;
        case 3:  cout << 31 << endl; break;
        case 4:  cout << 30 << endl; break;
        case 5:  cout << 31 << endl; break;
        case 6:  cout << 30 << endl; break;
        case 7:  cout << 31 << endl; break;
        case 8:  cout << 31 << endl; break;
        case 9:  cout << 30 << endl; break;
        case 10: cout << 31 << endl; break;
        case 11: cout << 30 << endl; break;
        case 12: cout << 31 << endl; break;
        default: 
            // Otherwise you don't input valid number
            // Please enter the number in range 1, 2, 3 ... 12
            cout << "The count month in year is 12,\n" 
                 << "please rerun program and input number in 1, 2, ... 12.\n";
            break;
    }

    return 0;
}
