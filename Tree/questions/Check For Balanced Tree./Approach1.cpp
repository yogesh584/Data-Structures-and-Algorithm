/*
    CHECK FOR BALANCED TREE.
*/
#include <iostream>
using namespace std;

/*      CREATING NODE CLASS TO CREATE BINARY TREE       */
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

/*      FUNCTION TO BUILD TREE      */
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

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}
