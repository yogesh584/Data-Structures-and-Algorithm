/*
    --- BINARY SEARCH TREE ---
    ------    INTRO     ------
*/

#include <iostream>
#include <queue>
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

/*      LEVEL ORDER TRAVERSAL       */
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

/*      INORDER TRAVERSAL       */
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

/*      PREORDER TRAVERSAL      */
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

/*      POSTORDER TRAVERSAL     */
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

/*      SEARCH IN BINARY SEARCH TREE (RETURNING TRUE OR FALSE)       */
bool searchInBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (root->data > target)
        return searchInBST(root->left, target);
    else
        return searchInBST(root->right, target);
}

/*      SEARCH IN BINARY TREE (RETURNING NODE)      */
Node *searchInBST2(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        return root;
    }

    if (root->data > target)
        return searchInBST2(root->left, target);
    else
        return searchInBST2(root->right, target);
}

/*      FINDING MINIMUM NODE FROM BINARY SEARCH TREE        */
Node *minOfBST(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

/*      FINDING MAXIMUM NODE FROM BINARY SEARCH TREE        */
Node *maxOfBST(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

/*      INORDER PREDECESSOR (पूर्वज) OF A NODE         */
void inorderPredecessor(Node *root, int givenNode, Node *&pred)
{
}

/*      INORDER SUCCESSOR (उत्तराधिकारी) OF A NODE         */
Node *inorderSuccessor(Node *root, int givenNode)
{
}

/*      DELETING A NODE FROM BINARY SEARCH TREE         */
Node *deleteNode(Node *root, int givenNode)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == givenNode)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            // option 1
            /*
            Node *max = maxOfBST(root->left);
            root->data = max->data;
            root->left = deleteNode(root->left, max->data);
            return root;
            */
            // option 2
            Node *min = minOfBST(root->right);
            root->data = min->data;
            root->right = deleteNode(root->right, min->data);
            return root;
        }
    }
    else if (root->data > givenNode)
    {
        root->left = deleteNode(root->left, givenNode);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, givenNode);
        return root;
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

    /*      LEVEL ORDER TRAVERSAL       */
    cout << endl
         << "Printing the Binary Search Tree " << endl;
    levelOrderTraversal(root);

    /*      INORDER, PREORDER AND POSTORDER TRAVERSAL       */
    cout << endl
         << "Inorder Traversal : ";
    inorderTraversal(root);

    cout << endl
         << "preOrder Traversal : ";
    preOrderTraversal(root);

    cout << endl
         << "postOrder Traversal : ";
    postOrderTraversal(root);

    cout << endl
         << endl;

    /*      SEARCHING IN BINARY SEARCH TREE        */
    cout << "Given Target Address is : " << searchInBST2(root, 7) << endl;
    cout << "Is Element present in BST : " << searchInBST(root, 7) << endl;

    /*      FINDING MINIMUM AND MAXIMUM IN BINARY SEARCH TREE       */
    cout << endl
         << "Minimum element of Binary Search Tree is : " << minOfBST(root)->data << endl;
    cout << "Miximum element of Binary Search Tree is : " << maxOfBST(root)->data << endl;

    /*      FINDING INORDER PREDECESSOR AND INORDER SUCCESSOR       */
    // Node *pred = NULL;
    // inorderPredecessor(root, 4, pred);
    // cout << "Inorder pred : " << pred->data << endl;

    /*      DELETING A NODE FROM BINARY SEARCH TREE         */
    cout << endl;
    cout << "Deleting a Node from BST : " << endl;
    root = deleteNode(root, 50);
    levelOrderTraversal(root);
    cout << endl
         << endl
         << endl;
    return 0;
}
