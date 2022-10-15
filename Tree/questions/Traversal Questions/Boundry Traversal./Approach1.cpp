/*
    BOUNDRY TRAVERSAL
        APPROACH 1 :
*/
#include <iostream>
#include <vector>
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

void leftTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
        leftTraversal(root->left, ans);
    else
        leftTraversal(root->right, ans);
}

void rightTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
        rightTraversal(root->right, ans);
    else
        rightTraversal(root->left, ans);

    ans.push_back(root->data);
}

void printLeafNodes(Node *root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    printLeafNodes(root->left, ans);
    printLeafNodes(root->right, ans);
}

void printLeafNodes(Node *root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    printLeafNodes(root->left, ans);
    printLeafNodes(root->right, ans);
}

vector<int> BoundryTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    /*  STEP 1 : LEFT SIDE TRAVERSAL     */
    leftTraversal(root->left, ans);

    /*      STEP 2 : LEFT NODE TRAVERSAL        */
    printLeafNodes(root->left, ans);
    printLeafNodes(root->right, ans);
    /*      STEP 3 : RIGHT TRAVERSAL         */
    rightTraversal(root->right, ans);

    return ans;
}

int main()
{

    cout << endl
         << endl
         << endl;

    Node *root = NULL;
    cout << "Enter Data to Build Tree : ";
    root = buildTree(root);

    /*       1 2 3 -1 -1 5 6 -1 -1  8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1        */

    vector<int> boundryTraversalResult = BoundryTraversal(root);

    for (int i = 0; i < boundryTraversalResult.size(); i++)
    {
        cout << boundryTraversalResult[i] << " ";
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
