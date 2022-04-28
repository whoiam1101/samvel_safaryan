#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

void _selectionSort(int* array, int left, int right) {
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

void _selectionSort(int* array, int size) {
    _selectionSort(array, 0, size - 1);
}
#endif // __SELECTION_SORT_H__