#include <iostream>
using namespace std;

int strLen(char *str)
{
    /*
     * STUDENT ANSWER
     */
    if (*str == '\0')
        return 0;
    else
        return 1 + strLen(str + 1);
}