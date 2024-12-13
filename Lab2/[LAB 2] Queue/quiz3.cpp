#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int sumOfMaxSubarray(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    if (nums.empty() || k <= 0 || k > nums.size())
        return 0;

    deque<int> dq;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    sum += nums[dq.front()];

    for (int i = k; i < nums.size(); i++)
    {
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        sum += nums[dq.front()];
    }
    return sum;
}