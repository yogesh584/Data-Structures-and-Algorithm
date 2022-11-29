/*
    KTH SMALLEST ELEMENT IN AN UNSORTED ARRAY.
*/
#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int arr[], int size, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < size; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    cout << endl
         << endl
         << endl;

    /*      FINDING THE KTH SMALLEST ELEMENT     */
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = 7;
    int k = 3;
    cout << "Kth Smallest Element is : " << kthSmallestElement(arr, size, k);

    cout << endl
         << endl
         << endl;

    return 0;
}
