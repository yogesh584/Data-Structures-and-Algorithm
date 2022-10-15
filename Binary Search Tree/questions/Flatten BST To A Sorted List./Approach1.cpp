/*
    FLATTEN BST TO A SORTED LIST.
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

/*      FLATTEN BST TO A SORTED LIST.      */
Node *flatten(Node *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int size = inorder.size();

    Node *newRoot = new Node(inorder[0]);

    Node *curr = newRoot;
    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node(inorder[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
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
    /*      FLATTEN BST TO A SORTED LIST. DRIVER CODE      */
    Node *LinkedListRoot = flatten(root);

    // Traveling Linked List
    Node *temp = LinkedListRoot;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
