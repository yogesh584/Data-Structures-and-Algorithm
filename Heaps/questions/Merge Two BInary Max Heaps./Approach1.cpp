#include <iostream>
#include <vector>
using namespace std;

/*      HEAPIFY ALGO        */
void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if (leftIndex < size && arr[largest] < arr[leftIndex])
        largest = leftIndex;

    if (rightIndex < size && arr[largest] < arr[rightIndex])
        largest = rightIndex;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // step 1: merge both arrays
    vector<int> ans;
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    // step 2 : build heap using merged array.
    int size = ans.size();
    for (int i = ((size / 2) - 1); i >= 0; i--)
    {
        heapify(ans, size, i);
    }
    return ans;
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};

    vector<int> heap3 = mergeHeaps(heap1, heap2, 4, 3);

    for (int i = 0; i < heap3.size(); i++)
    {
        cout << heap3[i] << " ";
    }

    cout << endl
         << endl
         << endl;

    return 0;
}
