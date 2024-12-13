#include <iostream>
#include <string.h>
using namespace std;

int myArrayToInt(char *str, int index, int n)
{
    if (index == n)
        return 0;

    int currentDigit = str[index] - '0';

    return currentDigit * pow(10, n - index - 1) + myArrayToInt(str, index + 1, n);
}

int myArrayToInt(char *str, int n)
{
    /*
     * STUDENT ANSWER
     */
    return myArrayToInt(str, 0, n);
}