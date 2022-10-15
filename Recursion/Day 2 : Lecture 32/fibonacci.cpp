/*
    Fibonacci Series :
    TC : O(2^n)
*/

#include <iostream>
using namespace std;

int fib(int n)
{
    // Base Cases :
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    cout << fib(n) << endl;

    // Iterative Way:
    int first = 0;
    int second = 1;
    int nextNumber;

    for (int i = 0; i < (n - 2); i++)
    {
        nextNumber = first + second;
        first = second;
        second = nextNumber;
    }

    cout << nextNumber << endl;

    return 0;
}
