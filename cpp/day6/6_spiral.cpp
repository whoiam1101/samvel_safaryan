#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(time(0));

// Generate random number from a to b
double myGenerator(int a, int b) {
    int rnd_number = gen() % (10 * b - 10 * a + 1) + 10 * a;
    return rnd_number / 10.0;
}

// return absolute value of double number
double ab(double x) {
    if (x < 0.0) return -x;
    return x;
}

// Print n times space
void printSpace(int n) {
    while (n--) {
        cout << " ";
    }
}

// Return count digits of number
int countDigits(int n) {
    int count = 0;

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

int main() {

    int n;

    cin >> n;

    const int SIZE = n;

    int spiral[SIZE][SIZE] = {};

    const int FLAG = SIZE * SIZE;

    int direction = 0;

    int current_value = 1;

    int i = 0;
    int j = 0;

    while (current_value < FLAG) {
        if (direction == 0) {
            while (j < SIZE - 1 && spiral[i][j + 1] == 0) {
                spiral[i][j] = current_value;
                current_value++;
                j++;
            }

            direction = 1;
        } else if (direction == 1) {
            while (i < SIZE - 1 && spiral[i + 1][j] == 0) {
                spiral[i][j] = current_value;
                current_value++;
                i++;
            }

            direction = 2;
        } else if (direction == 2) {
            while (j > 0 && spiral[i][j - 1] == 0) {
                spiral[i][j] = current_value;
                current_value++;
                j--;
            }

            direction = 3;
        } else {
            while (i > 0 && spiral[i - 1][j] == 0) {
                spiral[i][j] = current_value;
                current_value++;
                i--;
            }

            direction = 0;
        }
    }

    spiral[i][j] = FLAG;

    int maxCount = countDigits(FLAG);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << spiral[i][j];

            printSpace(maxCount - countDigits(spiral[i][j]) + 1);
        }

        cout << endl;
    }

    return 0;
}