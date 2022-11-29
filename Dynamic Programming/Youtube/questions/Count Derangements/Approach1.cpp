#include <iostream>
#define MODANSWER 1000000007;
using namespace std;

long long int countDerangements(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n & 1)
    {
        // odd number
        return (n * countDerangements(n - 1) - 1) % MODANSWER;
    }
    else
    {
        // even number
        return (n * countDerangements(n - 1) + 1) % MODANSWER;
    }
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
