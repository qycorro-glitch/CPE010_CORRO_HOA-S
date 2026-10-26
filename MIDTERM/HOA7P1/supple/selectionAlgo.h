#ifndef SELECTIONALGO_H
#define SELECTIONALGO_H

// Find the smallest element
template <typename T>
int routine_smallest(T A[], int maxSize, int k)
{
    int position = k;
    T smallestElement = A[k];

    for (int j = k + 1; j < maxSize; j++)
    {
        if (A[j] < smallestElement)
        {
            smallestElement = A[j];
            position = j;
        }
    }

    return position;
}
// Selection Sort
template <typename T>
void selectionSort(T arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        int pos = routine_smallest(
            arr, arrSize, i
        );

        T temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}
#endif