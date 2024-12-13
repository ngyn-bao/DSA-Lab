#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end)
    {
        // TODO: return the pointer which points to the pivot after rearrange the array.
        T pivot = *start;
        T *left = start + 1;
        T *right = end;

        while (true)
        {
            while (left <= end && *left <= pivot)
            {
                left++;
            }
            while (right > start && *right >= pivot)
            {
                right--;
            }
            if (left >= right)
                break;

            std::swap(*left, *right);
        }
        std::swap(*start, *right);
        return right;
    }

public:
    static void QuickSort(T *start, T *end)
    {
        // TODO
        // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
        if (start < end)
        {
            T *pivot = Partition(start, end);
            cout << pivot - start << " ";
            QuickSort(start, pivot);
            QuickSort(pivot + 1, end);
        }
    }
};

#endif /* SORTING_H */