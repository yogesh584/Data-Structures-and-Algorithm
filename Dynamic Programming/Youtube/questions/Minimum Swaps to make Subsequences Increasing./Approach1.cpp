#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
{
    if (index >= nums1.size())
    {
        return 0;
    }

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];
    int ans = INT32_MAX;
    // catch
    if (swapped)
        swap(prev1, prev2);

    // no swap
    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solve(nums1, nums2, index + 1, 0);

    // swap
    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));

    return ans;
}

int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
{
    if (index >= nums1.size())
    {
        return 0;
    }
    if (dp[index][swapped] != -1)
        return dp[index][swapped];

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];
    int ans = INT32_MAX;
    // catch
    if (swapped)
        swap(prev1, prev2);

    // no swap
    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solve(nums1, nums2, index + 1, 0, dp);

    // swap
    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1, dp));

    return dp[index][swapped] = ans;
}

int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

    for (int index = nums1.size() - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];
            int ans = INT32_MAX;

            if (swapped)
                swap(prev1, prev2);

            // no swap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = dp[index + 1][0];

            // swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + dp[index + 1][1]);

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}

int solveSO(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = nums1.size() - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];
            int ans = INT32_MAX;

            if (swapped)
                swap(prev1, prev2);

            // no swap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = next[0];

            // swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + next[1]);

            curr[swapped] = ans;
        }
        next = curr;
    }
    return curr[0];
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // Recursion
    // nums1.insert(nums1.begin(), -1);
    // nums2.insert(nums2.begin(), -1);

    // return solve(nums1, nums2, 1, false);

    // Recursion + memoization
    // nums1.insert(nums1.begin(), -1);
    // nums2.insert(nums2.begin(), -1);

    // vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));

    // return solve(nums1, nums2, 1, false, dp);

    // Tabulation
    // nums1.insert(nums1.begin(), -1);
    // nums2.insert(nums2.begin(), -1);

    // return solveTab(nums1, nums2);

    // Space Optimization
    // nums1.insert(nums1.begin(), -1);
    // nums2.insert(nums2.begin(), -1);
    // return solveTab(nums1, nums2);
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
