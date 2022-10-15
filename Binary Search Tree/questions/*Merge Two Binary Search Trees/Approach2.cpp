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

void convertIntoSortedDLL(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node *mergeLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head->data)
        {
            if (head == NULL)
            {
                head = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            head1 = head1->right;
        }
        else
        {
            tail->right = head;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
    }

    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            head2 = head2->right;
        }
        else
        {
            tail->right = head;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    return head;
}

int countNodes(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }

    return count;
}

Node *SortedLinkedToBST(Node *&head, int n)
{
    if (head == NULL || n <= 0)
    {
        return NULL;
    }

    Node *left = SortedLinkedToBST(head, n / 2);

    Node *root = head;
    root->left = left;
    head = head->right;

    Node *right = SortedLinkedToBST(head, n - n / 2 - 1);

    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{

    // step 1 : Creating Sorted Doubly Linked List from BST.
    Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);

    Node *head2 = NULL;
    convertIntoSortedDLL(root1, head2);

    // step 2 : Merge Two Sorted Linked List.
    Node *head = mergeLinkedList(head1, head2);

    // step 3 : Create BST from Sorted LinkedList.
    int TotalNodes = countNodes(head);
    Node *mergedBSTRoot = SortedLinkedToBST(head, TotalNodes);

    return mergedBSTRoot;
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
