/*
In an undirected graph, you need to find the shortest path between two vertices.

Input format
In the first line given one number n, number of vertices (1 <= n <= 100). In n lines given, and n elements in each line ‘0’ or ‘1’ where 0 indicates the absence of an edge, 1 indicates the presence of an edge. In the next line two numbers are given: start and end of a path.

Output format
Print the length of the shortest path. If the path does not exist, print a single number -1.

Examples
Input
5
0 1 0 0 1
1 0 1 0 0
0 1 0 0 0
0 0 0 0 0
1 0 0 0 0
3 5
Output
3
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int start, finish;
    cin >> start >> finish;

    
    start--;
    finish--;

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; u++) {
            if (g[v][u] == 1 && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    cout << dist[finish] << endl;

    return 0;
}