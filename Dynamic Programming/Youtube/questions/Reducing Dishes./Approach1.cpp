#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
{
     // base case
     if (index == satisfaction.size())
     {
          return 0;
     }
     if (dp[index][time] != -1)
     {
          return dp[index][time];
     }

     int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, dp);
     int exclude = solve(satisfaction, index + 1, time, dp);

     return dp[index][time] = max(include, exclude);
}

int solveTab(vector<int> &satisfaction)
{
     int n = satisfaction.size();
     vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, 0));
     for (int index = n - 1; index >= 0; index--)
     {
          for (int time = n - 1; time >= 0; time--)
          {
               int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
               int exclude = dp[index + 1][time];

               dp[index][time] = max(include, exclude);
          }
     }

     return dp[0][0];
}

int solveSO(vector<int> &satisfaction)
{
     int n = satisfaction.size();
     vector<int> curr(n + 1, 0);
     vector<int> next(n + 1, 0);
     for (int index = n - 1; index >= 0; index--)
     {
          for (int time = n - 1; time >= 0; time--)
          {
               int include = satisfaction[index] * (time + 1) + next[time + 1];
               int exclude = next[time];

               curr[time] = max(include, exclude);
          }
          next = curr;
     }

     return curr[0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
     // sort the vector
     sort(satisfaction.begin(), satisfaction.end());

     // vector<vector<int>> dp(satisfaction.size()+1,vector<int> (satisfaction.size()+1,-1));
     // return solve(satisfaction,0,0,dp);

     // return solveTab(satisfaction);
     return solveSO(satisfaction);
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
