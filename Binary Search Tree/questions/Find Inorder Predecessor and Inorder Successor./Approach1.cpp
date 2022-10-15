/*
    FIND INORDER PREDECESSOR AND SUCCESSOR IN BST.
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

int findMinElem(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int findMaxElem(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

pair<int, int> predecessorAndSuccessor(Node *root, int predecessor, int successor, int key)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(-1, -1);
        return p;
    }

    // Using Binary Search To Find Key.
    if (root->data == key)
    {
        if (root->left)
            predecessor = findMaxElem(root->left);
        if (root->right)
            successor = findMinElem(root->right);

        pair<int, int> p = make_pair(predecessor, successor);
        return p;
    }
    else if (root->data > key)
    {
        successor = root->data;
        return predecessorAndSuccessor(root->left, predecessor, successor, key);
    }
    else
    {
        predecessor = root->data;
        return predecessorAndSuccessor(root->right, predecessor, successor, key);
    }
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
    /*      FINDING PREDECESSOR AND SUCCESSOR       */
    int key = 9;
    int predecessor = -1;
    int successor = -1;
    pair<int, int> preAndSucc = predecessorAndSuccessor(root, predecessor, successor, key);

    predecessor = preAndSucc.first;
    successor = preAndSucc.second;

    cout << "Predecessor and Successor of " << key << " are : " << predecessor << " and " << successor << endl;
    cout << endl
         << endl
         << endl;

    return 0;
}
