/*
    ZIG ZAG TRAVERSEL  (GFG)
        APPROACH 1 :

*/
#include <iostream>
#include <vector>
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

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<Node *> q;
    q.push(root);

    bool isLToR = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            int index = isLToR ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }

        isLToR = !isLToR;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{

    return 0;
}
