#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int maxWeight, int index)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    int includeAns = 0;
    if (weight[index] <= maxWeight)
    {
        includeAns = value[index] + solve(weight, value, maxWeight - weight[index], index - 1);
    }
    int excludeAns = solve(weight, value, maxWeight, index - 1);
    return max(includeAns, excludeAns);
}

int solveMem(vector<int> &weight, vector<int> &value, int maxWeight, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }

    int includeAns = 0;
    if (weight[index] <= maxWeight)
    {
        includeAns = value[index] + solveMem(weight, value, maxWeight - weight[index], index - 1, dp);
    }
    int excludeAns = 0 + solveMem(weight, value, maxWeight, index - 1, dp);
    return dp[index][maxWeight] = max(includeAns, excludeAns);
}

int solveTab(vector<int> &weight, vector<int> &value, int maxWeight, int index, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    // step 2 : Analyse Base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int capicity = 0; capicity <= maxWeight; capicity++)
        {
            int includeAns = 0;
            if (weight[index] <= capicity)
            {
                includeAns = value[index] + dp[index - 1][capicity - weight[index]];
            }
            int excludeAns = 0 + dp[index - 1][capicity];
            dp[index][capicity] = max(includeAns, excludeAns);
        }
    }

    return dp[n - 1][maxWeight];
}

int solveSO(vector<int> &weight, vector<int> &value, int maxWeight, int index, int n)
{
    vector<int> curr(maxWeight + 1, 0);
    vector<int> prev(maxWeight + 1, 0);

    // step 2 : Analyse Base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int capicity = 0; capicity <= maxWeight; capicity++)
        {
            int includeAns = 0;
            if (weight[index] <= capicity)
            {
                includeAns = value[index] + prev[capicity - weight[index]];
            }
            int excludeAns = 0 + prev[capicity];
            curr[capicity] = max(includeAns, excludeAns);
        }
        prev = curr;
    }

    return prev[maxWeight];
}
int solveMoreSO(vector<int> &weight, vector<int> &value, int maxWeight, int index, int n)
{
    vector<int> curr(maxWeight + 1, 0);

    // step 2 : Analyse Base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int capicity = maxWeight; capicity >= 0; capicity--)
        {
            int includeAns = 0;
            if (weight[index] <= capicity)
            {
                includeAns = value[index] + curr[capicity - weight[index]];
            }
            int excludeAns = 0 + curr[capicity];
            curr[capicity] = max(includeAns, excludeAns);
        }
    }

    return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Recursion
    // return solve(weight, value, maxWeight, n - 1);

    // Recursion + Memoization
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMem(weight, value, maxWeight, n - 1, dp);

    // Bottom Up Appraoch
    // return solveTab(weight, value, maxWeight, n - 1, n);

    // Space Optimization
    // return solveSO(weight,value,maxWeight,n-1,n);

    // More Space Optimized Answer
    return solveMoreSO(weight, value, maxWeight, n - 1, n);
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
