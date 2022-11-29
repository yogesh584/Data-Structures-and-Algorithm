#include <iostream>
#include <vector>
using namespace std;

int solve(int index, int endIndex, vector<int> &slices, int totalSlices)
{
    if (index >= endIndex || totalSlices == 0)
    {
        return 0;
    }

    int pick = slices[index] + solve(index + 2, endIndex, slices, totalSlices - 1);
    int notPick = 0 + solve(index + 1, endIndex, slices, totalSlices);

    return max(pick, notPick);
}

int solve(int index, int endIndex, vector<int> &slices, int totalSlices, vector<vector<int>> &dp)
{
    if (index > endIndex || totalSlices == 0)
    {
        return 0;
    }
    if (dp[index][totalSlices] != -1)
    {
        return dp[index][totalSlices];
    }

    int pick = slices[index] + solve(index + 2, endIndex, slices, totalSlices - 1, dp);
    int notPick = 0 + solve(index + 1, endIndex, slices, totalSlices, dp);

    return dp[index][totalSlices] = max(pick, notPick);
}

int solveTab(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

    for (int index = k - 2; index >= 0; index--)
    {
        for (int totalSlices = 1; totalSlices <= k / 3; totalSlices++)
        {
            int pick = slices[index] + dp1[index + 2][totalSlices - 1];
            int notPick = 0 + dp1[index + 1][totalSlices];
            dp1[index][totalSlices] = max(pick, notPick);
        }
    }

    for (int index = k - 1; index >= 1; index--)
    {
        for (int totalSlices = 1; totalSlices <= k / 3; totalSlices++)
        {
            int pick = slices[index] + dp2[index + 2][totalSlices - 1];
            int notPick = 0 + dp2[index + 1][totalSlices];
            dp2[index][totalSlices] = max(pick, notPick);
        }
    }

    return max(dp1[0][k / 3], dp2[1][k / 3]);
}

int solveSO(vector<int> &slices)
{
    int k = slices.size();

    vector<int> prev1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);

    vector<int> prev2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);

    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

    for (int index = k - 2; index >= 0; index--)
    {
        for (int totalSlices = 1; totalSlices <= k / 3; totalSlices++)
        {
            int pick = slices[index] + next1[totalSlices - 1];
            int notPick = 0 + curr1[totalSlices];
            prev1[totalSlices] = max(pick, notPick);
        }
        next1 = curr1;
        curr1 = prev1;
    }

    for (int index = k - 1; index >= 1; index--)
    {
        for (int totalSlices = 1; totalSlices <= k / 3; totalSlices++)
        {
            int pick = slices[index] + next2[totalSlices - 1];
            int notPick = 0 + curr2[totalSlices];
            prev2[totalSlices] = max(pick, notPick);
        }
        next2 = curr2;
        curr2 = prev2;
    }

    return max(curr1[k / 3], curr2[k / 3]);
}

int maxSizeSlices(vector<int> &slices)
{
    // int k = slices.size();

    // vector<int> dp(slices.size() + 1, -1);
    // int case1 = solve(0, k - 2, slices, k / 3);
    // int case2 = solve(1, k - 1, slices, k / 3);
    // return max(case1, case2);

    // Recursion + memoization
    int k = slices.size();

    vector<vector<int>> dp(slices.size() + 1, vector<int>(slices.size() + 1, -1));
    int case1 = solve(0, k - 2, slices, k / 3, dp);
    vector<vector<int>> dp1(slices.size() + 1, vector<int>(slices.size() + 1, -1));
    int case2 = solve(1, k - 1, slices, k / 3, dp1);
    return max(case1, case2);
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
