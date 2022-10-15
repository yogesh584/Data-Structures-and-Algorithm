/*
    SORT A STACK.
*/
#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || (!s.empty() && s.top() < x))
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    sortedInsert(s, x);

    s.push(num);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s, num);
}

int main()
{
    cout << endl
         << endl
         << endl;

    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

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
