/*
    CHECK PALINDROME :
    TC : O(n)
*/

#include <iostream>
using namespace std;

bool checkPailndrome(string s, int i)
{
    if (i > (s.length() - 1 - i))
    {
        return true;
    }
    if (s[i] != s[(s.length() - 1 - i)])
    {
        return false;
    }

    return checkPailndrome(s, ++i);
}

int main()
{
    string s = "babbab";
    cout << checkPailndrome(s, 0) << endl;
    return 0;
}
