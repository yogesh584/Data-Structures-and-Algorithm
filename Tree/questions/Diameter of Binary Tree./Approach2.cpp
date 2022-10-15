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

int diameter(Node *root)
{

    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int leftSubTree = diameter(root->left);
    int rightSubTree = diameter(root->right);

    int sumOfLeftPartAndRightPart = height(root->left) + 1 + height(root->right);

    return max(max(leftSubTree, rightSubTree), sumOfLeftPartAndRightPart);
}

int main()
{

    return 0;
}
