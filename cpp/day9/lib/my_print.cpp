#include <iostream>

#include "my_print.h"

void _printMatrix(int** matrix, int height, int width) {
    for (int** pptr = matrix; pptr < matrix + height; pptr++) {
        for (int* ptr = *pptr; ptr < *pptr + width; ptr++) {
            std::cout << *ptr << " ";
        }

        std::cout << std::endl;
    }
}