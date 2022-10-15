/*
    SUBSEQUENCES OF STRING :
*/

#include <iostream>
using namespace std;

void solve(string str, string output, int index, string &ans)
{

    // Base Case
    if (index > str.length() - 1)
    {
        if (output != "")
        {
            ans.append(output + " ");
        }

        return;
    }

    // Exclude
    solve(str, output, index + 1, ans);

    // include
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

string subSequence(string str)
{
    string ans = "";
    string output = "";
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}

int main()
{
    string str = "abc";
    cout << subSequence(str) << endl;
    return 0;
}
