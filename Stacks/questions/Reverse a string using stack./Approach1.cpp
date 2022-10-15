/*
    REVERSE A STRING USING STACK.
        APPROACH 1 :

    PROPERTY OF STACK :
        1. ANYTHING YOU PUT IN STACK IT WILL REVERSE IT.

*/
#include <iostream>
#include <stack>
using namespace std;

string reverseString(string givenString)
{
    stack<int> st;

    for (int i = 0; i < givenString.length(); i++)
    {
        st.push(givenString[i]);
    }

    string ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    string name = "yogesh";
    cout << name << endl;

    string reverseName = reverseString(name);

    cout << reverseName << endl;
    return 0;
}
