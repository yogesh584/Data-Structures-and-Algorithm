#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &days, vector<int> &costs, int index)
{
    if (index >= days.size())
    {
        return 0;
    }

    // One Day Ticket.
    int oneDayPassAns = costs[0] + solve(days, costs, index + 1);

    // Seven Day Ticket.
    int i;
    for (i = index; i < days.size() && (days[i] < days[index] + 7); i++)
        ;
    int sevenDayPassAns = costs[1] + solve(days, costs, i);

    // Thirty Day Ticket.
    for (i = index; i < days.size() && (days[i] < days[index] + 30); i++)
        ;
    int ThirtyDayAns = costs[2] + solve(days, costs, i);

    // Returning Minimun Costs.
    return min(oneDayPassAns, min(sevenDayPassAns, ThirtyDayAns));
}

int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    if (index >= days.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // One Day Ticket.
    int oneDayPassAns = costs[0] + solve(days, costs, index + 1, dp);

    // Seven Day Ticket.
    int i;
    for (i = index; i < days.size() && (days[i] < days[index] + 7); i++)
        ;
    int sevenDayPassAns = costs[1] + solve(days, costs, i, dp);

    // Thirty Day Ticket.
    for (i = index; i < days.size() && (days[i] < days[index] + 30); i++)
        ;
    int ThirtyDayAns = costs[2] + solve(days, costs, i, dp);

    // Returning Minimun Costs.
    return dp[index] = min(oneDayPassAns, min(sevenDayPassAns, ThirtyDayAns));
}

int solveTab(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, INT32_MAX);
    dp[n] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        // One Day Ticket.
        int oneDayPassAns = costs[0] + dp[index + 1];

        // Seven Day Ticket.
        int i;
        for (i = index; i < days.size() && (days[i] < days[index] + 7); i++)
            ;
        int sevenDayPassAns = costs[1] + dp[i];

        // Thirty Day Ticket.
        for (i = index; i < days.size() && (days[i] < days[index] + 30); i++)
            ;
        int ThirtyDayAns = costs[2] + dp[i];

        // Returning Minimun Costs.
        dp[index] = min(oneDayPassAns, min(sevenDayPassAns, ThirtyDayAns));
    }
    return dp[0];
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
