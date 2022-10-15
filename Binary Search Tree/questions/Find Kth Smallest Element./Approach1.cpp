/*
    QUESTION NAME
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

/*      FINDING KTH SMALLEST ELEMENT        */
/*      TC : O(n)         */
/*      SC : O(n)         */
int solve(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    i++;
    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int findKthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
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

/*      YOUR FUNCTIONAL CODE GOES HERE      */

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
    int k = 3;
    cout << k << " smallest element is : " << findKthSmallest(root, k) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
