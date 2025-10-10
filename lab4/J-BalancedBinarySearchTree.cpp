/*
You have an array with 2^N - 1 elements in it. You want to build the Binary Search Tree on this array, adding elements in order of their appearance in array (from left to right). But there is a probability that the tree would be imbalanced. That’s why you decided to shuffle your array to obtain perfectly balanced Binary Search Tree (i.e. BST with prefect binary tree underneath) after adding elements (from left to right, again). Your task is to print your array after appropriate shuffle. If there are several possible shuffles, print the array after applying any of them.
Note, that you are not asked for building Binary Search Tree, but only for shuffling array.

Input format
The first line of input consists of single integer N that describes the length of the array (1 <= N <= 15).
The next line contains 2^N - 1 integers a_i - elements of the array (0 <= a_i <= 2*10^9).
It is guaranteed that there are no duplicates in the array.

Output format
Print 2^N - 1 integers - elements in your array after applying required shuffle.

Examples
Input
2
3 5 1

Output
3 5 1

Notes
In the first sample given array can be used for building balanced BST (left picture).
In the second sample given array gives such chain tree (right picture), so it must be shuffled.
Note, that for both samples [3, 5, 1] and [3, 1, 5] are correct answers.
Hint: Use divide and conquer method (recall advanced sorting algorithms) and implement recursive function to solve this problem
*/


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void balanced(const vector<long long>& a, int l, int r, vector<long long>& out) {
    if (l > r) return;
    
    int mid = (l + r) / 2;

    out.push_back(a[mid]);                  
    balanced(a, l, mid - 1, out);     
    balanced(a, mid + 1, r, out);     
}

int main() {
    
    int n;  
    cin >> n;

    int size = pow(2, n) - 1;

    vector<long long> a(size);

    for (int i = 0; i < size; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> out;

    balanced(a, 0, size - 1, out);

    for (int i = 0; i < size; ++i) {
        cout << out[i] << ' ';
    }
    
}
