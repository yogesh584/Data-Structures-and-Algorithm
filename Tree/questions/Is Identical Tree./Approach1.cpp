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

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)
    {
        return false;
    }

    if (r1->data != r2->data)
    {
        return false;
    }

    bool leftIdentical = isIdentical(r1->left, r2->left);
    bool rightIdentical = isIdentical(r1->right, r2->right);

    return (leftIdentical && rightIdentical);
}

int main()
{

    return 0;
}
