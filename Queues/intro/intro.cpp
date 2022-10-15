/*
    QUEUE :
        WHAT : DATA STRUCTURE WITH FIFO (First In First Out).

        SOME REQUIRED FUNCTION OF QUEUE :
            1. PUSH/INSERT
            2. POP/REMOVE
            3. SIZE
            4. IS EMPTY
            4. FRONT
            5. BACK

        IMPLEMENTATION :
            USING ARRAY.
*/

#include <iostream>
using namespace std;

class Queue
{
    int front;
    int back;
    int size;
    int *arr;

public:
    Queue(int givenSize)
    {
        this->size = givenSize;
        this->front = 0;
        this->back = 0;
        this->arr = new int[givenSize];
    }

    bool push(int givenData)
    {
        if (back == size)
        {
            arr[back] = givenData;
            back++;
            return true;
        }
        else
        {
            cout << "Queue Overflow" << endl;
            return false;
        }
    }

    int pop()
    {
        if (front < back)
        {
            int tempElem = arr[front];
            front++;
            return tempElem;
        }
        else
        {
            cout << "Queue is Underflow" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (front == back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return this->size;
    }
};

int main()
{

    return 0;
}
