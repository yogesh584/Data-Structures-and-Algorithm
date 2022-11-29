/*
    IS BINARY TREE HEAP.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node *root, int index, int totalCount)
{
    if (root == NULL)
    {
        return true;
    }

    if (index >= totalCount)
    {
        return false;
    }
    else
    {
        bool leftAns = isCBT(root->left, 2 * index + 1, totalCount);
        bool rightAns = isCBT(root->right, 2 * index + 2, totalCount);

        return leftAns && rightAns;
    }
}

bool isMaxOrder(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
    }
}

bool isBinaryTreeHeap(Node *root)
{
    int index = 0;
    int totalCount = countNodes(root);

    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << endl
         << endl
         << endl;

    cout << endl
         << endl
         << endl;

    return 0;
}
