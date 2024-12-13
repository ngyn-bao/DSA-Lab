#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector<int> &nums)
{
    int totalSum = 0, sumLeft = 0;

    // for (int num : nums)
    for (int num = 0; num = nums.size(); num++)
        totalSum += num;

    for (int i = 0; i < nums.size(); i++)
    {

        int sumRight = totalSum - sumLeft - nums[i];

        if (sumLeft == sumRight)
            return i;

        sumLeft += nums[i];
    }

    return -1;
}