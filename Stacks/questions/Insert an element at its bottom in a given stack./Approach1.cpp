/*
    INSERT AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK.
        APPROACH 1 :
*/
#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &mystack, int x)
{
    // x is given number to insert at bottom.
    stack<int> temp;

    while (!mystack.empty())
    {
        temp.push(mystack.top());
        mystack.pop();
    }
    mystack.push(x);

    while (!temp.empty())
    {
        mystack.push(temp.top());
        temp.pop();
    }
}

int main()
{
    cout << endl
         << endl
         << endl;

    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(7);

    pushAtBottom(s, 9);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl
         << endl
         << endl;
    return 0;
}
