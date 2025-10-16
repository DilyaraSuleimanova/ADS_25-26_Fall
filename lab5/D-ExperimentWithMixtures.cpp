/*
Mark is making an experiment with mixtures of different densities. For his experiment he wants all of the mixtures to have a density >= m.
He uses the following formula to obtain a combined mixture: d_new = d_least + 2 * d_secondleast, where d_new is the density of the new mixture, d_least is the smallest density among all mixtures and d_secondleast is the second smallest density among all mixtures.
Mark repeats the mixing until he gets all the mixtures with the density >= m.
You are given the densities of mixtures. How many times Mark should mix his mixtures to get the densities of all mixtures >= m?

Input format
The first line consists of integers n and m (1 <= n <= 10^6, 0 <= m <= 10^9), the number of mixtures and the minimum required density correspondingly.
The next line contains n space-separated integers d_i (0 <= d_i <= 10^6) describing the densities of mixtures.

Output format
Print the number of operations that are needed to make all the densities >= m. If it is impossible, print - 1.

Examples
Input
3 10
1 1 1
Output
-1

Input
6 7
1 2 3 9 10 12
Output
2
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class MinHeap {
public:
    vector <int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void push(int x) {
        heap.push_back(x);
        HeapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            return -1;
        }

        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        HeapifyDown(0);
        return top;
    }

    int top() {
        if (heap.empty()) {
            return -1;
        }

        return heap[0];
    }

    int size() {
        return heap.size();
    }

private:
    void HeapifyUp(int i) {
        while (i > 0) {
            int parentIdx = this -> parent(i);

            if(heap[i] < heap[parentIdx]) {
                swap(heap[i], heap[parentIdx]);
                i = parentIdx;
            }

            else {
                break;
            }
        }
    }


    void HeapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < n && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else {
                break;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    MinHeap h;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.push(x);        
    }

     while (h.size() > 1 && h.top() < m) {
        int first = h.pop();
        int second = h.pop();

        int d_new = first + 2 * second;
        h.push(d_new);
        
        cnt++;
    }

    if (h.top() >= m) {
        cout << cnt;
    }

    else {
        cout << -1;
    }
}