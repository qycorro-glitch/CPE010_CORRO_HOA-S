#include <iostream>
#include "sortingAlgo2.h"
#include <cstdlib>
#include <ctime>

const int maxSize = 100;

void displayArray(int arr[]);

int main() { 
    int array[maxSize];

    std::srand(std::time(0));

    for (int i = 0; i < maxSize; i++){
        array[i] = std::rand() % 100;
    }

    std::cout << "Unsorted Array:\n";
    displayArray(array);
    
    
    std::cout << "\nShell Sort:\n";
    shellSort(array, maxSize);
    displayArray(array);
      

    
    std::cout << "\nMerge Sort:\n";
    mergeSort(array, 0, maxSize - 1);
    displayArray(array);
    

    
    std::cout << "\nQuick Sort:\n";
    quickSort(array, 0, maxSize - 1);
    displayArray(array);
    

}

void displayArray(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}