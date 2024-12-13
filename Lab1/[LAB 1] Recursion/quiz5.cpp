#include <iostream>
using namespace std;

bool isPalindromeHelper(const string &str, int left, int right)
{

    if (left >= right)
    {
        return true;
    }

    if (!isalnum(str[left]))
    {
        return isPalindromeHelper(str, left + 1, right);
    }

    if (!isalnum(str[right]))
    {
        return isPalindromeHelper(str, left, right - 1);
    }

    if (tolower(str[left]) != tolower(str[right]))
    {
        return false;
    }

    return isPalindromeHelper(str, left + 1, right - 1);
}

bool isPalindrome(string str)
{
    return isPalindromeHelper(str, 0, str.length() - 1);
}