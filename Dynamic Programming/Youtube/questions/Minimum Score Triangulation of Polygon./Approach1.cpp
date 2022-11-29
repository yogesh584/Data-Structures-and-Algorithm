#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp)
{
    // base case
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int ans = values[i] * values[j] * values[k] + solve(i, k, values, dp) + solve(k, j, values, dp);
        mini = min(ans, mini);
    }

    return dp[i][j] = mini;
}

int solveTab(vector<int> &values)
{
    int n = values.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n; i >= 0; i--)
    {
        for (int j = i + 2; j <= n; j++)
        {
            int mini = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int ans = values[i] * values[j] * values[k] + dp[i][k] + dp[k][j];
                mini = min(ans, mini);
            }

            dp[i][j] = mini;
        }
    }

    return dp[0][n];
}

int minScoreTriangulation(vector<int> &values)
{
    // Recursion + Memoizaion
    //     int n = values.size() - 1;
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    //     return solve(0, n, values, dp);

    // Bottom Up
    // return solveTab(values);
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
