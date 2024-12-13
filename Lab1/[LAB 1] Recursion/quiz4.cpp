#include <iostream>
using namespace std;

int findMax(int *arr, int length)
{
    /*
     * STUDENT ANSWER
     */
    if (length == 1)
        return arr[0];
    else
    {
        return max(arr[length - 1], findMax(arr, length - 1));
    }
}