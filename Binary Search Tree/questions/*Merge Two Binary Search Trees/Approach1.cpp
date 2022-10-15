/*
    MERGE 2 BST
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

/*      MERGE 2 BST      */
void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArray(vector<int> array1, vector<int> array2)
{
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    vector<int> mergedArray(array1.size() + array2.size());

    while (index1 < array1.size() && index2 < array2.size())
    {
        if (array1[index1] < array2[index2])
        {
            mergedArray[index3++] = array1[index1++];
        }
        else
        {
            mergedArray[index3++] = array2[index2++];
        }
    }

    while (index1 < array1.size())
    {
        mergedArray[index3++] = array1[index1++];
    }

    while (index2 < array2.size())
    {
        mergedArray[index3++] = array2[index2++];
    }

    return mergedArray;
}

Node *inorderToBST(vector<int> inorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = inorderToBST(inorder, start, mid - 1);
    root->right = inorderToBST(inorder, mid + 1, end);

    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
    // step 1 : Store Inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 : find merged Array
    vector<int> mergedArray = mergeArray(bst1, bst2);

    // step 3 : Create Tree using merged Array
    Node *root = inorderToBST(mergedArray, 0, mergedArray.size() - 1);
    return root;
}

int main()
{
    cout << endl
         << endl
         << endl;

    /*      BUILDING A BINARY SEARCH TREE      */
    /*      TEMP DATA TO BUILD BINARY SEARCH TREE
            10 7 15 5 9 17 16 19 -1     */
    Node *root1 = NULL;
    cout << "Enter Data to Create Binary Serach Tree : " << endl;
    buildTree(root1);

    Node *root2 = NULL;
    cout << "Enter Data to Create Binary Serach Tree : " << endl;
    buildTree(root2);

    cout << endl;
    /*      MERGE 2 BST. DRIVER CODE      */
    Node *root3 = mergeBST(root1, root2);

    return 0;
}
