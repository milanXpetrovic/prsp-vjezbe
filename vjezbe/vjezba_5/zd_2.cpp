#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
        return 0;
    }

    grid[x][y] = 0;

    int area = 1; 
    area += dfs(grid, x + 1, y); 
    area += dfs(grid, x - 1, y); 
    area += dfs(grid, x, y + 1); 
    area += dfs(grid, x, y - 1); 

    return area;
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

    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                int area = dfs(grid, i, j); 
                maxArea = max(maxArea, area); 
            }
        }
    }

    cout << maxArea << endl;

    return 0;
}
