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
            USING STL (STANDARD TEMPLATE LIBRARAY)
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATION OF QUEUE      */
    queue<int> q;

    /*      PUSING ELEMENTS TO QUEUE        */
    q.push(17);
    q.push(45);
    q.push(5);
    q.push(4);
    q.push(67);

    /*      POPING ELEMENTS FROM QUEUE      */
    q.pop();

    /*      FINDING SIZE OF QUEUE       */

    cout << "Size of Queue is : " << q.size() << endl;

    /*      CHECKING IS QUEUE IS EMPTY      */

    cout << "Is Queue Empty : " << q.empty() << endl;

    /*      CHECKING FRONT AND BACK OF QUEUE        */

    cout << "Front Element of Queue is : " << q.front() << endl;
    cout << "Back Element of Queue is : " << q.back() << endl;

    /*      PRINTING ALL ELEMENTS OF QUEUE      */
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
