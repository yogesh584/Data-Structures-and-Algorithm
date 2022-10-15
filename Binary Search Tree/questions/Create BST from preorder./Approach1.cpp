/*
    CREATE BST FROM PREORDER.
        APPROACH 1:
*/
#include <iostream>
#include <vector>
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

/*      CREATE BST FROM PREORDER.      */

Node *solve(vector<int> &preorder, int mini, int maxi, int &index)
{
    if (index >= preorder.size() || preorder[index] < mini || preorder[index] > maxi)
    {
        return NULL;
    }

    Node *root = new Node(preorder[index++]);
    root->left = solve(preorder, mini, root->data, index);
    root->right = solve(preorder, root->data, maxi, index);

    return root;
}

Node *BSTfromPreorder(vector<int> preorder)
{
    int mini = INT32_MIN;
    int maxi = INT32_MAX;
    int index = 0;
    return solve(preorder, mini, maxi, index);
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
    /*      CREATE BST FROM PREORDER. DRIVER CODE.      */
    return 0;
}
