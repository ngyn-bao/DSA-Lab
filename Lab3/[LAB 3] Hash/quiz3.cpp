#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pairMatching(vector<int> &nums, int target)
{
    int res = 0;
    sort(nums.begin(), nums.end());
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        if (nums[start] + nums[end] > target)
            end--;
        else if (nums[start] + nums[end] < target)
            start++;
        else
        {
            res++;
            start++;
            end--;
        }
    }
    return res;
}