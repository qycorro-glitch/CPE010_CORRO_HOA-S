#ifndef SORTALGO2_H
#define SORTALGO2_H

#include <iostream>
#include <algorithm>

// Insertion Sort   
template <typename T>
void insertionSort(T arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        T temp = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

// Helper function for Quick Sort
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort using Insertion Sort for the sublists
template <typename T>
void quickSortWithInsertion(T arr[], int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        // Sort the left sublist using Insertion Sort
        insertionSort(arr, low, pi - 1);

        // Sort the right sublist using Insertion Sort
        insertionSort(arr, pi + 1, high);
    }
}

#endif