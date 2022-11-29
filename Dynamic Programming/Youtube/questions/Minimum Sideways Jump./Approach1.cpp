#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int> &obstacles, int currentlane, int position)
{
    if (position == obstacles.size() - 1)
    {
        return 0;
    }

    int ans = 0;
    if (obstacles[position + 1] != currentlane)
    {
        return solve(obstacles, currentlane, position + 1);
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            // i represents lane number
            if (currentlane != i && obstacles[position] != i)
            {
                ans = min(ans, 1 + solve(obstacles, i, position));
            }
        }
        return ans;
    }
}

int solve(vector<int> &obstacles, int currentlane, int position, vector<vector<int>> &dp)
{
    if (position == obstacles.size() - 1)
    {
        return 0;
    }
    if (dp[currentlane][position] != -1)
    {
        return dp[currentlane][position];
    }

    int ans;
    if (obstacles[position + 1] != currentlane)
    {
        ans = solve(obstacles, currentlane, position + 1, dp);
    }
    else
    {
        int TempAns = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            // i represents lane number
            if (currentlane != i && obstacles[position] != i)
            {
                TempAns = min(TempAns, 1 + solve(obstacles, i, position, dp));
            }
        }
        ans = TempAns;
    }
    return dp[currentlane][position] = ans;
}

int solveTab(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(obstacles.size() + 1, 1e9));

    // base case analysis
    for (int i = 0; i <= 3; i++)
    {
        dp[i][obstacles.size() - 1] = 0;
    }

    for (int position = n - 1; position >= 0; position--)
    {
        for (int currentlane = 1; currentlane <= 3; currentlane++)
        {
            int ans;
            if (obstacles[position + 1] != currentlane)
            {
                ans = dp[currentlane][position + 1];
            }
            else
            {
                int TempAns = INT_MAX;
                for (int i = 1; i <= 3; i++)
                {
                    // i represents lane number
                    if (currentlane != i && obstacles[position] != i)
                    {
                        TempAns = min(TempAns, 1 + dp[i][position + 1]);
                    }
                }
                ans = TempAns;
            }
            dp[currentlane][position] = ans;
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

int minSideJumps(vector<int> &obstacles)
{
    // Recursive Solution
    // return solve(obstacles, 2, 0);

    // Recursion + memoization
    // vector<vector<int>> dp(4, vector<int>(obstacles.size() + 1, -1));
    // return solve(obstacles, 2, 0, dp);

    // Bottom Up Approach
    // return solveTab(obstacles);
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
