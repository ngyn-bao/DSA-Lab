#include <iostream>
#include <vector>
using namespace std;

int longestSublist(vector<string> &words)
{
    // STUDENT ANSWER
    int maxLength = 1;
    int currentLength = 1;

    if (words.empty())
        return 0;
    for (int i = 1; i < words.size(); i++)
    {

        if (words[i][0] == words[i - 1][0])
        {
            currentLength++;
        }
        else
        {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    maxLength = max(maxLength, currentLength);
    return maxLength;
}