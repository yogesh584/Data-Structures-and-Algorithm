#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start + (end - start) / 2);

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Adding Values to Both Array.
    int mainIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }

    // mearging Two Sorted Arrays
    mainIndex = start;
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainIndex++] = first[index1++];
        }
        else
        {
            arr[mainIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int start, int end)
{
    int mid = (start + (end - start) / 2);

    // Base Case
    if (start >= end)
    {
        return;
    }

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{
    cout << endl
         << endl
         << endl;

    int arr[5] = {2, 5, 1, 6, 9};
    int size = 5;

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl
         << endl;
    return 0;
}
