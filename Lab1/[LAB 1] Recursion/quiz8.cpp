#include <iostream>
using namespace std;

void printHailstone(int number)
{
    /*
     * STUDENT ANSWER
     */
    if (number == 1)
    {
        cout << number;
        return;
    }

    cout << number << " ";

    if (number % 2 == 0)
    {
        printHailstone(number / 2);
    }
    else if (number % 2 != 0)
    {
        printHailstone(number * 3 + 1);
    }
}