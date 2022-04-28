#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include <ctime>
#include <random>

std::mt19937 _gen(time(nullptr));
int _randomIndex(int left, int right) {
    return _gen() % (right - left + 1) + left;
}

void _quickSort(int* array, int left, int right) {
    if (left < right) {
        int pivot = array[_randomIndex(left, right)];
        int first = left;
        int second = right;
        while (first <= second) {
            while (first <= second && array[first] < pivot) {
                first++;
            }

            while (first <= second && array[second] > pivot) {
                second--;
            }

            if (first <= second) {
                std::swap(array[first], array[second]);
                first++;
                second--;
            }
        }
        _quickSort(array, left, second);
        _quickSort(array, first, right);
    }
}

void _quickSort(int* array, int size) {
    _quickSort(array, 0, size - 1);
}

#endif // __QUICK_SORT_H__