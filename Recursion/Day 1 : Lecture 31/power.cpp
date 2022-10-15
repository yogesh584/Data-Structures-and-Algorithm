/*
    POWER OF TWO :
    TC : O(n)
*/

#include <iostream>
using namespace std;

int power(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    return 2 * power(n - 1); // Recurence Relation
}

int main()
{
    int n;
    cin >> n;

    int ans = power(n);
    cout << ans << endl;
    return 0;
}
