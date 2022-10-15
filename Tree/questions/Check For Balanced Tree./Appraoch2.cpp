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

pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.second = false;
    }
    return ans;
}

bool isBalance(Node *root)
{
    return solve(root).first;
}

int main()
{

    return 0;
}
