/*
    CALCULATION OF A TO THE POWER OF B :
    TC : O(logn)
*/

#include <iostream>
using namespace std;

int power(int a, int b)
{

    // Base Case :
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b / 2);
    if (b & 1) // odd
    {
        return a * ans * ans;
    }
    else
    {
        return ans * ans;
    }
}

int main()
{
    cout << power(2, 10) << endl;
    return 0;
}
