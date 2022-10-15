/*
    QUICK SORT
*/
#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    int index1 = start;
    int index2 = end;
    while (index1 < pivotIndex && index2 > pivotIndex)
    {
        while (arr[index1] < pivot)
        {
            index1++;
        }

        while (arr[index2] > pivot)
        {
            index2--;
        }
        if (index1 < pivotIndex && index2 > pivotIndex)
        {
            swap(arr[index1++], arr[index2--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
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
