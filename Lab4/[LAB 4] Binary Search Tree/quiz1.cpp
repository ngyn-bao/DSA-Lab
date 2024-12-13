#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
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

    // Helping function
    Node *getSuccessor(Node *curr)
    {
        curr = curr->pRight;
        while (curr && curr->pLeft)
            curr = curr->pLeft;
        return curr;
    }

    Node *add(Node *root, T value)
    {
        if (!root)
            return new Node(value);

        // If the node value is the same as the parent node, add to the left subtree
        if (root->value == value)
            root->pLeft = add(root->pLeft, value);
        else if (root->value < value)
            root->pRight = add(root->pRight, value);
        else
            root->pLeft = add(root->pLeft, value);

        return root;
    }

    void add(T value)
    {
        this->root = add(this->root, value);
    }

    Node *deleteNode(Node *root, T value)
    {
        if (!root)
            return root;

        if (value < root->value)
            root->pLeft = deleteNode(root->pLeft, value);
        else if (value > root->value)
            root->pRight = deleteNode(root->pRight, value);
        else
        {
            if (!root->pLeft)
            {
                Node *temp = root->pRight;
                delete root;
                return temp;
            }
            if (!root->pRight)
            {
                Node *temp = root->pLeft;
                delete root;
                return temp;
            }

            Node *successor = getSuccessor(root);
            root->value = successor->value;
            root->pRight = deleteNode(root->pRight, successor->value);
        }
        return root;
    }

    void deleteNode(T value)
    {
        this->root = deleteNode(this->root, value);
    }

    string inOrderRec(Node *root)
    {
        stringstream ss;
        if (root != nullptr)
        {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }

    string inOrder()
    {
        return inOrderRec(this->root);
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
};