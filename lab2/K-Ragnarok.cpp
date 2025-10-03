/*You are given an array a (-1000 <= a_i <= 1000) of length n (1 <= n <= 100) in linked list form. Find non-empty subarray of n (range of consequent elements) of maximal sum.

    NOTES
Take one of the templates from links given below and implement the function findMaxSum().
C++: https://ideone.com/j1t24c
Python3: https://ideone.com/g4kkKm
You can’t convert linked list to array, doing this will result in 0 points.
*/

# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};

int findMaxSum(int n, Node *head) {
	int current_sum = head -> val;
    int max_sum = head -> val;

    Node *cur = head -> next;
    while (cur != NULL) {
        
        current_sum = max(cur -> val, current_sum + cur -> val);
        max_sum = max(max_sum, current_sum);
        cur = cur -> next;
    }

    return max_sum;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
