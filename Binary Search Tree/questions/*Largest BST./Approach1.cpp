/*
    LARGEST BST IN A BINARY TREE
        APPROACH 1:
*/
#include <iostream>
using namespace std;

/*       NODE CLASS FOR BINARY SEARCH TREE       */
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int givenData)
    {
        data = givenData;
        left = NULL;
        right = NULL;
    }
};

/*      INSERT INTO BINARY SEARCH TREE      */
/*      TC : O(logn)                        */
/*      SC : O(n)                           */
Node *insertIntoBST(Node *root, int givenData)
{
    /*      BASE CASE       */
    if (root == NULL)
    {
        root = new Node(givenData);
        return root;
    }

    if (givenData > root->data)
    {
        /*       Insert in Right Part.        */
        root->right = insertIntoBST(root->right, givenData);
    }
    else
    {
        /*      Insert in Left Part      */
        root->left = insertIntoBST(root->left, givenData);
    }

    return root;
}

/*      BUILD TREE      */
void buildTree(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

/*      LARGEST BST IN A BINARY TREE      */

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT32_MIN, INT32_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(left.mini, root->data);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main()
{
    cout << endl
         << endl
         << endl;

    /*      BUILDING A BINARY SEARCH TREE      */
    /*      TEMP DATA TO BUILD BINARY SEARCH TREE
            10 7 15 5 9 17 16 19 -1     */
    Node *root = NULL;
    cout << "Enter Data to Create Binary Serach Tree : " << endl;
    buildTree(root);

    cout << endl;
    /*       LARGEST BST IN A BINARY TREE      */
    cout << "Number of Nodes in Largest BST in Given Tree is : " << largestBST(root) << endl;
    return 0;
}
