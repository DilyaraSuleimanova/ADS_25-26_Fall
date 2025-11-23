/*
You are given undirected graph with n vertices, m edges, and q queries. Initially all vertices are black. There are two types of queries.
1. 1 v - Change the color of vertex v to red.
2. 2 v - Output the distance to the nearest red vertex to v, or -1 is there is no such vertex.

Input format
First line contains three integers 1 ≤ n, m ≤ 5000, 1 ≤ q < 10^5. Next m lines contain information about edges. Next q lines contain queries as described in the statement.

Output format
Output answer to queries of type 2.

Examples
Input
5 4 7
1 2
2 3
3 4
4 5
2 1
1 1
2 1
2 2
2 5
1 3
2 5
Output
-1
0
1
4
2
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> distAll(n + 1, INF);
    vector<int> recentRed;
    vector<int> isRed(n + 1, 0);

    const int B = 70;  

    auto recompute = [&]() {
        queue<int> qq;
        fill(distAll.begin(), distAll.end(), INF);

        for (int v = 1; v <= n; v++) {
            if (isRed[v]) {
                distAll[v] = 0;
                qq.push(v);
            }
        }

        while (!qq.empty()) {
            int v = qq.front(); qq.pop();
            for (int u : g[v]) {
                if (distAll[u] > distAll[v] + 1) {
                    distAll[u] = distAll[v] + 1;
                    qq.push(u);
                }
            }
        }
        recentRed.clear();
    };

    while (q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            if (!isRed[v]) {
                isRed[v] = 1;
                recentRed.push_back(v);
                if ((int)recentRed.size() > B) {
                    recompute();
                }
            }
        } 
        else {
            int answer = distAll[v];

            
            if (!recentRed.empty()) {
                vector<int> dist(n + 1, INF);
                queue<int> qq;
                dist[v] = 0;
                qq.push(v);

                while (!qq.empty()) {
                    int x = qq.front(); qq.pop();

                    if (dist[x] >= answer) break;

                    if (isRed[x]) answer = min(answer, dist[x]);

                    for (int u : g[x]) {
                        if (dist[u] > dist[x] + 1) {
                            dist[u] = dist[x] + 1;
                            qq.push(u);
                        }
                    }
                }
            }

            if (answer == INF) answer = -1;
            cout << answer << "\n";
        }
    }
    return 0;
}