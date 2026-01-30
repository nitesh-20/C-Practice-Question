#include <iostream>
#include <vector>
using namespace std;

// Medium level DSA: Sudoku solver using backtracking (9x9)

bool isSafe(const vector<vector<int>> &board, int row, int col, int num) {
    // Row and column check
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
    }

    // 3x3 subgrid check
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board[startRow + r][startCol + c] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &board, int row = 0, int col = 0) {
    if (row == 9) return true;           // solved all rows
    if (col == 9) return solveSudoku(board, row + 1, 0); // next row

    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1); // skip filled cell
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false; // no number fits here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Sudoku Solver (9x9) using Backtracking =====\n";
    cout << "Enter a 9x9 Sudoku grid, use 0 for empty cells:\n";

    vector<vector<int>> board(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] < 0 || board[i][j] > 9) {
                cout << "Invalid value, forcing to 0.\n";
                board[i][j] = 0;
            }
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}
