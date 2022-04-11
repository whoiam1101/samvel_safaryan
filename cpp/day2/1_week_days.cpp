#include <iostream>

using namespace std;

int main() {

    // Declare week day number
    int week_day_number;

    // Read week day number while not that day in [1, 7]
    do {

        // Read week day number
        cout << "Input week number(1-7): ";
        cin >> week_day_number;
    
    } while (!(1 <= week_day_number && week_day_number <= 7));

    // Use switch statement for check
    switch(week_day_number) {
        case 1: cout << "Monday"    << endl; break;
        case 2: cout << "Tuesday"   << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday"  << endl; break;
        case 5: cout << "Friday"    << endl; break;
        case 6: cout << "Saturday"  << endl; break;
        case 7: cout << "Sunday"    << endl; break;
    }
    
    return 0;
}
