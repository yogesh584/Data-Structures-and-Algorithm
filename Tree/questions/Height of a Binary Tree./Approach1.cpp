/*
    Height of Binary Tree.
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int givenData)
    {
        this->data = givenData;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = buildTree(root->left);

    root->right = buildTree(root->right);

    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftPartHeight = height(root->left);
    int rightPartHeight = height(root->right);

    return max(leftPartHeight, rightPartHeight) + 1;
}

int main()
{
    cout << endl
         << endl
         << endl;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    cout << "Enter Data to Build Binary Tree : ";
    root = buildTree(root);

    cout << "Height of Binary Tree is : " << height(root) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
