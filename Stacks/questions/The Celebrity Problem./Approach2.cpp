/*
    THE CELEBRITY PROBLEM
        APPROACH 2 :

    HOMEWORK :
        FIND MORE APPROACHES TO SOLVE THIS QUESTION.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b)
{
    if (M[a][b] == 1)
    {
        return true;
    }

    return false;
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    // step 1 : push all elements in stack.
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step 2 :
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int candidate = s.top();
    // step 3 : single element in stack is potential celeb.
    // so verify it.

    // Row Checking.
    bool rowCheck = false;
    int zeroCount = 0;

    for (int col = 0; col < n; col++)
    {
        if (M[candidate][col] == 0)
        {
            zeroCount++;
        }
    }

    if (zeroCount == n)
    {
        rowCheck = true;
    }

    // Column Checking.
    bool colCheck = false;
    int oneCount = 0;
    for (int row = 0; row < n; row++)
    {
        if (M[row][candidate] == 1)
        {
            oneCount++;
        }
    }

    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck && colCheck)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main()
{
    cout << endl
         << endl
         << endl;

    vector<vector<int>> M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    cout << "Celebrity is : " << celebrity(M, 3) << endl;

    cout << endl
         << endl
         << endl;
    return 0;
}
