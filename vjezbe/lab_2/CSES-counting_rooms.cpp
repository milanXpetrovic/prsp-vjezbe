#include<iostream>
using namespace std;
int ROWS, COLS;
// row (i) = i/COLS
// column (j) = i%COLS

void searchMap(char* mapMatrix, bool* visited, int row, int col) {
    if (row<0 || row>=ROWS || col<0 || col>=COLS || mapMatrix[row*COLS + col]!='.' || visited[row*COLS + col])
        return;

    visited[row*COLS + col] = 1;

    searchMap(mapMatrix, visited, row-1, col); // walking up
    searchMap(mapMatrix, visited, row+1, col); // walking down
    searchMap(mapMatrix, visited, row, col-1); // walking left
    searchMap(mapMatrix, visited, row, col+1); // walking right
}

int countRooms(char* mapMatrix, bool* visited) {
    int counter = 0;
    for (int i=0; i<ROWS*COLS; i++) {
        if (mapMatrix[(i/COLS)*COLS + i%COLS]=='.' && !(visited[(i/COLS)*COLS + i%COLS])) {
            searchMap(mapMatrix, visited, i/COLS, i%COLS);
            counter++;
        }
    }
    return counter;
}

int main()
{
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>ROWS>>COLS;
    char* mapMatrix = new char[ROWS*COLS];
    bool* visited = new bool[ROWS*COLS];

    for (int i=0; i<ROWS*COLS; i++) {
        cin>>mapMatrix[i];
        visited[i] = 0;
    }

    cout<<countRooms(mapMatrix, visited);

    delete [] mapMatrix;
    delete [] visited;
    return 0;
}
