/*
You are going to hike in the mountains. You have written directions (left or right) on a piece of paper, in which direction you need to turn on each of the branches of the path, following which you can reach the peak. In the mountains there are several peaks and you have recorded the path to each peak. Since you are a guide, you need to check the day before the hike which of the recorded paths is available. All paths start at one point at the foothills.

The path is presented in the form of "RRLLRLR", which means to reach the peak you need to turn right at the beginning, then right again, then left, left, right, left, right. Peak located after last turn and it is possible that it does not exist. You are given all the paths in the mountains that are available in the form of a Binary Search Tree and the paths to the peaks that are written on a piece of paper. You need to tell which of the paths written on the piece of paper is available.

Input format
Given the number N, M (1 <= N, M <= 10^5)-the number of branches in the available path in the mountains and the number of paths written on a piece of paper. In the next line N integers describe the BST. The following M lines describe the paths p1, p2, p3 ... pm (2 <= |p_i| <= 100) written on a piece of paper.
Output format
You need to print M lines where i-th line should be "YES" if the path p_i-th, to the peak is available, otherwise "NO".

Examples
Input
9 4
7 10 12 8 5 6 2 1 4
LLL
LRR
RL
RR

Output
YES
NO
YES
YES
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
    else if (data > root->data) {
        root -> right = insertNode(root -> right, data);
    }

    return root;
}


bool checkPath(Node* root, const string& path) {
    Node* cur = root;

    for (char c : path) {
        if (!cur) return false;
        if (c == 'L') cur = cur->left;
        else cur = cur->right;
    }

    return cur != nullptr;
}


int main() {
    int n, m;
    cin >> n >> m;

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int child;
        cin >> child;
        root = insertNode(root, child);
    }

    while (m--) {
        string path;
        cin >> path;

        if (checkPath(root, path)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }

}
