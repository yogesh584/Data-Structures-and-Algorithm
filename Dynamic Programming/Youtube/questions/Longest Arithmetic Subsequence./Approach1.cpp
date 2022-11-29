#include <iostream>
#include <unordered_map>
using namespace std;

int solve(int A[], int n, int index, int d)
{
    if (index < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (A[j] - A[index] == d)
        {
            ans = max(ans, 1 + solve(A, n, j, d));
        }
    }
    return ans;
}

int solveMem(int A[], int index, int d, unordered_map<int, int> dp[])
{
    if (index < 0)
    {
        return 0;
    }
    if (dp[index].count(d))
    {
        return dp[index][d];
    }

    int ans = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (A[index] - A[j] == d)
        {
            ans = max(ans, 1 + solveMem(A, j, d, dp));
        }
    }
    return dp[index][d] = ans;
}
// int lengthOfLongestAP(int A[], int n)
// {
// Recursion
// int ans = 0;
// for (int i = 0; i < n; i++)
// {
//     for (int j = i + 1; j < n; j++)
//     {
//         int d = A[i] - A[j];
//         ans = max(ans, 2 + solve(A, n, i, d));
//     }
// }
// return ans;

// Recursion + Memoization
// if (n <= 2)
//     return n;

// int ans = 0;
// unordered_map<int, int> dp[n + 1];
// for (int i = 0; i < n; i++)
// {
//     for (int j = i + 1; j < n; j++)
//     {

//         int d = A[j] - A[i];
//         ans = max(ans, 2 + solve(A, i, d, dp));
//     }
// }
// return ans;
// }

// Bottom Up Solution
int lengthOfLongestAP(int A[], int n)
{
    if (n <= 2)
        return n;

    int ans = 0;
    unordered_map<int, int> dp[n + 1];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int d = A[j] - A[i];
            int cnt = 1;

            // check if answer alrady present
            if (dp[j].count(d))
            {
                cnt = dp[j][d];
            }

            dp[i][d] = 1 + cnt;
            ans = max(ans, dp[i][d]);
        }
    }
    return ans;
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
