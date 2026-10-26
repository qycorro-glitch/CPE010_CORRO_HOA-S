#include <iostream>
#include "sortAlgo2.h"

const int maxSize = 15;

void displayArray(int arr[]);

int main() {

    int array[maxSize] = {
        4, 34, 29, 48, 53,
        87, 12, 30, 44, 25,
        93, 67, 43, 19, 74
    };

    std::cout << "Unsorted Array:\n";
    displayArray(array);

    std::cout << "\nQuick Sort:\n";
    quickSort(array, 0, maxSize - 1);
    displayArray(array);

    return 0;
}

void displayArray(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}