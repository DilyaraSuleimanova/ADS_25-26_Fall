/*
Given a binary tree, write a program to get the width of the given tree.

The level of a node is the number of vertices on the path from this node to the root. The width of a level h is the number of vertices with level h. The width of a tree is the maximal width over the levels.
Vertex number 1 always will be root.

Input format
Given integer n — (1 <= |n| <= 1000), number of vertexes. The next n - 1 lines has 3 numbers x, y, z - description of binary tree, meaning that vertex y son of vertex x, if z = 0, it is left son, if z = 1 it is right son.

Output format
Print one integer maximum width.

Examples
Input
6
1 2 1
1 3 0
3 5 0
3 6 1
2 4 1

Output
3

Notes
Explanation: The maximum width existing in the third level with the length 3 (5,6,4).
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int left = -1;
    int right = -1;
};


int main() {
    int n;
    cin >> n;

    vector <Node> tree(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            tree[x].left = y;
        }
        else {
            tree[x].right = y;
        }
    }

    queue<int> que;
    que.push(1);

    int maxWidth = 0;

    while (!que.empty()) {
        int size = que.size(); 
        maxWidth = max(maxWidth, size);

        for (int i = 0; i < size; i++) {

            int node = que.front(); 
            que.pop();
            if (tree[node].left != -1) {
                que.push(tree[node].left);
            }
            if (tree[node].right != -1) {
                que.push(tree[node].right);
            }
        }
    }

    cout << maxWidth << endl;

}
/*
6
1 2 1
1 3 0
3 5 0
3 6 1
2 4 1

1
*/