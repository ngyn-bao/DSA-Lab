#include <iostream>
#include <vector>
using namespace std;

bool consecutiveOnes(vector<int> &nums)
{
    // STUDENT ANSWER
    if (nums.empty())
        return true;

    bool foundOne = false;
    bool foundNonOneAfterOne = false;
    // for (int num : nums)
    for (int num; num < nums.size(); num++)
    {
        if (num == 1)
        {
            if (foundNonOneAfterOne)
                return false;
            foundOne = true;
        }
        else
        {
            if (foundOne)
                foundNonOneAfterOne = true;
        }
    }
    return true;
}