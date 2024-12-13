#include <iostream>
#include <algorithm>
using namespace std;

int buyCar(int *nums, int length, int k)
{
    std::sort(nums, nums + length);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (k >= nums[i])
        {
            k -= nums[i];
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}