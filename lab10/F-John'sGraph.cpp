/*
Mom gave John an undirected graph for his birthday. After some time, he came up with a game with a graph. He takes two vertices and checks to see if they are in the same component.

Input format
The first line contains two integers n and m (2 <= n <= 100000, 0 <= m <= 99999), where n is the number of vertices and m is the number of edges. Following m lines contain one edge each in form x, y (1 <= x, y <= n), where x, y are edge endpoints. The last line contains two integers s and f (1 <= s, f <= n), vertices you have to check.

Output format
Print "YES", if s and f vertices are in the same component, otherwise print "NO".

Examples
Input
3 3
1 2
2 3
3 1

1 3
Output
YES
*/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]); 
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }

    int s, f;
    cin >> s >> f;

    cout << (dsu.find(s) == dsu.find(f) ? "YES" : "NO");

    return 0;
}