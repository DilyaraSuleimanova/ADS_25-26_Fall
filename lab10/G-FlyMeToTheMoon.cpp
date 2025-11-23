/*
Giving up halfway is worse than never trying at all

- Misato Katsuragi, Evangelion

I think you've all heard about Keqing and her love for solving puzzles. But it's time for you to find out about her friend Ganyu, who also loves to solve
various problems. Unlike Keqing, Ganyu likes graph problems more. This time she has a directed graph of n vertices and m edges. She is very interested
to know if she can turn her primordial graph into an acyclic graph. Moreover, she set herself an additional condition - she can delete only one edge from
the graph. Unfortunately, Ganyu has a lot to do at work, so she didn't have time to solve this problem. Therefore, she asked you to help her. Try your best
for this problem because she believes in you!

Input format
The first line contains n and m - the number of vertices and the number of edges. Then m lines follow. Each line contains two integers x and y
denoting a directed edge going from vertex x to vertex y. Each ordered pair (x, y) is listed at most once. However, loops for the vertex itself in the graph
are possible. (2<n ≤ 500, 1 <m ≤ min(n(n-1), 105)).

Output format
Print the answer. YES - if it is possible. NO - otherwise.

Examples
Input
5 6
1 3
2 1
3 5
4 3
5 4
3 2
Output
NO

Notes
Acyclic graph - each edge directed from one vertex to another, such that following those directions will never form a closed loop.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indeg0;

bool topo_with_remove_to(int remove) {
    vector<int> indeg = indeg0;

    if (remove != -1) {
        if (indeg[remove] != 0) {
            indeg[remove]--;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0)
            q.push(i);
    }

    int processed = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return (processed == n);
}

int main() {

    cin >> n >> m;
    adj.assign(n, {});
    indeg0.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        indeg0[v]++;
    }

    if (topo_with_remove_to(-1)) {
        cout << "YES";
        return 0;
    }

    for (int v = 0; v < n; ++v) {
        if (indeg0[v] == 0) continue;

        if (topo_with_remove_to(v)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}