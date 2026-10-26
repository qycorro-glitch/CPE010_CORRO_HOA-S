#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <iostream>

// Bubble Sort
template <typename T>
void bubbleSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            // Compare adjacent elements and swap if out of order
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//insertion sort
template <typename T>
void insertionSort(T arr[], int arrSize) {
    int k = 1, j;
    T temp;

    while (k < arrSize) {
        temp = arr[k];
        j = k - 1;

        // Added 'j >= 0' to prevent out-of-bounds array access (arr[-1])
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;   // responsible for swapping
        }
        arr[j + 1] = temp; // responsible for swapping
        k++; // responsible for swapping
    }
}

//helper function

template <typename T>
int routine_smallest(T A[], int maxSize, int k){ //int k = current index;

    int position, j;
    T smallestElement = A[k];

    for (int J = k+1; J < maxSize; J++) {
        if (A[J] < smallestElement) {
            smallestElement = A[J];
            position = J;
        }
    }

    return position;
} 

//selection sort
template <typename T>
void selectionSort(T arr[], int arrSize) {
    int POS, temp;

    for (int i = 0; i < arrSize; i++) {
        POS = routine_smallest(arr, arrSize, i);

        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    
    }

}


#endif 
