#include <iostream>
#include <string>
using namespace std;
string repeatString(const string &str, int count)
{
    if (count <= 0)
    {
        return "";
    }
    return str + repeatString(str, count - 1);
}

string expandHelper(const string &s, size_t &index)
{
    string result = "";

    if (index >= s.size())
    {
        return result;
    }

    char currentChar = s[index];

    if (isdigit(currentChar))
    {

        int repeatCount = currentChar - '0';
        index++;

        index++;

        string innerExpanded = expandHelper(s, index);

        string repeated = repeatString(innerExpanded, repeatCount);

        result += repeated;

        return result + expandHelper(s, index);
    }
    else if (currentChar == ')')
    {

        index++;
        return result;
    }
    else
    {

        result += currentChar;
        index++;

        return result + expandHelper(s, index);
    }
}

string expand(const string &s)
{
    size_t index = 0;
    return expandHelper(s, index);
}