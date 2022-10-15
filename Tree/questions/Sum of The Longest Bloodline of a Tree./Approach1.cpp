/*
    SUM OF THE LONGEST BLOODLINE OF A TREE (SUM OF NODES ON THE LONGEST PATH FROM ROOT TO LEAF NODE).
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

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    // base case
    if (root == NULL)
    {
        if (maxLen < len)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootLeafPath(Node *root)
{
    int sum = 0;
    int maxSum = INT32_MIN;

    int len = 0;
    int maxLen = 0;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main()
{

    return 0;
}
