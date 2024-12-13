#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}

    void printInorderRec(Node *node)
    {
        if (!node)
            return;

        printInorderRec(node->pLeft);
        cout << node->data << " ";
        printInorderRec(node->pRight);
    }

    bool findRec(Node *node, const T &value)
    {
        if (!node)
            return false;
        else if (node->data == value)
            return true;
        else if (node->data > value)
            return findRec(node->pLeft, value);
        else
            return findRec(node->pRight, i);
    }

    void printInorder()
    {
        // TODO
        printInorderRec(this->root);
    }

    bool search(const T &value)
    {
        // TODO
        return findRec(this->root, value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};