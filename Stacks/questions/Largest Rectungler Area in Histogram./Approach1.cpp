/*
    LARGEST RECUNGLER AREA IN HISTOGRAM.    (IMPORTANT QUESTION)
        COMPANIES :
            GOOGLE,MICROSOFT

        LINK : https://leetcode.com/problems/largest-rectangle-in-histogram/

        APPROACH 1 :
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    vector<int> nextSmallerElements(vector<int> arr, int n)
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
    vector<int> prevSmallerElements(vector<int> arr, int n)
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

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

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
};
int main()
{

    return 0;
}
