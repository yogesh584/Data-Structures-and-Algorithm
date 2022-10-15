/*
    RAT IN A MAZE PROBLEM :
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if ((x >= 0) && (x < n) && (y >= 0) && (y < n) && (m[x][y] == 1) && (visited[x][y] == 0))
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &m, int n, int x, int y, vector<string> &ans, string path, vector<vector<int>> &visited)
{
    // Base Case :
    if ((x == n - 1) && (y == n - 1))
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // Down
    int newX = x + 1;
    int newY = y;
    if (isSafe(m, n, newX, newY, visited))
    {
        path.push_back('D');
        solve(m, n, newX, newY, ans, path, visited);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;
    if (isSafe(m, n, newX, newY, visited))
    {
        path.push_back('L');
        solve(m, n, newX, newY, ans, path, visited);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;
    if (isSafe(m, n, newX, newY, visited))
    {
        path.push_back('R');
        solve(m, n, newX, newY, ans, path, visited);
        path.pop_back();
    }

    // Top
    newX = x - 1;
    newY = y;
    if (isSafe(m, n, newX, newY, visited))
    {
        path.push_back('U');
        solve(m, n, newX, newY, ans, path, visited);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    int start = 0;
    int end = 0;
    vector<string> ans;

    if (m[0][0] == 0)
    {
        return ans;
    }

    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";

    solve(m, n, start, end, ans, path, visited);

    return ans;
}

int main()
{

    return 0;
}
