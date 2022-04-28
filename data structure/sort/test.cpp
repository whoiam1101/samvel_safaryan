#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

#include "bubble_sort.hpp"    // O(n^2)
#include "insertion_sort.hpp" // O(n^2)
#include "selection_sort.hpp" // O(n^2)
#include "heap_sort.hpp"      // O(n*log(n))
#include "merge_sort.hpp"     // O(n*log(n))
#include "quick_sort.hpp"     // O(n*log(n))

#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"

using namespace std;

mt19937 gen(time(nullptr));
int _generatorOfRandomIntegerNumber(int = -1000, int = 1000);

bool _isEqual(int*, int*, int);

void _acceptedMessage(const char*, clock_t);
void _rejectedMessage(const char*);
void _printArray(int*, int);

int main() {
    const int SIZE = 2000;

    int* stl_array       = new int[SIZE];
    int* bubble_array    = new int[SIZE];
    int* insertion_array = new int[SIZE];
    int* selection_array = new int[SIZE];
    int* heap_array      = new int[SIZE];
    int* merge_array     = new int[SIZE];
    int* quick_array     = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        stl_array[i] = _generatorOfRandomIntegerNumber();
        bubble_array[i]    = stl_array[i];
        insertion_array[i] = stl_array[i];
        selection_array[i] = stl_array[i];
        heap_array[i]      = stl_array[i];
        merge_array[i]     = stl_array[i];
        quick_array[i]     = stl_array[i];
    }

    // stl
    clock_t start_execution_time = clock();
    sort(stl_array, stl_array + SIZE);
    _acceptedMessage("stl", start_execution_time);

    // selection
    start_execution_time = clock();
    _selectionSort(selection_array, SIZE);
    if (_isEqual(selection_array, stl_array, SIZE)) {
        _acceptedMessage("selection", start_execution_time);
    } else {
        _rejectedMessage("selection");
    }

    // bubble
    start_execution_time = clock();
    _bubbleSort(bubble_array, SIZE);
    if (_isEqual(bubble_array, stl_array, SIZE)) {
        _acceptedMessage("bubble", start_execution_time);
    } else {
        _rejectedMessage("bubble");
    }

    // insertion
    start_execution_time = clock();
    _insertionSort(insertion_array, SIZE);
    if (_isEqual(insertion_array, stl_array, SIZE)) {
        _acceptedMessage("insertion", start_execution_time);
    } else {
        _rejectedMessage("insertion");
    }

    // merge
    start_execution_time = clock();
    _mergeSort(merge_array, SIZE);
    if (_isEqual(merge_array, stl_array, SIZE)) {
        _acceptedMessage("merge", start_execution_time);
    } else {
        _rejectedMessage("merge");
    }

    // quick
    start_execution_time = clock();
    _quickSort(quick_array, SIZE);
    if (_isEqual(quick_array, stl_array, SIZE)) {
        _acceptedMessage("quick", start_execution_time);
    } else {
        _rejectedMessage("quick");
    }

    return 0;
}

int _generatorOfRandomIntegerNumber(int left, int right) {
    return gen() % (right - left + 1) + left;
}

bool _isEqual(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void _acceptedMessage(const char* sorting_algorithm, clock_t start_execution_time) {
    cout << GREEN << "ACCEPTED : " << sorting_algorithm << " sort, execution time := "
         << 1000.0 * (double) (clock() - start_execution_time) / CLOCKS_PER_SEC
         << "ms\n";
}

void _rejectedMessage(const char* sorting_algorithm) {
    cout << RED << "REJECTED : " << sorting_algorithm << endl;
}

void _printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}