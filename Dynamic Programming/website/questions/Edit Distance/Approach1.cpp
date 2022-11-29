#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2, int index1, int index2)
{
    // base case
    if (index1 == s1.length())
    {
        return (s2.length() - index2);
    }
    if (index2 == s2.length())
    {
        return (s1.length() - index1);
    }
    if (index1 == s1.length() && index2 == s2.length())
    {
        return 0;
    }
    int ans = 0;
    if (s1[index1] == s2[index2])
    {
        ans = editDistance(s1, s2, index1 + 1, index2 + 1);
    }
    else
    {
        int insertAns = editDistance(s1, s2, index1, index2 + 1);
        int deleteAns = editDistance(s1, s2, index1 + 1, index2);
        int replaceAns = editDistance(s1, s2, index1 + 1, index2 + 1);
        ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
    }

    return ans;
}

int editDistanceDP(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
{
    // base case
    if (index1 == s1.length())
    {
        return (s2.length() - index2);
    }
    if (index2 == s2.length())
    {
        return (s1.length() - index1);
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    int ans = 0;
    if (s1[index1] == s2[index2])
    {
        ans = editDistance(s1, s2, index1 + 1, index2 + 1);
    }
    else
    {
        int insertAns = editDistance(s1, s2, index1, index2 + 1);
        int deleteAns = editDistance(s1, s2, index1 + 1, index2);
        int replaceAns = editDistance(s1, s2, index1 + 1, index2 + 1);
        ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
    }

    return dp[index1][index2] = ans;
}

int editDistanceTab(string &s1, string &s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int index2 = 0; index2 < s2.length(); index2++)
    {
        dp[s1.length()][index2] = s2.length() - index2;
    }

    for (int index1 = 0; index1 < s1.length(); index1++)
    {
        dp[index1][s2.length()] = s1.length() - index1;
    }

    for (int index1 = s1.length() - 1; index1 >= 0; index1--)
    {
        for (int index2 = s2.length() - 1; index2 >= 0; index2--)
        {
            int ans = 0;
            if (s1[index1] == s2[index2])
            {
                ans = dp[index1 + 1][index2 + 1];
            }
            else
            {
                int insertAns = dp[index1][index2 + 1];
                int deleteAns = dp[index1 + 1][index2];
                int replaceAns = dp[index1 + 1][index2 + 1];
                ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
            }

            dp[index1][index2] = ans;
        }
    }

    return dp[0][0];
}

int main()
{
    cout << endl
         << endl
         << endl;

    string s1 = "ros";
    string s2 = "horse";

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    cout << "Minimum operations to convert String1 to String is : " << editDistanceTab(s1, s2);

    cout << endl
         << endl
         << endl;
    return 0;
}