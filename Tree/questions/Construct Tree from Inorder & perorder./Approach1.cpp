#include <iostream>
#include <map>
using namespace std;

/*      CREATING A NODE         */
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

/*      BUILD TREE        */
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

/*      BUILDING TREE USING INRODER AND PERORDER        */
void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{

    // base case
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // recursion calls
    root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;

    // create nodes to index mapping
    createMapping(in, nodeToIndex, n);

    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

int main()
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};

    Node *root = buildTree(in, pre, 6);
    return 0;
}
