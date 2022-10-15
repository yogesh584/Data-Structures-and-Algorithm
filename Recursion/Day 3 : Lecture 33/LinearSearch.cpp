/*
    LINEAR SEARCH :
    TC : O(n)
*/

#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int target)
{
    // Base Case:
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == target)
    {
        return true;
    }
    if (size == 1)
    {
        return false;
    }

    return LinearSearch(arr + 1, size - 1, target);
}

int main()
{
    int arr[] = {2, 4, 6, 1, 8, 3};
    cout << LinearSearch(arr, 6, 10) << endl;
    return 0;
}
