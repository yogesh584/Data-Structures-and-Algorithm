/*
    Diameter of a Binary Tree.
*/
#include <iostream>
#include <queue>
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

/*      FUNCTIONS TO FIND DIAMETER OF THE TREE       */
int solve(Node *root, int &longestPath)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDiameter = solve(root->left, longestPath);
    int rightDiameter = solve(root->right, longestPath);

    longestPath = max(longestPath, leftDiameter + rightDiameter);

    return max(leftDiameter, rightDiameter) + 1;
}
int diameter(Node *root)
{
    int longestPath = 0;
    return solve(root, longestPath);
}

int main()
{
    cout << endl
         << endl
         << endl;

    /*      EXAMPLE TREE :
                    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    */

    Node *root = NULL;

    /*      BUILDING TREE       */
    cout << "Enter Data to Build Binary Tree : ";
    root = buildTree(root);

    /*      FINDING DIAMETER        */
    cout << "Diameter of Binary Tree is : " << diameter(root) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
