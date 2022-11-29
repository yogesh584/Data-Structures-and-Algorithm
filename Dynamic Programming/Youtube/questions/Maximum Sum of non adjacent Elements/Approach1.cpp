#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, int index)
{
    if (index >= nums.size())
    {
        return 0;
    }

    int maxi = INT32_MIN;
    for (int i = index; i < nums.size(); i++)
    {
        int includeAns = nums[i] + solve(nums, i + 2);
        int excludeAns = solve(nums, i + 1);
        int maxAns = max(includeAns, excludeAns);

        if (maxi < maxAns)
        {
            maxi = maxAns;
        }
    }
    return maxi;
}

int solveMem(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int maxi = INT32_MIN;
    for (int i = index; i < nums.size(); i++)
    {
        int includeAns = nums[i] + solve(nums, i + 2);
        int excludeAns = solve(nums, i + 1);
        int maxAns = max(includeAns, excludeAns);

        if (maxi < maxAns)
        {
            maxi = maxAns;
        }
    }
    return dp[index] = maxi;
}

int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        int maxi = INT32_MIN;
        for (int i = index; i < n; i++)
        {
            int includeAns = nums[i] + dp[i + 2];
            int excludeAns = dp[i + 1];
            int maxAns = max(includeAns, excludeAns);

            if (maxi < maxAns)
            {
                maxi = maxAns;
            }
        }

        dp[index] = maxi;
    }
    return dp[0];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Recursive Solution
    // return solve(nums,0);

    // Recursion + Memoization Solution
    // vector <int> dp(nums.size() + 1,-1);
    // return solveMem(nums,0,dp);

    // Bottum UP Approach
    return solveTab(nums);
}
int main()
{
    cout << endl
         << endl
         << endl;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(10);

    cout << "Maximum sum of non adjucent elements is : " << maximumNonAdjacentSum(nums);
    cout << endl
         << endl
         << endl;
    return 0;
}