#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T *left, T *middle, T *right)
    {
        /*TODO*/
        int leftSize = middle - left + 1;
        int rightSize = right - middle;

        T *leftArray = new T[leftSize];
        T *rightArray = new T[rightSize];

        for (int i = 0; i < leftSize; i++)
        {
            leftArray[i] = left[i];
        }

        for (int i = 0; i < rightSize; i++)
        {
            rightArray[i] = middle[i + 1];
        }

        int i = 0, j = 0, k = 0;
        while (i < leftSize && j < rightSize)
        {
            if (leftArray[i] <= rightArray[j])
            {
                left[k++] = leftArray[i++];
            }
            else
            {
                left[k++] = rightArray[j++];
            }
        }

        while (i < leftSize)
        {
            left[k++] = leftArray[i++];
        }

        while (j < rightSize)
        {
            left[k++] = rightArray[j++];
        }

        Sorting::printArray(left, right);
        delete[] leftArray;
        delete[] rightArray;
    }
    static void mergeSort(T *start, T *end)
    {
        /*TODO*/
        if (start >= end)
            return;

        T *middle = start + (end - start) / 2;

        mergeSort(start, middle);
        mergeSort(middle + 1, end);

        merge(start, middle, end);
    }
};
#endif /* SORTING_H */
