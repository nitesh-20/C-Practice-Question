#include <iostream>
#include <vector>

// N-Queens Problem
// Place N queens on an N x N chessboard so that no two queens attack each other.
// Backtracking solution: prints all possible solutions for given N (N <= ~12 recommended).

bool isSafe(const std::vector<int> &queens, int row, int
     col) {
    // queens[i] = column of queen in row i
    for (int r = 0; r < row; ++r) {
        int c = queens[r];
        if (c == col) return false;                  // same column
        if (abs(c - col) == abs(r - row)) return false; // same diagonal
    }
    return true;
}

void solveNQueens(int n, int row, std::vector<int> &queens,
                  std::vector<std::vector<int>> &solutions) {
    if (row == n) {
        solutions.push_back(queens);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(n, row + 1, queens, solutions);
        }
    }
}

void printBoard(const std::vector<int> &queens) {
    int n = static_cast<int>(queens.size());
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (queens[r] == c) std::cout << "Q ";
            else std::cout << ". ";
        }
        std::cout << '\n';
    }
}

int main() {
    std::cout << "===== N-Queens Backtracking Demo =====\n";

    int n;
    std::cout << "Enter N (size of board, e.g., 4 to 10): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid N. Exiting.\n";
        return 0;
    }

    std::vector<int> queens(n, -1);
    std::vector<std::vector<int>> solutions;

    solveNQueens(n, 0, queens, solutions);

    if (solutions.empty()) {
        std::cout << "No solutions found for N = " << n << "\n";
    } else {
        std::cout << "Total solutions for N = " << n << ": " << solutions.size() << "\n";
        for (size_t i = 0; i < solutions.size(); ++i) {
            std::cout << "Solution " << i + 1 << ":\n";
            printBoard(solutions[i]);
            std::cout << '\n';
        }
    }

    return 0;
}
