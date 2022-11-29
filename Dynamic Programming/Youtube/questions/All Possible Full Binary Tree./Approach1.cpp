#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int givenVal)
    {
        left = NULL;
        right = NULL;
        val = givenVal;
    }
};

vector<TreeNode *> solve(int n)
{

    if (n == 1)
    {
        vector<TreeNode *> temp;
        temp.push_back(new TreeNode(0));
        return temp;
    }
    vector<TreeNode *> ans;
    for (int i = 1; i < n; i = i + 2)
    {
        vector<TreeNode *> left = solve(i);
        vector<TreeNode *> right = solve(n - i - 1);

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(0);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }

    return ans;
}

vector<TreeNode *> solve(int n, vector<vector<TreeNode *>> &dp)
{

    if (n == 1)
    {
        vector<TreeNode *> temp;
        temp.push_back(new TreeNode(0));
        return dp[1] = temp;
    }
    if (!dp[n].empty())
    {
        return dp[n];
    }

    vector<TreeNode *> ans;
    for (int i = 1; i < n; i = i + 2)
    {
        vector<TreeNode *> left = solve(i, dp);
        vector<TreeNode *> right = solve(n - i - 1, dp);

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(0);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }

    return dp[n] = ans;
}

vector<TreeNode *> allPossibleFBT(int n)
{
    // Recursion
    // return solve(n);

    // Recursion + Memoization
    // vector<vector<TreeNode *>> dp(n + 1, vector<TreeNode *>());
    // return solve(n,dp);
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<TreeNode *> ans = allPossibleFBT(7);

    cout << endl
         << endl
         << endl;
    return 0;
}
