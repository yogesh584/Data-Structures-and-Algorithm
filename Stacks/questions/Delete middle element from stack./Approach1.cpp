/*
    REVERSE MIDDLE ELEMENT FROM STACK.
*/
#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &st, int count, int size)
{
    if (count == size / 2)
    {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    deleteMiddle(st, count + 1, size);

    st.push(num);
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int stackSize = st.size();
    int count = 0;

    deleteMiddle(st, count, stackSize);

    /*      ITERATING STACK     */
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl
         << endl;
    return 0;
}
