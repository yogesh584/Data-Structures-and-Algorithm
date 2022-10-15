/*
    TWO SUM IN BST.
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

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);
}

/*      TWO SUM IN BST      */
bool twoSumInBST(Node *root, int target)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int start = 0;
    int end = inorder.size() - 1;
    while (start <= end)
    {
        int sum = start + end;
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return false;
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

    /*  TWO SUM IN BST DRIVER CODE      */
    cout << twoSumInBST(root, 15) << endl;
    return 0;
}
