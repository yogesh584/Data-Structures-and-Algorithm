#include <iostream>
#include <vector>
using namespace std;

int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveMem(n - (i * i), dp));
    }
    return dp[n] = ans;
}

int solveTab(int N)
{
    vector<int> dp(N + 1, INT32_MAX);
    dp[0] = 0;

    for (int n = 1; n <= N; n++)
    {
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + dp[n - (i * i)]);
        }
        dp[n] = ans;
    }
    return dp[N];
}

int MinSquares(int n)
{
    // Recursion + memoization
    // vector<int> dp(n + 1, -1);
    // return solveMem(n, dp);

    // Bottom up approach
    // return solveTab(n);
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
