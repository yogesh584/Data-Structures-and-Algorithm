#include <iostream>
using namespace std;

int editDistance(string s1, string s2, int index1, int index2)
{
    // base case
    if (index1 == s1.length() && index2 != s2.length())
    {
        return (s2.length() - index2);
    }
    if (index1 != s1.length() && index2 == s2.length())
    {
        return (s1.length() - index1);
    }
    if (index1 == s1.length() && index2 == s2.length())
    {
        return 0;
    }
    int ans = 0;
    if (s1[index1] == s2[index2])
    {
        ans = editDistance(s1, s2, index1 + 1, index2 + 1);
    }
    else
    {
        int insertAns = editDistance(s1, s2, index1, index2 + 1);
        int deleteAns = editDistance(s1, s2, index1 + 1, index2);
        int replaceAns = editDistance(s1, s2, index1 + 1, index2);
        ans = min(insertAns, deleteAns, replaceAns);
    }

    return ans;
}

int main()
{
    cout << endl
         << endl
         << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
