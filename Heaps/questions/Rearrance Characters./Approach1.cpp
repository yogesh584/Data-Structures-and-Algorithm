#include <iostream>
using namespace std;

/*      HEAP CLASS      */
class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {

        // Step 1 : Add element to the end of array.
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Step 2 : Find the right position of element.
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // Step 1 : Put Last Node to First position
        arr[1] = arr[size];

        // Step 2 : Removing Last Node.
        size--;

        // Step 3 : Put First Node (Root Node) to its right position.
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

/*      HEAPIFY ALGO        */
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex <= size && arr[largest] < arr[leftIndex])
        largest = leftIndex;

    if (rightIndex <= size && arr[largest] < arr[rightIndex])
        largest = rightIndex;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATING A HEAP     */
    Heap h;

    /*      INSERTING ELEMENTS TO HEAP      */
    h.insert(50);
    h.insert(51);
    h.insert(52);
    h.insert(53);
    h.insert(54);

    /*      PRINTING THE HEAP       */
    cout << "Heap is : ";
    h.print();

    cout << endl
         << endl
         << endl;

    return 0;
}
