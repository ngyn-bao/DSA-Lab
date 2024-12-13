#include <iostream>
using namespace std;

void printArray(int n)
{
    /*
     * STUDENT ANSWER
     */
    if (n < 0)
        return;
    else if (n == 0)
    {
        cout << n;
    }
    else
    {
        printArray(n - 1);
        cout << ", " << n;
    }
}
