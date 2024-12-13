class BSTNode
{
public:
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode()
    {
        this->left = this->right = nullptr;
    }
    BSTNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BSTNode(int val, BSTNode *&left, BSTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int kthSmallest(BSTNode *root, int &count, int k)
    {
        if (!root)
            return -1;

        int leftFind = kthSmallest(root->left, count, k);
        if (leftFind != -1)
            return leftFind;

        count++;

        if (count == k)
            return root->val;

        int rightFind = kthSmallest(root->right, count, k);
        return rightFind;
    }

    int kthSmallest(BSTNode *root, int k)
    {
        int count = 0;
        return kthSmallest(root, count, k);
    }
};