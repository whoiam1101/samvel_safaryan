#include <iostream>

using namespace std;

// Implementation procedure: print <count> times of <symbol>
void printChar(char symbol, int count) {
    while (count--) {
        cout << symbol;
    }
}

int main() {

    int n;

    // Read height of tree while input number <= 0
    do {
        cout << "Input height of Xmas trees: ";
        cin >> n;
    } while (n <= 0);

    // Height of tree is const
    const int height_of_tree = n;

    // Tree type 1

    cout << "Type 1 ------------------------------\n\n";

    while (n--) {
        printChar('*', height_of_tree - n);
        cout << "\n";
    }

    cout << "\n";

    // Tree type 2

    cout << "Type 2 ------------------------------\n\n";

    n = height_of_tree;

    while (n--) {
        printChar(' ', n);
        printChar('*', height_of_tree - n);
        cout << "\n";
    }

    cout << "\n";

    // Tree type 3

    cout << "Type 3 ------------------------------\n\n";

    n = height_of_tree;

    while (n--) {
        printChar('*', n + 1);
        cout << "\n";
    }

    cout << "\n";

    // Tree type 4

    cout << "Type 4 ------------------------------\n\n";
    
    n = height_of_tree;

    while (n--) {
        printChar(' ', n);
        
        int count = height_of_tree - n;

        while (count--) {
            cout << "* ";
        }

        cout << "\n";
    }

    cout << "\n";

    return 0;
}
