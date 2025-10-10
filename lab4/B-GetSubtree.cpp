/*
You are given Binary Search Tree. Your task is to calculate the size of the subtree of the node X.
Remember, that the subtree of node X is the set of all nodes whose ancestor is node X, including it. The size of the subtree is the size of such set.

Input format
The first line of the input contains an integer X - number of nodes in Binary Search Tree (1 <= X <= 1000).
The second line contains N integers a_i - values of nodes in order of insertion to the Binary Search Tree.
The third line contains single integer - value of the node which subtree’s size you must calculate.

Output format
Print the size of the subtree of the given node.

Examples
Input
7
4 2 6 1 3 5 7
4

Output
7
*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
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


Node* find_root(Node* root, int need_root) {
    if (!root){
        return nullptr;
    }
    
    if (root -> data == need_root) {
        return root;
    }
    else if (root -> data > need_root) {
        return find_root(root -> left, need_root);
    }
    else {
        return find_root(root -> right, need_root);
    }
    
}

int sub_root_size(Node* root) {
    if (!root) return 0;
    return 1 + sub_root_size(root -> left) + sub_root_size(root -> right);
}


int main() {
    int n, need_root;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int child;
        cin >> child;
        root = insertNode(root, child);
    }

    cin >> need_root;

    Node* sub_root = nullptr;
    sub_root = find_root(root, need_root);

    if (!sub_root) {
        cout << 0;
    } 
    else {
        cout << sub_root_size(sub_root);
    }

}