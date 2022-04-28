#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

void _bubbleSort(int* array, int left, int right) {
    for (int i = left; i <= right - 1; i++) {
        bool is_not_swapped = true;
        for (int j = left; j <= right - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                is_not_swapped = false;
            }
        }
        if (is_not_swapped) {
            break;
        }
    }
}

void _bubbleSort(int* array, int size) {
    _bubbleSort(array, 0, size - 1);
}

#endif // __BUBBLE_SORT_H__