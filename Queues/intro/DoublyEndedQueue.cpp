/*
    DOUBLY ENDED QUEUE
*/
#include <iostream>
using namespace std;

class Dequeue
{
private:
    int *arr;
    int size;
    int start;
    int end;

public:
    /*      CONSTRUCTOR     */
    Dequeue(int givenSize)
    {
        size = givenSize;
        arr = new int[size];
        start = end = -1;
    }

    /*      PUSH FRONT      */
    bool push_front(int givenData)
    {
        /*      CHECKING THAT QUEUE IS FULL OT NOT      */
        if ((start == 0 && end == size - 1) || (end == (start - 1) % (size - 1)))
        {
            cout << "Queue OverFlow." << endl;
            return false;
        }

        if (start == -1 && end == -1)
        {
            start = end = 0;
        }

        else if (start == 0 && end != size - 1)
        {
            start = size - 1;
        }
        else
        {
            start--;
        }

        arr[start] = givenData;
        return true;
    }

    /*      PUSH BACK       */
    bool push_back(int givenData)
    {
        /*      CHECKING THAT QUEUE IS FULL OT NOT      */
        if ((start == 0 && end == size - 1) || (end == (start - 1) % (size - 1)))
        {
            cout << "Queue OverFlow." << endl;
            return false;
        }

        if (start == -1 && end == -1)
        {
            start = end = 0;
        }

        else if (end == size - 1 && start != 0)
        {
            end = 0;
        }
        else
        {
            end++;
        }

        arr[end] = givenData;
        return true;
    }

    /*      POP FRONT       */
    int pop_front()
    {
        if (start == end)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
    }

    /*      POP BACK       */
    int pop_back()
    {
    }
};

int main()
{

    return 0;
}
