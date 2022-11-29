#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &num, int tar)
{
    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i]);
    }
    return ans;
}

int solveMem(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveMem(num, tar - num[i], dp);
    }
    return dp[tar] = ans;
}

int solveTab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);

    // base case analysis
    dp[0] = 1;

    for (int t = 0; t <= tar; t++)
    {
        int ans = 0;
        for (int i = 0; i < num.size(); i++)
        {
            ans += solveMem(num, t - num[i], dp);
        }
        dp[t] = ans;
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Recursion
    // return solve(num, tar);

    // Recursion + memoization
    // vector <int> dp(tar+1,-1);
    // return solveMem(num,tar,dp);

    // Bottom up solution
    // return solveTab(num,tar);
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
