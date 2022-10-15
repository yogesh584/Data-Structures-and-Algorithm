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

Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT32_MAX;
            return root;
        }
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT32_MAX;
            return root;
        }
        return leftAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *res = solve(root, k, node);
    if (res == NULL)
    {
        return -1;
    }
    return res->data;
}
int main()
{

    return 0;
}
