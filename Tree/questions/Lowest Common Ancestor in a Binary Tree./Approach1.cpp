/*
    LOWEST COMMON ANCESTOR IN A BINARY TREE.
        APPROACH 1 :
*/
#include <iostream>
using namespace std;

/*      CREATING A NODE         */
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

/*      A FUNCTION TO BUILD TREE        */
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

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns == NULL && rightAns == NULL)
    {
        return NULL;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
}

int main()
{

    return 0;
}
