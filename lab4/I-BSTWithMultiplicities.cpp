/*
You are given implementation of Binary Search Tree. You need to introduce new feature to the Binary Search Tree. It must be able to contain not only nodes with unique keys, but the number of copies of that key as well.
You are given several queries, each of them is of one the type:

‘insert X’ - insert X into the tree, if it already in a tree - increase its multiplicity,
‘delete X’ - decrease multiplicity of X by one, if it became zero - delete the node from the tree,
‘cnt X’ - output the multiplicity of X.

To complete the task you need to download solution code from https://bit.ly/3kWufJa and make some extra changes in it. Remaining code was written for you.

Input format
The first line contains single integer Q - number of queries (1 <= Q <= 1000). Each of the next Q lines contains one query.

Output format
Print answer on each query of type ‘cnt X’ in separate line.

Examples
Input
4
insert 1
cnt 1
insert 1
cnt 1

Output
1
2


Input
8
insert 1
cnt 1
insert 1
cnt 1
delete 1
cnt 1
delete 1
cnt 1

Output
1
2
1
0
*/

#include <iostream>

using namespace std;

struct Node {
	int data;
    int cnt;
	Node* left;
	Node* right;

	Node(int data) {
		this -> data = data;
        this -> cnt = 1;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {

	while (root -> left != NULL) {
		root = root -> left;
	}

	return root;
}

Node* add(Node* root, int data) {

	if (root == NULL) {
		return new Node(data);

	}
    
    else if (root -> data > data) {
		if (root -> left == NULL) {
			root -> left = new Node(data);
            
		} 
        else {
			root -> left = add(root -> left, data);
		}
	} 
    
    else if (root -> data < data) {
		if (root -> right == NULL) {
			root -> right = new Node(data);
		} 
        else {
			root -> right = add(root -> right, data);
		}
	}

    else {
        root -> cnt++;
    }

	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} 
    else if (root -> data > data) {
		root -> left = deleteNode(root -> left, data);
		return root;
	} 
    else if (root -> data < data) {
		root -> right = deleteNode(root -> right, data);
		return root;
	} 
    else {
        if (root -> cnt > 1) {
            root -> cnt--;
            return root;
        }

		if (root -> left == NULL && root -> right == NULL) {
			delete root;
			return NULL;
		} 

        else if (root -> right == NULL) {
			Node* temp = root -> left;
			delete root;
			return temp;
		} 

        else if (root -> left == NULL) {
			Node* temp = root -> right;
			delete root;
			return temp;
		} 
        
        else {
			Node* temp = getMin(root -> right);
			root -> data = temp -> data;
            root -> cnt = temp -> cnt;
            temp -> cnt = 1;
			root -> right = deleteNode(root -> right, temp -> data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} 
    else if (root -> data == x) {
		return root;
	} 
    else if (root -> data < x) {
		return find(root -> right, x);
	} 
    else {
		return find(root -> left, x);
	}
}

int main() {
    int q;
    cin >> q;

    Node* root = nullptr;
    while (q--) {
        string s;
        int x; 
        cin >> s >> x;

        if (s == "insert") {
            root = add(root, x);
        }
        else if (s == "delete"){
            root = deleteNode(root, x);
        }
        else if (s == "cnt") {
            Node* node = find(root, x);
            if (node) {
                cout << node -> cnt << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
}