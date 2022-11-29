#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#include <limits.h>
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans1 = solve(n - x, x, y, z, dp) + 1;
    int ans2 = solve(n - y, x, y, z, dp) + 1;
    int ans3 = solve(n - z, x, y, z, dp) + 1;

    return dp[n] = max(ans1, max(ans2, ans3));
}

int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i - x] + 1, dp[i]);
        if (i - y >= 0)
            dp[i] = max(dp[i - y] + 1, dp[i]);
        if (i - z >= 0)
            dp[i] = max(dp[i - z] + 1, dp[i]);
    }
    if (dp[n] < 0)
    {
        return 0;
    }
    else
    {
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z)
{
    int ans = solveTab(n, x, y, z);
    return ans;
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
