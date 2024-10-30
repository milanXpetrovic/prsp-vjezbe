#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
        return;
    }

    grid[x][y] = 0;

    dfs(grid, x + 1, y); 
    dfs(grid, x - 1, y); 
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1); 
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> grid(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int islandCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                islandCount++;
                dfs(grid, i, j); 
            }
        }
    }

    cout << islandCount << endl;

    return 0;
}
