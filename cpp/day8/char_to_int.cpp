#include <iostream>
#include <cassert>

// My my_atoi library for use my_atoi(char*) function
#include "my_atoi.h"

using namespace std;

int main(int argc, char* argv[]) {
    // If this expression evaluates to 0, this causes an assertion failure that terminates the program
    assert(("Please, use one argument", argc > 1));

    int sum = 0;

    for (int i = 1; i < argc - 1; i++) {
        cout << my_atoi(argv[i]) << " + ";

        sum += my_atoi(argv[i]);
    }

    sum += my_atoi(argv[argc - 1]);

    cout << my_atoi(argv[argc - 1]) << " = " << sum << endl;

    return 0;
}
