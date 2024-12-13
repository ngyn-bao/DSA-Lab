#include <iostream>
using namespace std;

class SplayTree
{
    struct Node
    {
        int val;
        Node *pLeft;
        Node *pRight;
        Node *pParent;
        Node(int val = 0, Node *l = nullptr, Node *r = nullptr, Node *par = nullptr) : val(val), pLeft(l), pRight(r), pParent(par) {}
    };
    Node *root;

    // print the tree structure for local testing
    void printBinaryTree(string prefix, const Node *root, bool isLeft, bool hasRightSibling)
    {
        if (!root && isLeft && hasRightSibling)
        {
            cout << prefix << "├──\n";
        }
        if (!root)
            return;
        cout << prefix;
        if (isLeft && hasRightSibling)
            cout << "├──";
        else
            cout << "└──";
        cout << root->val << '\n';
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
    }

    void printPreorder(Node *p)
    {
        if (!p)
        {
            return;
        }
        cout << p->val << ' ';
        printPreorder(p->pLeft);
        printPreorder(p->pRight);
    }

public:
    SplayTree()
    {
        root = nullptr;
    }
    ~SplayTree()
    {
        // Ignore deleting all nodes in the tree
    }

    void printBinaryTree()
    {
        printBinaryTree("", root, false, false);
    }

    void printPreorder()
    {
        printPreorder(root);
        cout << "\n";
    }

    void rotateLeft(Node *x)
    {
        Node *y = x->pRight;
        if (!y)
            return;
        x->pRight = y->pLeft;
        if (y->pLeft)
            y->pLeft->pParent = x;
        y->pParent = x->pParent;
        if (!x->pParent)
            root = y;
        else if (x == x->pParent->pLeft)
            x->pParent->pLeft = y;
        else
            x->pParent->pRight = y;
        y->pLeft = x;
        x->pParent = y;
    }

    void rotateRight(Node *x)
    {
        Node *y = x->pLeft;
        if (!y)
            return;
        x->pLeft = y->pRight;
        if (y->pRight)
            y->pRight->pParent = x;
        y->pParent = x->pParent;
        if (!x->pParent)
            root = y;
        else if (x == x->pParent->pLeft)
            x->pParent->pLeft = y;
        else
            x->pParent->pRight = y;
        y->pRight = x;
        x->pParent = y;
    }

    void splay(Node *p)
    {
        // ToDo
        while (p->pParent)
        {
            if (!p->pParent->pParent)
            {
                if (p == p->pParent->pLeft)
                    rotateRight(p->pParent);
                else
                    rotateLeft(p->pParent);
            }
            else if (p == p->pParent->pLeft && p->pParent == p->pParent->pParent->pLeft)
            {
                rotateRight(p->pParent->pParent);
                rotateRight(p->pParent);
            }
            else if (p == p->pParent->pRight && p->pParent == p->pParent->pParent->pRight)
            {
                rotateLeft(p->pParent->pParent);
                rotateLeft(p->pParent);
            }
            else if (p == p->pParent->pRight && p->pParent == p->pParent->pParent->pLeft)
            {
                rotateLeft(p->pParent);
                rotateRight(p->pParent);
            }
            else
            {
                rotateRight(p->pParent);
                rotateLeft(p->pParent);
            }
        }
    }

    void insert(int val)
    {
        // ToDo
        if (!this->root)
        {
            this->root = new Node(val);
            return;
        }

        Node *parent = nullptr;
        Node *current = this->root;

        while (current)
        {
            parent = current;
            if (val < current->val)
                current = current->pLeft;

            else
                current = current->pRight;
        }

        Node *newNode = new Node(val, 0, 0, parent);

        if (val < parent->val)
            parent->pLeft = newNode;
        else
            parent->pRight = newNode;

        splay(newNode);
    }
};