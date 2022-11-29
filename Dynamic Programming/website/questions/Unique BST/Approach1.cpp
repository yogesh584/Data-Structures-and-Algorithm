#include <iostream>
#include <vector>
using namespace std;

int uniqueBST(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += uniqueBST(i - 1, dp) * uniqueBST(n - i, dp);
    }

    return dp[n] = ans;
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<int> dp(4, -1);
    cout << uniqueBST(3, dp);

    cout << endl
         << endl
         << endl;
    return 0;
}