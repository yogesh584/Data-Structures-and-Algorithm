#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, int newx, int newy)
{
     if ((newx >= 0 && newy >= 0) && (newx < n && newy < n) && (visited[newx][newy] == 0) && arr[newx][newy] == 1)
     {
          return true;
     }
     return false;
}

void solve(vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, int x, int y, vector<string> &ans, string output)
{
     if (x == n - 1 && y == n - 1)
     {
          ans.push_back(output);
          return;
     }

     visited[x][y] = 1;

     // Down
     if (isSafe(arr, n, visited, x + 1, y))
     {
          solve(arr, n, visited, x + 1, y, ans, output + 'D');
     }

     // Left
     if (isSafe(arr, n, visited, x, y - 1))
     {
          solve(arr, n, visited, x, y - 1, ans, output + 'L');
     }

     // Right
     if (isSafe(arr, n, visited, x, y + 1))
     {
          solve(arr, n, visited, x, y + 1, ans, output + 'R');
     }

     // Up
     if (isSafe(arr, n, visited, x - 1, y))
     {
          solve(arr, n, visited, x - 1, y, ans, output + 'U');
     }

     visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
     int x = 0;
     int y = 0;
     vector<string> ans;

     // corner case.
     if (arr[x][y] == 0)
     {
          return ans;
     }

     string output = "";
     vector<vector<bool>> isVisited(n, vector<bool>(n, 0));
     solve(arr, n, isVisited, x, y, ans, output);
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
