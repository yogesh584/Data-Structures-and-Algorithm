#include <iostream>
#include <queue>
using namespace std;

void solve(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int num = q.front();
    q.pop();

    solve(q);

    q.push(num);
}

queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q = rev(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
