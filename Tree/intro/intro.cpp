/*
    INTRO TO BINARY TREE.
        1. BASIC TERMS
            1. NODE
            2. ROOT
            3. CHILDREN
            4. SIBLINGS
            5. ANCESTORS
            6. DECENDENT
            7. LEAF

        2. CREATION OF BINARY TREE.

        3. TRAVERSAL
            1. LEVEL ORDER TRAVERSAL
            2. INORDER TRAVERSAL    ->LNR
            3. PREORDER TRAVERSAL   ->NLR
            4. POSTORDER TRAVERSAL  ->LRN
*/

#include <iostream>
#include <queue>
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
    cout << "Enter the data " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Going left.
    inorderTraversal(root->left);

    // Printing
    cout << root->data << " ";

    // Going Right
    inorderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    inorderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
