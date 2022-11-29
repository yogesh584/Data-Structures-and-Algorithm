#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2)
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

int longestPalindromicSubsequence(string s1)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return lcs(s1, s2);
}

int main()
{
    cout << endl
         << endl
         << endl;

    string text = "amomb";
    cout << "Length of Longest Palindromic Subsequence is : " << longestPalindromicSubsequence(text);

    cout << endl
         << endl
         << endl;
    return 0;
}
