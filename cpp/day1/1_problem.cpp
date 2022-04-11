#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    
    // Declare keep number
    int keep_number;

    // Read keep_number while it isn't in [1, 100]
    do {

        cout << "Please enter the keep number from 1 to 100" << endl;
        cout << "$ ";

        // Read keep_number
        cin >> keep_number;

    } while (!(1 <= keep_number && keep_number <= 100));

    /* It is only work in linux or unix based systems.
     * Please consider this fact!
     * If your system is windows based, please delete "clear" and write "cls".
     */
    system("clear");

    // Declare say_number
    int say_number;

    // Read say_number while it doesn't equal to keep_number
    do {

        cout << "Please enter the number from 1 to 100" << endl;
        cout << "$ ";
        
        // Read say_number
        cin >> say_number;

    } while (say_number != keep_number);

    // You won!!! Congratulations!!!
    cout << "You won!" << endl;

    return 0;
}
