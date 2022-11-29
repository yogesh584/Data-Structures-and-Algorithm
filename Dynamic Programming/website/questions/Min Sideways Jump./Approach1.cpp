#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> obs, int currentLane, int currentPos, vector<vector<int>> dp)
{
    // base case
    int lastPos = obs.size() - 1;
    if (currentPos == lastPos)
    {
        return 0;
    }
    if (dp[currentLane][currentPos] != -1)
    {
        return dp[currentLane][currentPos];
    }
    int finalAns = 0;
    // stright movement
    if (obs[currentPos + 1] != currentLane)
    {
        finalAns = solve(obs, currentLane, currentPos + 1, dp);
    }
    else
    {
        // sideways movement
        int ans = INT32_MAX;
        for (int i = 0; i <= 3; i++)
        {
            if (i != currentLane && obs[currentPos] != i)
            {
                ans = min(ans, 1 + solve(obs, i, currentPos, dp));
            }
        }
        finalAns = ans;
    }

    return dp[currentLane][currentPos] = finalAns;
}

int minSideways(vector<int> obs)
{
    int currLane = 2;
    int currPos = 0;
    int n = obs.size();
    vector<vector<int>> dp(4, vector<int>(n + 1, -1));

    return solve(obs, currLane, currPos, dp);
}

int minSidewaysTab(vector<int> obs)
{
    int currLane = 2;
    int currPos = 0;
    int n = obs.size();
    vector<vector<int>> dp(4, vector<int>(n + 1, INT32_MAX));

    for (int i = 0; i <= 3; i++)
    {
        dp[i][obs.size() - 1] = 0;
    }
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<int> obs;
    obs.push_back(0);
    obs.push_back(0);
    obs.push_back(1);
    obs.push_back(2);
    obs.push_back(3);

    cout << "Minimum Jumps Required is : " << minSideways(obs) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
