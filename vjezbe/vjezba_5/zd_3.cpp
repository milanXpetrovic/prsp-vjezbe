#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 

void dfs(vector<vector<char>>& grid, int x, int y) {
    stack<pair<int, int>> s;
    s.push({x, y});

    while (!s.empty()) {
        auto [cur_x, cur_y] = s.top();
        s.pop();
        
        grid[cur_x][cur_y] = 'S';

        for (const auto& dir : DIRS) {
            int new_x = cur_x + dir[0];
            int new_y = cur_y + dir[1];

            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() &&
                grid[new_x][new_y] == 'O') {
                s.push({new_x, new_y});
            }
        }
    }
}

void conquerRegions(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        if (grid[i][0] == 'O') dfs(grid, i, 0); 
        if (grid[i][cols - 1] == 'O') dfs(grid, i, cols - 1); 
    }
    for (int j = 0; j < cols; ++j) {
        if (grid[0][j] == 'O') dfs(grid, 0, j); 
        if (grid[rows - 1][j] == 'O') dfs(grid, rows - 1, j); 
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'O') {
                grid[i][j] = 'X'; 
            } else if (grid[i][j] == 'S') {
                grid[i][j] = 'O'; 
            }
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    conquerRegions(grid);

    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}

