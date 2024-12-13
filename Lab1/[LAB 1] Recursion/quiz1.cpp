#include <iostream>
using namespace std;

void printArray(int n)
{
    /*
     * STUDENT ANSWER
     */
    if (n < 0)
        return;
    printArray(n - 1);
    cout << n << " ";
}