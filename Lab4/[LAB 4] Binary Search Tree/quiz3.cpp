#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node *pLeft, *pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node *addRec(Node *root, T value);
    void add(T value);
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    T getMin(Node *root)
    {
        if (!root)
            return 99999;

        T result = root->value;
        T lResult = getMin(root->pLeft);
        T rResult = getMin(root->pRight);

        if (lResult < result)
            result = lResult;
        if (rResult < result)
            result = rResult;

        return result;
    }

    T getMax(Node *root)
    {
        if (!root)
            return -99999;

        T result = root->value;
        T lResult = getMax(root->pLeft);
        T rResult = getMax(root->pRight);

        if (lResult > result)
            result = lResult;
        if (rResult > result)
            result = rResult;

        return result;
    }

    T getMin()
    {
        // TODO: return the minimum values of nodes in the tree.
        return getMin(this->root);
    }

    T getMax()
    {
        // TODO: return the maximum values of nodes in the tree.
        return getMax(this->root);
    }

    // STUDENT ANSWER END
};