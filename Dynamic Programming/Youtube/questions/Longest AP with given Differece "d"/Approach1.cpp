#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubsequence(vector<int> &arr, int difference)
{
     unordered_map<int, int> dp;
     int ans = 0;
     for (int i = 0; i < arr.size(); i++)
     {
          int temp = arr[i] - difference;
          int tempAns = 0;

          // Check answer exist for temp already or not.
          if (dp.count(temp))
               tempAns = dp[temp];

          // current answer update.
          dp[arr[i]] = 1 + tempAns;

          // ans update.
          ans = max(ans, dp[arr[i]]);
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
