/*
Given a map as 2d char array of ‘1’s (land) and ‘0’s (water). Your task to compute the number of islands. An island is set of land cells that are surrounded by water, such that from any cell you can reach any other cell in the islland moving only horizontally or vertically to adjacent cells. You may assume that area outside a map is a water.

Input format
In the first line given n and m, size of array (1 <= n, m <= 100) In the next n line contain m character ‘0’ or ‘1’.

Output format
Single number - the number of islands.

Examples
Input
4 5
11110
11010
11000
00000
Output
1
Input
4 5
11000
11000
00100
00011
Output
3
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                islands++;
                dfs(i, j);
            }
        }
    }

    cout << islands;
}