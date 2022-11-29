#include <iostream>
#include <vector>
using namespace std;

// Normal Recursive Solution
int lcs(string s1, string s2, int index1, int index2)
{
    // base case
    if (index1 == s1.length() || index2 == s2.length())
    {
        return 0;
    }

    if (s1[index1] == s2[index2])
    {
        int matchAnswer = 1 + lcs(s1, s2, index1 + 1, index2 + 1);
        return matchAnswer;
    }
    else
    {
        int option1 = lcs(s1, s2, index1 + 1, index2);
        int option2 = lcs(s1, s2, index1, index2 + 1);
        return max(option1, option2);
    }
}

// dp Solution
int lcsDP(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
{
    // base case
    if (index1 == s1.length() || index2 == s2.length())
    {
        return 0;
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    if (s1[index1] == s2[index2])
    {
        int matchAnswer = 1 + lcs(s1, s2, index1 + 1, index2 + 1);
        return dp[index1][index2] = matchAnswer;
    }
    else
    {
        int option1 = lcs(s1, s2, index1 + 1, index2);
        int option2 = lcs(s1, s2, index1, index2 + 1);
        return dp[index1][index2] = max(option1, option2);
    }
}

// Bottom up Solution
int lcsTab(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int index1 = s1.size() - 1; index1 >= 0; index1--)
    {
        for (int index2 = s2.size() - 1; index2 >= 0; index2--)
        {
            int ans = 0;
            if (s1[index1] == s2[index2])
            {
                ans = 1 + dp[index1 + 1][index2 + 1];
            }
            else
            {
                int option1 = dp[index1 + 1][index2];
                int option2 = dp[index1][index2 + 1];
                ans = max(option1, option2);
            }
            dp[index1][index2] = ans;
        }
    }
    return dp[0][0];
}

// Bottom up Solution
int lcsSO(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    vector<int> curr(s2.length() + 1, 0);
    vector<int> next(s2.length() + 1, 0);

    for (int index1 = s1.size() - 1; index1 >= 0; index1--)
    {
        for (int index2 = s2.size() - 1; index2 >= 0; index2--)
        {
            int ans = 0;
            if (s1[index1] == s2[index2])
            {
                ans = 1 + next[index2 + 1];
            }
            else
            {
                int option1 = next[index2];
                int option2 = curr[index2 + 1];
                ans = max(option1, option2);
            }
            curr[index2] = ans;
        }
        next = curr;
    }
    return curr[0];
}

int main()
{
    cout << endl
         << endl
         << endl;

    string s1 = "abcde";
    string s2 = "babed";

    // Normal Recursion Checking
    // cout << "Length of Longest Common Subsequence is : " << lcs(s1, s2, 0, 0);

    // Dp Checking -> memoization
    // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    // cout << "Length of Longest Common Subsequence is : " << lcsDP(s1, s2, 0, 0, dp);

    // Dp Checking -> Tabulation
    // cout << "Length of Longest Common Subsequence is : " << lcsTab(s1, s2);

    // Dp Checking -> Space Optimization
    cout << "Length of Longest Common Subsequence is : " << lcsSO(s1, s2);

    cout << endl
         << endl
         << endl;
    return 0;
}
