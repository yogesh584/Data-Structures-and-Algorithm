/*
    MAX RECTANGLE IN BINARY MATRIX WITH ALL 1'S.
        APPROACH 1 :
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElements(int *arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElements(int *arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int *heights, int n)
{
    vector<int> next(n);
    next = nextSmallerElements(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElements(heights, n);

    int area = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;

        area = max(newArea, area);
    }

    return area;
}

int maxArea(int M[][4], int n, int m)
{
    // compute area for first row.
    int area = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update : by adding previous row's value.
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }

        area = max(area, largestRectangleArea(M[i], m));
    }

    return area;
}

int main()
{
    cout << endl
         << endl
         << endl;

    int M[][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout << "Max Area is : " << maxArea(M, 4, 4);

    cout << endl
         << endl
         << endl;
    return 0;
}
