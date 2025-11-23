/*
Arman works as a beta tester for a game development company. Today he is testing a game that has quests, and in order to win the game, the player needs to complete all the quests. However, some quests only become available after completing certain other quests. The developers give Arman a list of requirements, which indicates which quest must be completed in order to open the next one. Help Arman determine whether is it possible to complete this game, and if possible, output one of the scenarios for the passage.

Input format
The first line of input contains a pair of numbers n and m (1 <= n <= 10^5, 0 <= m <= 10^5), the number of quests and requirements, respectively. The next m lines contains a pair of integers i and j (1 <= i, j <= n), which means that in order to make quest j available, you must complete quest i.

Output format
Determine whether it is possible to complete the game, and output ‘Impossible’ if not, otherwise output ‘Possible’ and the scenario of the passage. If there are several of them, output any.

Examples
Input
5 5
1 2
2 3
1 3
4 5
3 4
Output
Possible
1 2 3 4 5 

Input
6 6
4 2
4 3
2 3
1 5
6 2
6 4
Output
Possible
1 5 6 4 2 3 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topo.push_back(v);

        for (int to : g[v]) {
            indeg[to]--;
            if (indeg[to] == 0)
                q.push(to);
        }
    }

    if ((int)topo.size() != n) {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible\n";
    for (int x : topo)
        cout << x << " ";
}