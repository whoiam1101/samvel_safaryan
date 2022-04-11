#include <iostream>

using namespace std;

int main() {

    // Declare current year
    int year = 2022;

    // Declare leap years count
    int leap_years_count = 0;

    cout << "The next 20 leap years:\n";

    // print next 20 leap years
    while (leap_years_count < 20) {

        // Leap years if year mod 400 = 0 or (year mod 4 = 0 and year mod 100 != 0)
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
            
            // Increment leap years count
            leap_years_count++;
            
            // Print year, because year is leap year
            cout << "(" << leap_years_count << ") " << year << " is a leap year!\n";
        }

        // year = next year
        year++;
    }
    return 0;
}
