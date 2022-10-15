/*
    COUNT WAYS TO NTH STAIR :
    TC : O(2^n) (Checked)
*/

#include <iostream>
using namespace std;

int countWaysToReachNthStairs(int nStairs)
{
    // Base Cases :
    if (nStairs < 0)
    {
        return 0;
    }
    if (nStairs == 0)
    {
        return 1;
    }

    // Recursive Relation
    return (countWaysToReachNthStairs(nStairs - 1) + countWaysToReachNthStairs(nStairs - 2));
}

int main()
{
    int n;
    cout << "Enter Number of Stairs : ";
    cin >> n;
    int ans = countWaysToReachNthStairs(n);
    cout << "Ways to Reach " << n << "Stairs is : " << ans << endl;
    return 0;
}
