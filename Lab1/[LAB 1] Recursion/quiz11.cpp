#include <iostream>
using namespace std;

int countBrackets(const string &s, long unsigned int index, int open)
{

    if (index == s.length())
    {
        return open;
    }

    if (s[index] == '(')
    {

        return countBrackets(s, index + 1, open + 1);
    }
    else
    {
        if (open > 0)
        {

            return countBrackets(s, index + 1, open - 1);
        }
        else
        {

            return 1 + countBrackets(s, index + 1, open);
        }
    }
}
int mininumBracketAdd(string s)
{
    return countBrackets(s, 0, 0);
    // STUDENT ANSWER
}