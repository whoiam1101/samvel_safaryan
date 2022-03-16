#include <iostream>

#include "./lib/my_random.h"
#include "./lib/my_print.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n, m;

    cout << "Enter the hight of array\n";
    cin >> n;

    cout << "Enter the width of array\n";
    cin >> m;

    const int N = n;
    const int M = m;

    int** MA = new int*[N];

    // Fill matrix and print
    for (int** ptr = MA; ptr < MA + N; ptr++) {
        *ptr = new int[M];

        for (int* pptr = *ptr; pptr < *ptr + M; pptr++) {
            *pptr = _myRandom();

            cout << *pptr << " ";
        }

        cout << endl;
    }

    // Sorting matrix by columns
    for (int* ptr = *MA; ptr < *MA + M; ptr++) {
        for (int** fpptr = MA; fpptr < MA + N - 1; fpptr++) {
            for (int** spptr = fpptr + 1; spptr < MA + N; spptr++) {
                int a = *(*fpptr + (ptr - *MA));
                int b = *(*spptr + (ptr - *MA));

                if (a > b) {
                    *(*fpptr + (ptr - *MA)) = b;
                    *(*spptr + (ptr - *MA))  = a;
                }
            }
        }
    }

    cout << endl;

    // Print sorted matrix
    _printMatrix(MA, N, M);

    return 0;
}