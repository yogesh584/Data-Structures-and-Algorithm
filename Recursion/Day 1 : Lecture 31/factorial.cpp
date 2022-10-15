/*
    FACTORIAL
    TC : O(n)
*/

#include <iostream>
using namespace std;

int factorial(int num)
{
    // Base Condition
    if (num == 0)
        return 1;
    /*
    int smallerProblem = factorial(num - 1);
    int biggerProblem = num * smallerProblem; // Recursive Relation.
    return biggerProblem;
    */

    return num * factorial(num - 1);
}

int main()
{
    int num;
    cout << "Enter Your Number : ";
    cin >> num;

    int ans = factorial(num);
    cout << "Factorial of " << num << " is : " << ans << endl;

    return 0;
}
