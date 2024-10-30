// CSES Chessboard and Queens

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countWays = 0;
vector<string> board(8);
vector<bool> col(8, false), diag1(15, false), diag2(15, false);

void solve(int row) {
    if (row == 8) {
        countWays++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '.' && !col[c] && !diag1[row + c] && !diag2[row - c + 7]) {
            col[c] = diag1[row + c] = diag2[row - c + 7] = true;
            solve(row + 1);
            col[c] = diag1[row + c] = diag2[row - c + 7] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    solve(0);
    cout << countWays << endl;
    return 0;
}
