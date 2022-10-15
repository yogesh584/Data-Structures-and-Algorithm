/*
    MINIMUM COST TO MAKE STRING VALID.
*/

#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    // odd condition
    if (str.length() & 1)
    {
        return -1;
    }

    // even condition.
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    // expression is invalid.
    int a = 0;
    int b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }

    int ans = ((a + 1) / 2 + (b + 1) / 2);

    return ans;
}

int main()
{
    string s = "{{{}";
    cout << findMinimumCost(s) << endl;
    return 0;
}
