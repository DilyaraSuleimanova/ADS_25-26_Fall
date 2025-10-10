/*
Christmas is coming! Everyone is preparing gifts for their families. The Damir’s family is also preparing for this. The Damir’s family has many children, so the parents decided to buy n various gifts. Parents decided to number these gifts - i-th as a_i. They hang them on Christmas tree in socks, following the form binary search tree. In particular, they insert i-th gift with the value a_i following the rules of binary search tree.
As you know, Damir is the smallest among the whole family. Therefore, parents for the holiday allowed him to pick up his gift first. Damir knew that his gift has number k, but he mistakenly assumed that all the gifts below his gift were also intended for him. Now, parents are confused and want to find out what gifts Damir wants to grab for himself.

Input format
The first line contains one integers n (1 <= n <= 1000) - the number of gifts. The second line contains n integers a_i (1 <= a_i <= 1000). The third line contains one integer k (1 <= k 1000). It is guaranteed that the array has the number k.

Output format
You should output this subtree in pre-order (root, left subtree, right subtree).

Examples
Input
5
4 2 7 1 3
2

Output
2 1 3 
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

void pre_order(Node* root) {
    if (root != nullptr) {
        cout << root -> data << " ";
        pre_order(root -> left);
        pre_order(root -> right);
    }
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

    pre_order(sub_root);

}