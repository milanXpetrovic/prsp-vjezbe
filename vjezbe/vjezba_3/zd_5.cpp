#include <iostream>
#include <vector>
using namespace std;

int countSolutions = 0;

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        countSolutions++;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;      
            solveNQueens(board, row + 1, n); 
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> board(n);
    solveNQueens(board, 0, n);

    cout << countSolutions << endl;
    return 0;
}
