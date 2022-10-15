/*
    MERGE SORT :

    IMPORTANT ARTICLE :
        WHY MERGE SORT PREFERRED FOR LINKED LIST OVER ARRAY.
        LINK : https://www.codingninjas.com/codestudio/library/why-is-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists
*/

#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = (mid - start + 1);
    int len2 = (end - mid);

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // Copying Array Elements to Left Array.
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }

    // Copying Array Elements to Right Array.
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }

    // Mergin two sorted Arrays.
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    // checking and Adding Value to arr.
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[mainArrayIndex++] = arr1[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

    // If Arr1 Length is Greather than Arr2 length.
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = arr1[index1++];
    }

    // If Arr2 Length is Greather Than Arr1 length
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = arr2[index2++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int arr[], int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // left Part Sort
    mergeSort(arr, start, mid);

    // right Part Sort
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{
    int arr[5] = {3, 7, 0, 1, 5};
    int size = 5;

    mergeSort(arr, 0, size - 1);

    // printing The Array :
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
