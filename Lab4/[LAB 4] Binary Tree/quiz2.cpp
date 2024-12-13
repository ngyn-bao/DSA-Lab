#include <bits/stdc++.h>
using namespace std;

class BTNode
{
public:
    int val;
    BTNode *left;
    BTNode *right;
    BTNode()
    {
        this->left = this->right = NULL;
    }
    BTNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode *&left, BTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

void sumOfRootToLeaf(BTNode *root, int sum, int length, int &maxLength, int &maxSum)
{
    if (!root)
    {
        if (length > maxLength)
        {
            maxLength = length;
            maxSum = sum;
        }

        else if (length == maxLength && sum > maxSum)
        {
            maxSum = sum;
        }
        return;
    }

    sumOfRootToLeaf(root->left, sum + root->val, length + 1, maxLength, maxSum);
    sumOfRootToLeaf(root->right, sum + root->val, length + 1, maxLength, maxSum);
}

int longestPathSum(BTNode *root)
{
    if (!root)
        return 0;

    int maxSum = INT_MIN, maxLength = 0;

    sumOfRootToLeaf(root, 0, 0, maxLength, maxSum);

    return maxSum;
}
