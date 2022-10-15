/*
    BINERY SEARCH :
    TC : O(logn)
*/

#include <iostream>
using namespace std;

bool BinerySearch(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        return false;
    }

    int mid = (start + (end - start) / 2);
    if (arr[mid] == target)
    {
        return true;
    }
    else if (arr[mid] > target)
    {
        return BinerySearch(arr, start, mid - 1, target);
    }
    else
    {
        return BinerySearch(arr, mid + 1, end, target);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 6, 7, 8};
    cout << BinerySearch(arr, 0, 5, 7) << endl;
    return 0;
}
