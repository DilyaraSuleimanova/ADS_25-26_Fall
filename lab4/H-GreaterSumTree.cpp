/*
Given the root of a binary search tree with distinct keys. Replace the key of each node with the sum of the keys over the nodes that has greater than or equal key. Print new keys in increasing order.
As a reminder, a binary search tree is a tree that satisfies these constraints:
- The left subtree of a node contains only nodes with keys less than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- Both the left and right subtrees must also be binary search trees.

Input format
The number of nodes n in the tree is between 1 and 100. Each node will have value between 0 and 1000. The given tree is a binary search tree.

Output format
In a single line print the answer.

Examples
Input
9
4 1 6 0 2 3 5 7 8
Output
8 15 21 26 30 33 35 36 36
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

int sum = 0;
void inorder_sums(Node* root) {
    
    if (root != nullptr) {
        inorder_sums(root -> right);
        sum += root -> val;
        cout << sum << " ";
        inorder_sums(root -> left);
    }
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

    inorder_sums(root);
}