/*
You are given N integers, that form a binary search tree by inserting them in the given order. You draw a set of horizontal lines that goes through nodes with the same height (level, depth). After that you can see triangles with nodes instead vertices and edges instead sides. Your task is to calculate the number of the smallest triangles.

Input format
The first line consists of an integer N - number of nodes in Binary Search Tree (1 <= N <= 10000).
The second line contains N integers a_i - value of each node in Binary Search Tree in order of their insertion (1 <= a_i <= N).
It is guaranteed that there are no duplicates.

Output format
Print the number of mini-triangles in resulting Binary Search Tree.

Examples
Input
3
3 5 1

Output
1
*/


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};


Node* insert_node(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    
    if (data < root -> data) {
        root -> left = insert_node(root -> left, data);
    }
    else if (data > root -> data) {
        root -> right = insert_node(root -> right, data);
    }

    return root;
}

int cnt_triangle(Node* root) {
    
    if (!root){
        return 0;
    }
        
    int cnt = 0;

    if (root -> left && root -> right) {
        cnt++;
    }

    return cnt + cnt_triangle(root -> left) + cnt_triangle(root -> right);

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

    cout << cnt_triangle(root);
}