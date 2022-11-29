/*
    HEAP :
        WHAT : COMPLEATE BINARY TREE THAT COMES WITH HEAP ORDER PROPERTYS.

        COMPLETE BINARY TREE :
            BINARY TREE WITH SOME EXTRA PROPERTIES :
                1. EVERY LEVEL IS COMPLETLY FILLED EXCEPT LAST LEVEL.
                2. NODES ALWAYS ADDED FROM LEFT.

        HEAP ORDER PROPERTYS :
            1. MAX HEAP :
                VALUE OF EVERY CHILD NODE IS LESS THEN PARENT NODE.
            2. MIN HEAP :
                VALUE OF EVERY CHILD NODE IS GREATHER THEN PARENT NODE.

        USE OF HEAP :
            IF YOU WANT TO ACCESS MINIMUM OR MAXIMUM ELEMENT QUICKLY.
*/

/*
    IMPLEMENTATION OF HEAP :
        USING ARRAYS :
            PARENT : i/2
            LEFT CHILD : 2*i (1 based indexing)
            RIGHT CHILD : 2*i+1 (1 based indexing)
            LEFT CHILD : 2*i + 1 (0 based indexing)
            RIGHT CHILD : 2*i + 2 (0 based indexing)
            i is NODE INDEX IN ARRAY.
            NODES FROM (size/2 + 1) to size are leaf nodes.

            INSERTATION :
                WE NEVER INSERT ANY ELEMENT AT 0TH INDEX FOR HEAP. because of easy calculation.
                TC : O(logN)

            DELETION :
                ALWAYS DELETING ROOT NODE.
                TC : O(logN)

            HEAPIFY ALGORITHUM :
                TC : O(logN)

            NOTE :
                1. Time Complexity of getting the Minimum value from min heap is : O(1)
                2. Time Complexity of getting the maximum value from min heap is : O(N) (Because we need to traverse the complete min heap)
                3. Time Complexity of getting the Maximum value from max heap is : O(1)
                4. Time Complexity of getting the minimum value from max heap is : O(N) (Because we need to traverse the complete max heap)
                5. Time Complexity to build a heap is : O(N*logN)
*/

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

/*      TC : nlog(n)        */
void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        // step 1 : Put First Element to last
        swap(arr[size], arr[1]);
        size--;

        // Heapify the heap.
        heapify(arr, size, 1);
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
    h.print();

    /*      DELETE FROM HEAP        */
    h.deleteRoot();
    h.print();

    /*      HEAPIFY ALGO        */
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    for (int i = size / 2; i > 0 / 2; i--)
    {
        heapify(arr, size, i);
    }

    // Print The Array After heapify.
    cout << "Printing the the Array : ";
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }

    /*      HEAP SORT       */
    heapSort(arr, size);

    cout << endl;

    cout << "Printing sorted Array : ";
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
