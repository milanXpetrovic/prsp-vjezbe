#include <bits/stdc++.h>
using namespace std;

vector<string> graph(1000);
vector<vector<char>> steps(1000, vector<char>(1000));
bool visited[1000][1000];
pair<int, int> start, dest;
stack<char> ans;
int n, m;


bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != '#' && visited[x][y] == false);
}

void backtrack(int x, int y)
{
    if (steps[x][y] != 'X')
    {
        char ch = steps[x][y];
        ans.push(ch);
        if (ch == 'U')
            backtrack(x + 1, y);
        else if (ch == 'D')
            backtrack(x - 1, y);
        else if (ch == 'L')
            backtrack(x, y + 1);
        else if (ch == 'R')
            backtrack(x, y - 1);
    }
}


void bfs(int x, int y){
    steps[x][y] = 'X';
    bool flag = false;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()){
        pair<int, int> ele = q.front();
        x = ele.first;
        y = ele.second;
        q.pop();
        if (graph[x][y] == 'B'){
            flag = true;
            break;
        }
        visited[x][y] = true;
        if (is_valid(x - 1, y)){
            visited[x - 1][y] = true;
            steps[x - 1][y] = 'U';
            q.push({x - 1, y});
        }
        if (is_valid(x, y + 1)){
            visited[x][y + 1] = true;
            steps[x][y + 1] = 'R';
            q.push({x, y + 1});
        }
        if (is_valid(x + 1, y)){
            visited[x + 1][y] = true;
            steps[x + 1][y] = 'D';
            q.push({x + 1, y});
        }
        if (is_valid(x, y - 1)){
            visited[x][y - 1] = true;
            steps[x][y - 1] = 'L';
            q.push({x, y - 1});
        }
    }
    if (flag){
        cout<<"YES\n";
        backtrack(x, y);
        cout << ans.size() << endl;
        while (!ans.empty())
        {
            cout << ans.top();
            ans.pop();
        }
    }
    else
        cout<<"NO";
}
int main(){

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'A')
                start = {i, j};
            else if (graph[i][j] == 'B')
                dest = {i, j};
        }
    }
    bfs(start.first, start.second);

}
