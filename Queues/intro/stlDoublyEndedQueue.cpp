/*
    STL DOUBLY ENDED QUEUE.
*/
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATING A DOUBLY ENDED QUEUE       */
    deque<int> dq;

    /*      PUSHING ELEMENTS OF DOUBLY ENDED QUEUE AT FRONT     */
    dq.push_front(3);
    dq.push_front(2);
    dq.push_front(1);

    /*      PUSHING ELEMENTS OF DOUBLY ENDED QUEUE AT BACK     */
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6);

    /*      POPING ELEMENTS FROM DOUBLY ENDED QUEUE FROM FRONT      */
    dq.pop_front();

    /*      POPING ELEMENTS FROM DOUBLY ENDED QUEUE FROM END        */
    dq.pop_back();

    /*      FINDING THE SIZE OF DOUBLY ENDED QUEUE      */
    int size = dq.size();
    cout << "Size of Dequeue is : " << size << endl;

    /*      FINDING THE FRONT OF DOUBLY ENDED QUEUE     */
    int front = dq.front();
    cout << "Front of Dequeue is : " << front << endl;

    /*      CHECKING THAT IS DOUBLY ENDED QUEUE IS EMPTY OR NOT     */
    switch (dq.empty())
    {
    case true:
        cout << "Queue is Empty." << endl;
        break;

    default:
        cout << "Queue is Not Empty." << endl;
        break;
    }

    /*      PRINTING THE DOUBLY ENDED QUEUE      */
    cout << "Printing the Dequeue : ";
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << endl
         << endl
         << endl;

    return 0;
}
