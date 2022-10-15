/*
    K SUM PATH.
        APPROACH 1 :
*/
#include <iostream>
#include <vector>
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

void solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();

    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
}

int sumK(Node *root, int k)
{
    vector<int> path;

    int count = 0;
    solve(root, k, count, path);

    return count;
}   

int main()
{

    return 0;
}
