/*
    REVERSE A STRING :
    TC : O(n)
*/

#include <iostream>
using namespace std;

void reverseString(string &s, int i)
{
    // base case
    if (i > (s.length() - i - 1))
    {
        return;
    }

    // processing.
    swap(s[i], s[(s.length() - i - 1)]);

    // recurence relation
    reverseString(s, ++i);
}

int main()
{
    string s = "abcde";
    cout << s << endl;
    reverseString(s, 0);
    cout << s << endl;
    return 0;
}
