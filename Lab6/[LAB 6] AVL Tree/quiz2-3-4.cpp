#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    int getBalance(Node *subroot)
    {
        if (!subroot)
            return 0;
        return getHeightRec(subroot->pLeft) - getHeightRec(subroot->pRight);
    };
    Node *rotateLeft(Node *subroot)
    {
        // TODO: Rotate and return new root after rotate
        Node *child = subroot->pRight;
        Node *T2 = child->pLeft;

        child->pLeft = subroot;
        subroot->pRight = T2;

        // subroot->balance = getBalance(subroot);
        // child->balance = getBalance(child);

        return child;
    };
    Node *rotateRight(Node *subroot)
    {
        // TODO: Rotate and return new root after rotate
        Node *child = subroot->pLeft;
        Node *T2 = child->pRight;

        child->pRight = subroot;
        subroot->pLeft = T2;

        // subroot->balance = getBalance(subroot);
        // child->balance = getBalance(child);

        return child;
    };

    Node *insert(Node *subroot, const T &value)
    {
        if (subroot == NULL)
            return (new Node(value));

        if (value < subroot->data)
            subroot->pLeft = insert(subroot->pLeft, value);
        else if (value >= subroot->data)
            subroot->pRight = insert(subroot->pRight, value);

        int balance = getBalance(subroot);
        // Left Left Case
        if (balance > 1 && value < subroot->pLeft->data)
            return rotateRight(subroot);

        // Right Right Case
        if (balance < -1 && value >= subroot->pRight->data)
            return rotateLeft(subroot);

        // Left Right Case
        if (balance > 1 && value >= subroot->pLeft->data)
        {
            subroot->pLeft = rotateLeft(subroot->pLeft);
            return rotateRight(subroot);
        }
        // Right Left Case
        if (balance < -1 && value < subroot->pRight->data)
        {
            subroot->pRight = rotateRight(subroot->pRight);
            return rotateLeft(subroot);
        }
        return subroot;
    };

    void insert(const T &value)
    {
        // TODO
        this->root = insert(this->root, value);
    };

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