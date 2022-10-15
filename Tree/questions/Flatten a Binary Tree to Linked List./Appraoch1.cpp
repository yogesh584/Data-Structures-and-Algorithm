/*
    FLATTEN A BINARY TREE TO LINKED LIST.
        APPROACH 1 :
*/

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

void flatten(Node *root)
{
}

int main()
{
    cout << endl
         << endl
         << endl;

    /*      EXAMPLE TREE :
                    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    */

    /*      BUILDING TREE       */
    Node *root = NULL;
    cout << "Enter Data to Build Binary Tree : ";
    root = buildTree(root);

    /*      FLATTEN A TREE TO LINKED LIST       */
    flatten(root);

    cout << endl
         << endl
         << endl;
    return 0;
}
