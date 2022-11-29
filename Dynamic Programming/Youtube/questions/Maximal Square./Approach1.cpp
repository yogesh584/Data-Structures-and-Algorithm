#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<char>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    int right = solve(mat, i, j + 1, maxi);
    int diagnol = solve(mat, i + 1, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);

    if (mat[i][j] == '1')
    {
        int ans = 1 + min(right, min(diagnol, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

int solveMem(vector<vector<char>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solveMem(mat, i, j + 1, maxi, dp);
    int diagnol = solveMem(mat, i + 1, j + 1, maxi, dp);
    int down = solveMem(mat, i + 1, j, maxi, dp);

    int ans = 0;
    if (mat[i][j] == '1')
    {
        ans = 1 + min(right, min(diagnol, down));
        maxi = max(maxi, ans);
    }
    return dp[i][j] = ans;
}

int solveTab(vector<vector<char>> &mat)
{
    int m = mat.size() - 1;
    int n = mat[0].size() - 1;
    vector<vector<int>> dp(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
    dp[m][n] = 0;
    int maxi = 0;
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int diagnol = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            int ans = 0;
            if (mat[i][j] == '1')
            {
                ans = 1 + min(right, min(diagnol, down));
                maxi = max(maxi, ans);
            }
            dp[i][j] = ans;
        }
    }
    return maxi * maxi;
}

int maximalSquare(vector<vector<char>> &matrix)
{
    // Recursive Solution
    // int maxi = 0;
    // solve(matrix, 0, 0, maxi);
    // return maxi * maxi;
}

int main()
{
    cout << endl
         << endl
         << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
