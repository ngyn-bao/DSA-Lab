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
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total);
    static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases);

    // TODO: Write your code here

    static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
    {
        int size = end - start;
        T a;
        int j;

        for (int i = 1; i * cur_segment_total + segment_idx < size; i++)
        {
            a = start[i * cur_segment_total + segment_idx];
            j = i - 1;

            // Fix the index for the comparison in the while loop
            while (j >= 0 && start[j * cur_segment_total + segment_idx] > a)
            {
                start[(j + 1) * cur_segment_total + segment_idx] = start[j * cur_segment_total + segment_idx];
                j--;
            }
            start[(j + 1) * cur_segment_total + segment_idx] = a;
        }
    }

    static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
    {
        for (int i = num_phases - 1; i >= 0; i--)
        {
            for (int segment = 0; segment < num_segment_list[i]; segment++)
            {
                sortSegment(start, end, segment, num_segment_list[i]);
            }
            cout << num_segment_list[i] << " segments: ";
            printArray(start, end);
        }
    }
};
#endif /* SORTING_H */