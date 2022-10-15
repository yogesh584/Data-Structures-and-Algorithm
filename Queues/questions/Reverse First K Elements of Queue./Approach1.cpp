/*
    REVERSE FIRST K ELEMENTS OF QUEUE.
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstKElements(queue<int> q, int k)
{
    stack<int> s;

    // adding elements to stack.
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // adding elements to queue.
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    // arrenging queue.

    // Finding Length of queue.
    int n = q.size();

    for (int i = 0; i < n - k; i++)
    {
        int elem = q.front();
        q.pop();
        q.push(elem);
    }

    return q;
}

int main()
{
    cout << endl
         << endl
         << endl;

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q = reverseFirstKElements(q, 3);

    // Printing the queue
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
