/*
Here is the field, where each cell can have one of three values:
"0" - an empty cell;
"1" - a cell with the brown mushroom;
"2" - a cell with Mario.
Every minute, Mario crushes any brown mushroom that is adjacent to his position (up, down, top, bottom) and new Mario appears instead of mushroom, Mario does not move to the empty cell.
How many minutes will it take for Mario to kill all brown mushrooms in each cell? The number of Marios can be more than one. If this is impossible, return -1.

Input format
The first line contains two integers, m - number of rows of a field, n - number of columns of a field (1 <= m,n <= 1000). The following m lines contain n values (0, 1, or 2).

Output format
Print the minimum time (in minutes) that must elapse until no cell will contain a brown mushroom. If any mushroom is unreachable for every Mario in a field print -1.

Examples
Input
3 3
2 1 1
1 1 0
0 1 1
Output
4

Notes
The picture illustrates the procedure of the first example.

In the second example, the mushroom at (3, 1) is unreachable, because Mario can move 4-directionally. So, the output is -1.

In the last example, there are no brown mushrooms, there is nothing to kill, so the answer is 0.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<int>> grid(m, vector<int>(n));
    queue<pair<int,int>> q;
    int mushrooms = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j}); 
            } else if (grid[i][j] == 1) {
                ++mushrooms;
            }
        }
    }

    if (mushrooms == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int minutes = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};


    while (!q.empty()) {
        int levelSize = q.size();
        bool convertedThisLevel = false;
        for (int k = 0; k < levelSize; ++k) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                   
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    --mushrooms;
                    convertedThisLevel = true;
                }
            }
        }
        if (convertedThisLevel) ++minutes;
    }

    if (mushrooms == 0) cout << minutes << '\n';
    else cout << -1 << '\n';

    return 0;
}