/*
You are given a permutation of size n. Create an empty BST, and insert into BST values p_1, p_2, ..., p_n in this order. You need to find how many levels are there and sum the of values for each level.

Input format
In the first line there is a single integer 1 <= n <= 5000 size of permutation. Second line contains n distinct numbers from 1 to n - the permutation.

Output format
In first line output k - maximum level in bst. In second line output k integers - sum of values for each level.

Examples
Input
5
4 3 5 1 2

Output
4
4 8 1 2 

There are 4 levels, and sum for each level is 4, 3 + 5, 1, 2.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int data) {
    if (root == nullptr) { 
        return new Node(data);
    }

    if (data < root -> data) {
        root -> left = insertNode(root -> left, data);
    }
    else if (data > root -> data) {
        root -> right = insertNode(root -> right, data);
    }

    return root;
}

int max_level(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + max(max_level(root -> left), max_level(root -> right));
}


vector<long long> level_values(Node* root) {
    vector<long long> sums;
    if (!root) return sums;

    queue <Node*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        long long level_sum = 0;

        for (int i = 0; i < size; i++) {
            Node* node = que.front(); 
            que.pop();
            level_sum += node -> data;

            if (node -> left) {
                que.push(node -> left);
            }
            if (node -> right) {
                que.push(node -> right);
            }
        }

        sums.push_back(level_sum);
    }

    return sums;
}

int main() {

    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        root = insertNode(root, p);
    }
    
    int levels = max_level(root);
    cout << levels << endl;

    vector <long long> lvl_sums = level_values(root);

    for (long long sum: lvl_sums) {
        cout << sum << " ";
    }
}