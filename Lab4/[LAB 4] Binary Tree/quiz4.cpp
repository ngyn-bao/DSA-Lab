#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template <class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node *walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.

    int getHeight(Node *root)
    {
        if (!root)
            return 0;

        int lHeight = getHeight(root->pLeft);
        int rHeight = getHeight(root->pRight);

        return max(lHeight, rHeight) + 1;
    }

    int getHeight()
    {
        // TODO: return height of the binary tree.
        return getHeight(this->root);
    }

    string preOrder(Node *root)
    {
        string result = "";
        if (!root)
            return result = "";

        result += to_string(root->value);
        result += " ";

        result += preOrder(root->pLeft);
        result += preOrder(root->pRight);

        return result;
    }

    string preOrder()
    {
        // TODO: return the sequence of values of nodes in pre-order.
        return preOrder(this->root);
    }

    string inOrder(Node *root)
    {
        string result = "";

        if (!root)
            return "";

        result += inOrder(root->pLeft);
        result += to_string(root->value);
        result += " ";
        result += inOrder(root->pRight);

        return result;
    }

    string inOrder()
    {
        // TODO: return the sequence of values of nodes in in-order.
        return inOrder(this->root);
    }

    string postOrder(Node *root)
    {
        string result = "";

        if (!root)
            return "";

        result += postOrder(root->pLeft);

        result += postOrder(root->pRight);

        result += to_string(root->value);
        result += " ";

        return result;
    }

    string postOrder()
    {
        // TODO: return the sequence of values of nodes in post-order.
        return postOrder(this->root);
    }

    // STUDENT ANSWER END
};
