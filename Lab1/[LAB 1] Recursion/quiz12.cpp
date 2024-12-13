#include <iostream>
using namespace std;

string lastWord(const string &s)
{
    size_t pos = s.find_last_of(' ');
    if (pos == string::npos)
    {
        return s;
    }
    return s.substr(pos + 1);
}

string removeLastWord(string &s)
{
    size_t pos = s.find_last_of(' ');
    if (pos == string::npos)
    {
        return "";
    }
    s = s.substr(0, pos);
    return s;
}

string reverseHelper(string s)
{
    if (s.empty())
    {
        return "";
    }
    string last = lastWord(s);
    s = removeLastWord(s);
    return (s.empty() ? last : last + " " + reverseHelper(s));
}

string reverseSentence(string s)
{
    return reverseHelper(s);
}