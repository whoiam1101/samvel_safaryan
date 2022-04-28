#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

void _merge(int* array, int left, int middle, int right) {
    int base   = 0;
    int first  = left;
    int second = middle + 1;
    int* temporary_array = new int[right - left + 1];

    while (first <= middle && second <= right) {
        while (first <= middle && array[first] < array[second]) {
            temporary_array[base] = array[first];
            first++;
            base++;
        }

        while (second <= right && array[first] >= array[second]) {
            temporary_array[base] = array[second];
            second++;
            base++;
        }
    }

    if (second == right + 1) {
        for (int i = first; i <= middle; i++) {
            temporary_array[base] = array[i];
            base++;
        }
    } else {
        for (int i = second; i <= right; i++) {
            temporary_array[base] = array[i];
            base++;
        }
    }

    for (int i = 0; i <= right - left; i++) {
        array[i + left] = temporary_array[i];
    }

    delete[] temporary_array;
}

void _mergeSort(int* array, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        _mergeSort(array, left, middle);
        _mergeSort(array, middle + 1, right);
        _merge(array, left, middle, right);
    }
}

void _mergeSort(int* array, int size) {
    _mergeSort(array, 0, size - 1);
}

#endif // __MERGE_SORT_H__