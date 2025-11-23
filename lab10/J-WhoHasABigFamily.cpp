/*
Given a graph without cycles or self loops. In any connected component of the graph, vertex with the lowest value in that component serves as the root. A vertex is BigFam if it is a root or it has more children than its parent. Count the number of BigFam vertices in the given graph.

Input format
On the first line there are two separated integers N and M (1 <= N, M <= 10^5) and the following M lines consist of two separated integers X and Y meaning that there is an edge between vertices X and Y.

Output format
Print the number of BigFam vertices.

Examples
Input
4 3
1 2
2 3
2 4
Output
2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> visited(n + 1, 0);
    int bigFamCount = 0;

    for (int start = 1; start <= n; start++) {
        if (visited[start]) continue;


        vector<int> comp;
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        comp.push_back(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (!visited[to]) {
                    visited[to] = 1;
                    q.push(to);
                    comp.push_back(to);
                }
            }
        }

        // find the root = smallest vertex
        int root = *min_element(comp.begin(), comp.end());


        vector<int> parent(n + 1, -1);
        vector<int> children(n + 1, 0);
        queue<int> bfs;

        bfs.push(root);
        parent[root] = 0; 

        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            for (int to : g[v]) {
                if (parent[to] == -1) {
                    parent[to] = v;
                    children[v]++;
                    bfs.push(to);
                }
            }
        }


        for (int v : comp) {
            if (v == root) {
                bigFamCount++;
            } else {
                if (children[v] > children[parent[v]]) {
                    bigFamCount++;
                }
            }
        }
    }

    cout << bigFamCount;
    return 0;
}