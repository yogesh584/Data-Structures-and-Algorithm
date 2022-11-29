#include <iostream>
#include <vector>
using namespace std;

int solve(int index, int arr[], int N, int target)
{
    // base case
    if (index >= N)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    int include = solve(index + 1, arr, N, target - arr[index]);
    int exclude = solve(index + 1, arr, N, target);

    return include || exclude;
}

int solve(int index, int arr[], int N, int target, vector<vector<int>> &dp)
{
    // base case
    if (index >= N)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    int include = solve(index + 1, arr, N, target - arr[index], dp);
    int exclude = solve(index + 1, arr, N, target, dp);

    return dp[index][target] = include || exclude;
}

int solveTab(int N, int arr[])
{

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += arr[i];
    }

    if (total & 1)
    {
        return 0;
    }

    int t = total / 2;

    vector<vector<int>> dp(N + 1, vector<int>(t + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = N - 1; index >= 0; index--)
    {
        for (int target = 1; target <= t; target++)
        {
            int include = 0;
            if (target - arr[index] >= 0)
                include = dp[index + 1][target - arr[index]];
            int exclude = dp[index + 1][target];

            dp[index][target] = (include || exclude);
        }
    }

    return dp[0][t];
}

int solveSO(int N, int arr[])
{

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += arr[i];
    }

    if (total & 1)
    {
        return 0;
    }

    int t = total / 2;

    vector<int> curr(t + 1, 0);
    vector<int> next(t + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for (int index = N - 1; index >= 0; index--)
    {
        for (int target = 1; target <= t; target++)
        {
            int include = 0;
            if (target - arr[index] >= 0)
                include = next[target - arr[index]];
            int exclude = next[target];
            curr[target] = (include || exclude);
        }
        next = curr;
    }

    return curr[t];
}

int equalPartition(int N, int arr[])
{
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += arr[i];
    }

    if (total & 1)
    {
        return 0;
    }

    int target = total / 2;

    // Recursion
    // return solve(0, arr, N, target);

    // Recursion + memoization
    // vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));
    // return solve(0, arr, N, target, dp);

    // Bottom Up Approach
    return solveTab(N, arr);
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
