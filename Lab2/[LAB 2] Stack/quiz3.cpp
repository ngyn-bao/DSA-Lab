#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreater(vector<int> &arr)
{
    vector<int> greater(arr.size(), -1);
    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[i] > arr[s.top()])
        {
            greater[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return greater;
}