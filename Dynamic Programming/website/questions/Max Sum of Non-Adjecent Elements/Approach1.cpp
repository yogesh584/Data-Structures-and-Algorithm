#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &arr, int index, vector<int> &dp)
{
    // base case
    if (index >= arr.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int includeAns = arr[index] + maxSum(arr, index + 2, dp);
    int excludeAns = maxSum(arr, index + 1, dp);

    return dp[index] = max(includeAns, excludeAns);
}

int maxSumBU(vector<int> &arr)
{
    vector<int> dp(arr.size() + 2, 0);

    for (int index = arr.size() - 1; index >= 0; index--)
    {
        int include = arr[index] + dp[index + 2];
        int exclude = dp[index + 1];

        dp[index] = max(include, exclude);
    }
    return dp[0];
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);

    // vector<int> dp(arr.size(), -1);
    // cout << "Max sum is : " << maxSum(arr, 0, dp);

    cout << "Max sum is : " << maxSumBU(arr);

    cout << endl
         << endl
         << endl;
    return 0;
}
