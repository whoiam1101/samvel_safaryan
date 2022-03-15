#include <cassert>

#include "my_atoi.h"

// Define my_atoi function
int my_atoi(char* arr) {
    // start pos = 1 if number is negative
    // start pos = 0 if number is positive
    int pos = (arr[0] == '-') ? 1 : 0;
    int answer = 0;

    // n = a_1 a_2 a_3 ... a_m
    // n = 10 * a_1 a_2 a_3 ... a_{n - 1} + a_n
    while (arr[pos] != '\0') {
        // If arr[pos] isn't a digit then exit program
        assert(("Argument isn't a number", '0' <= arr[pos] && arr[pos] <= '9'));

        answer = 10 * answer + (int) (arr[pos] - '0');
        pos++;
    }

    if (arr[0] == '-') {
        return -answer;
    }

    return answer;
}