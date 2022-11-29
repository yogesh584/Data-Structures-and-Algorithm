/*
    YOU CAN USE HEAP USING PRIORTY QUEUE (DEFAULT MAX HEAP).
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATING PRIORITY QUEUE     */
    priority_queue<int> pq;
    cout << "---------------Work on Max Heap--------------" << endl;

    /*      INSERTING ELEMENTS IN PRIORITY QUEUE        */
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    /*      FINDING MAX ELEMENTS FROM PRIORITY QUEUE        */
    cout << "Element at top : " << pq.top() << endl;
    pq.pop();
    cout << "Second Element at top : " << pq.top() << endl;

    /*      CREATING MIN HEAP USING PRIORITY QUEUE      */
    priority_queue<int, vector<int>, greater<int>> minheap;

    cout << endl;
    cout << "---------------Work on Min Heap--------------" << endl;

    /*      INSERTING ELEMENTS IN MIN HEAP        */
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    /*      FINDING THE TOP ELEMENT (MINIMUM ELEMENT) FROM MIN HEAP     */
    cout << "Element at top : " << minheap.top() << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
