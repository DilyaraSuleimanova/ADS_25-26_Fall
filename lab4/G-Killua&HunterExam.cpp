/*
While Gon is surviving on the Greed Island, Killua, after the first unsuccessful attempt to pass the hunter exam, decides to test himself again. This time one of his tasks is to find the maximum distance between any two vertices in a binary search tree. Since Killua is pretty bad at algorithms, he asks for your help.

Input format
In the first line you will be given single number N (1 <= N <= 200000). Next line consists of N numbers, where a_i (1 <= a_i <= 10^9) represents the i-th number inserted to a binary search tree. If a_i was found in a tree, then you don’t have to insert it again.

Output format
Print one single number - the maximum distance between any two vertices in a binary tree.

Examples
Input
9
11 5 3 2 1 7 9 8 13

Output
7

Notes
In the first test, the answer is the distance between nodes 1 and 8.
*/

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int x): val(x), left(nullptr), right(nullptr) {}
};

Node* insert_node(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (root -> val > val) {
        root -> left = insert_node(root -> left, val);
    }
    else if (root -> val < val){
        root -> right = insert_node(root -> right, val);
    }

    return root;
}

int max_dis = 0;

int dis(Node* root) {
    if (!root) {
        return 0;
    }

    int left_h = dis(root -> left);
    int right_h = dis(root  ->right);

    max_dis = max(max_dis, left_h + right_h);

    return 1 + max(left_h, right_h);
}


int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int child;
        cin >> child;
        root = insert_node(root, child);
    }

    dis(root);

    cout << max_dis + 1;

}