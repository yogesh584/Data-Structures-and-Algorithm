/*
    Is Sorted Array :
        Find that is Array is Sorted by using Recursion.
    TC : O(n)

*/

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    // Base Case :
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }

    // Recurence Relation.
    return isSorted((arr + 1), (size - 1));
}

int main()
{
    int arr[] = {4, 2, 3, 5, 6};
    cout << isSorted(arr, 5) << endl;
    return 0;
}
