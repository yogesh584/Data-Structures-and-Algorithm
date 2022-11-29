#include <iostream>
#include <vector>
using namespace std;

// Dp with Binary Search
int solveOptimal(int n, int a[])
{
    if (n == 0)
    {
        return 0;
    }
    vector<int> ans;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
        { // ans.back() is last element of ans vector.
            ans.push_back(a[i]);
        }
        else
        {
            // find index of just bada element in ans.
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, int a[])
{
    return solveOptimal(n, a);
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
