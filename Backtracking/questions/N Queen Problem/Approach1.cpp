#include <iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &board, int n, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // checking row
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    // checking col
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // checking diagonaly
    int x = row;
    int y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(vector<vector<int>> &board, int n, vector<vector<int>> &ans, int col)
{
    if (col == n)
    {
        addSolution(board, n, ans);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(board, n, ans, col + 1);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    int col = 0;

    solve(board, n, ans, col);
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
