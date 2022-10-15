/*
    QUICK SORT :

    IMPORTANT :
        Why is Quick Sort preferred for Arrays and Merge Sort for Linked Lists?
        LINK : https://www.codingninjas.com/codestudio/library/why-is-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists
*/
#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int cnt = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    int pivotIndex = start + cnt;

    swap(arr[start], arr[pivotIndex]);

    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{

    // Base Case :
    if (start >= end)
    {
        return;
    }

    int partitionElementIndex = partition(arr, start, end);

    // Sorting Left Part
    quickSort(arr, start, partitionElementIndex - 1);

    // Sorting Right Part
    quickSort(arr, partitionElementIndex + 1, end);
}

int main()
{
    cout << endl
         << endl
         << endl;
    int arr[5] = {2, 4, 1, 6, 9};
    int size = 5;
    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
