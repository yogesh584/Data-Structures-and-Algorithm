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

pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool sum = left.second + right.second == root->data;

    pair<bool, int> ans;
    ans.second = root->data + left.second + right.second;
    if (leftAns && rightAns && sum)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node *root)
{
    return solve(root).first;
}
int main()
{

    return 0;
}
