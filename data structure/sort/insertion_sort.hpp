#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

void _insertionSort(int* array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1]) {
            std::swap(array[j], array[j + 1]);
            j--;
        }
    }
}

void _insertionSort(int* array, int size) {
    _insertionSort(array, 0, size - 1);
}

#endif // __INSERTION_SORT_H__