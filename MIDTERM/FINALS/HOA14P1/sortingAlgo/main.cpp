#include <iostream>
#include "sortAlgo1.h"


const int maxSize = 15;

void displayArray(int arr[]);

int main() {

    int array[maxSize] = {
        8, 3, 7, 2, 9,
        5, 1, 6, 4, 10,
        12, 11, 15, 13, 14
    };

    std::cout << "Original Array:\n";
    displayArray(array);

    std::cout << "\nQuick Sort with Insertion Sort:\n";

    quickSortWithInsertion(array, 0, maxSize - 1);

    displayArray(array);

    return 0;
}

void displayArray(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
