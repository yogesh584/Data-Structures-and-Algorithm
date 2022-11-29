/*
    Perfect Squares
*/
#include <iostream>
#include <vector>
using namespace std;

int perfectSquare(int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = INT32_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + perfectSquare(n - i * i, dp));
    }
    return dp[n] = ans;
}

int perfectSquareBU(int N)
{
    vector<int> dp(N + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        int ans = INT32_MAX;
        for (int j = 1; j * j <= n; j++)
        {
            ans = min(ans, 1 + dp[n - j * j]);
        }
        dp[n] = ans;
    }

    return dp[N];
}

int main()
{
    cout << endl
         << endl
         << endl;

    int n = 12;
    vector<int> dp(n + 1, -1);
    cout << perfectSquareBU(n) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
