/*
    --- BURNING TREE ---
    ---- APPROACH 1 ----
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

/*      BINARY TREE       */
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

/*      BUILD TREE      */
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

/*      BURNING TREE CODE STARTS HERE        */
Node *createParentToNodeMapping(Node *root, map<Node *, Node *> &parentToNode, int target)
{
    // creating parent to node mapping and finding traget node using level order traversal.

    queue<Node *> q;
    q.push(root);
    parentToNode[root] = NULL;

    Node *targetNode = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            targetNode = front;
        }

        if (front->left)
        {
            q.push(front->left);
            parentToNode[front->left] = front;
        }

        if (front->right)
        {
            q.push(front->right);
            parentToNode[front->right] = front;
        }
    }

    return targetNode;
}

int burnTree(Node *root, map<Node *, Node *> &parentToNode)
{
    queue<Node *> q;
    map<Node *, bool> visited;
    q.push(root);
    visited[root] = 1;

    int ans = 0;

    while (!q.empty())
    {

        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {

            // process neighbouring nodes.
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                visited[front->left] = 1;
                q.push(front->left);
                flag = 1;
            }

            if (front->right && !visited[front->right])
            {
                visited[front->right] = 1;
                q.push(front->right);
                flag = 1;
            }

            if (parentToNode[front] && !visited[parentToNode[front]])
            {
                visited[parentToNode[front]] = 1;
                q.push(parentToNode[front]);
                flag = 1;
            }
        }

        if (flag == 1)
        {
            ans++;
        }
    }

    return ans;
}

int minTime(Node *root, int target)
{
    // algo
    // step 1 : create parent node mapping
    // step 2 : find the target node
    // step 3 : burn the tree

    map<Node *, Node *> parentToNode;
    Node *targetNode = createParentToNodeMapping(root, parentToNode, target);

    int TotalTime = burnTree(targetNode, parentToNode);

    return TotalTime;
}

int main()
{

    return 0;
}
