#include "my_atoi.h"

// Define my_atoi function
int my_atoi(char* arr) {
    int pos = 0;
    bool is_negative = false;

    while (arr[pos] != '\0' && !('0' <= arr[pos] && arr[pos] <= '9')) {
        pos++;
    }

    int answer = 0;

    if (pos > 0 && arr[pos - 1] == '-') {
        is_negative = true;
    }

    // n = a_1 a_2 a_3 ... a_m
    // n = 10 * a_1 a_2 a_3 ... a_{n - 1} + a_n
    while (arr[pos] != '\0' && '0' <= arr[pos] && arr[pos] <= '9') {
        answer = 10 * answer + (int) (arr[pos] - '0');
        pos++;
    }

    if (is_negative) {
        return -answer;
    }

    return answer;
}