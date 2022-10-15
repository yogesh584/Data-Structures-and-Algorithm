/*
    INTRO TO STACKS USING STL.
        WHAT IS STACK : A LIFO DATA STRUCTURE.
        OPERATIONS IN STACK :(ONLY IMPORTANT)
            1. PUSH
            2. POP
            3. TOP
            4. EMPTY
            5. SIZE
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cout << endl
         << endl
         << endl;

    /*      CREATION OF STACK       */
    stack<int> s;

    /*      PUSH OPERATION          */
    s.push(2);
    s.push(3);

    /*      POP OPERATION           */
    s.pop();

    /*      TOP OPERATION           */
    cout << "Top Element of Stack is : " << s.top() << endl;

    /*      EMPTY OPERATION         */
    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    /*      SIZE OPERATION          */
    cout << "Size of Stack is : " << s.size() << endl;

    cout << endl
         << endl
         << endl;

    return 0;
}
