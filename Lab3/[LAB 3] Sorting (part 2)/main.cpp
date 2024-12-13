#include <iostream>
#include "quiz1.h"
using namespace std;
int main()
{
    int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[19]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array)
        cout << i << " ";
}