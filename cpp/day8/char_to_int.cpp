#include <iostream>
#include <cassert>

// My my_atoi library for use my_atoi(char*) function
#include "my_atoi.h"

using namespace std;

int main(int argc, char* argv[]) {
    // If this expression evaluates to 0, this causes an assertion failure that terminates the program
    assert(("Please, use one argument", argc == 2));

    // char[] -> int
    cout << my_atoi(argv[1]) << endl;

    return 0;
}
