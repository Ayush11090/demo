#include <iostream>
#include <vector>
using namespace std;

int isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return 0;
    }
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j]) return 0;
    }
    for (int i = row - 1, j = col + 1; j < n && i >= 0; j++, i--)
    {
        if (board[i][j]) return 0;
    }

    return 1;
}
int solve(vector<vector<int>> &board, int row)
{
    int n = board.size();

    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return 1;
    }

    for (int col = 0; col < n; col++)
    {

        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            if (solve(board, row + 1)) return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}
int main()
{
    int n = 8;
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solve(board, 0))
        cout << "No solution";
    return 0;
}