/*
    CIRCULAR QUEUE.
*/

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int size;
    int start;
    int rear;

public:
    /*      CONSTRUCTOR         */
    CircularQueue(int givenSize)
    {
        size = givenSize;
        arr = new int[size];
        start = rear = -1;
    }
    /*      PUSHING TO CIRCULAR QUEUE       */
    bool push(int givenData)
    {
        /*      CHECKING THAT IS QUEUE IS FULL      */
        if (((start == 0) && (rear == size - 1)) || (rear == (start - 1) % (size - 1)))
        {
            cout << "Queue Overflow." << endl;
            return false;
        }

        /*      ADDING ELEMENT TO QUEUE IS COMPLETLY EMPTY    */
        if (start == -1 && rear == -1)
        {
            start = rear = 0;
        }

        /*       ADDING ELEMENT WHEN REAR IS AT END OF QUEUE       */
        else if (start != 0 && rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = givenData;
        return true;
    }

    /*      POPING TO CIRCULAR QUEUE        */
    int pop()
    {
        /*      CHECKING THAT QUEUE IS EMPTY OR NOT         */
        if (start == -1 && rear == -1)
        {
            cout << "Queue Underflow." << endl;
            return -1;
        }

        /*      IF ONLY SINGLE ELEMENT IS PRESENT IN QUEUE      */
        int popElement = arr[start];
        if (start == rear)
        {
            start = rear = -1;
        }
        /*      IF START IS AT END OF QUEUE     */
        else if (start == size - 1)
        {
            start = 0;
        }
        else
        {
            start++;
        }

        return popElement;
    }

    /*      CHECKING THAT QUEUE IS EMPTY OR NOT     */
    bool isEmpty()
    {
        if (start == -1 && rear == -1)
        {
            return true;
        }

        return false;
    }

    /*      FINDING THE FRONT OF QUEUE      */
    int front()
    {
        /*      CHECKING THAT QUEUE IS EMPTY OR NOT         */
        if (start == -1 && rear == -1)
        {
            cout << "Queue Underflow." << endl;
            return -1;
        }

        int frontElem = arr[start];
        return frontElem;
    }
};

/*      DRIVER PROGRAME     */
int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATING A CIRCULAR QUEUE       */
    CircularQueue cq(10);

    /*      PUSHING DATA TO QUEUE       */
    cq.push(45);
    cq.push(4);
    cq.push(5);
    cq.push(15);

    /*      POPING DATA FROM QUEUE      */
    cq.pop();
    cq.pop();
    cq.pop();

    /*      CHECKING THAT QUEUE IS EMPTY OR NOT     */
    switch (cq.isEmpty())
    {
    case true:
        cout << "Queue is Empty." << endl;
        break;

    default:
        cout << "Queue is Not Empty." << endl;
        break;
    }

    /*      FINDING THE FRONT OF QUEUE      */
    int front = cq.front();
    cout << "The Front Element of Queue is : " << front << endl;

    /*      PRINTING THE COMPLETE QUEUE     */
    cout << "Printing the Queue : ";
    while (!cq.isEmpty())
    {
        int front = cq.front();
        cout << front << " ";
        cq.pop();
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
