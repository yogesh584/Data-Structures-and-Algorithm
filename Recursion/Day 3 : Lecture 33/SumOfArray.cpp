/*
    FIND THE SUM OF THE ARRAY :
    TC : O(n)
*/

#include <iostream>
using namespace std;

int sumOfArray(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    if (size == 0)
    {
        return 0;
    }

    return (arr[0] + sumOfArray((arr + 1), (size - 1)));
}

int main()
{
    cout << endl
         << endl
         << endl;

    int arr[] = {3, 1, 5, 1, 6};
    cout << sumOfArray(arr, 5) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
