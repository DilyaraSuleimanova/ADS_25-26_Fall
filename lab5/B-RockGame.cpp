/*
We have a collection of rocks, each rock has a positive integer weight.
With each turn, we choose the two heaviest rocks and smash them together. Suppose the stones have weights x and y with x<=y. If x=y, both stones are totally destroyed. If x!=y, the stone of weight x is totally destroyed, and the stone of weight y has a new weight y-x.
At the end, there is at most 1 stone left. Output the weight of this stone (or 0 if there are no stones left).

Input format
The first line contains integer N (1<=N<=10^5) - the number of stones.
The second line contains N integers a_i (1<=a_i<=10^9) - the weights of each stone.

Output format
Print the weight of the remaining stone, or 0 if no one left.

Examples
Input
6
2 7 4 1 8 1
Output
1

Notes
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then, we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then, we combine 2 and 1 to get 1 so the array converts to [1,1,1] then, we combine 1 and 1 to get 0 so the array converts to [1] then that’s the value of last stone.
*/


#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class MaxHeap {
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

    int size() {
        return heap.size();
    }

private:
    void HeapifyUp(int i) {
        while (i > 0) {
            int parentIdx = this -> parent(i);

            if(heap[i] > heap[parentIdx]) {
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
            int largest = i;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else {
                break;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    MaxHeap h;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.push(x);        
    }

    while (h.size() > 1) {
        int first = h.pop();
        int second = h.pop();
        int left = first - second;
        
        if (left != 0) {
            h.push(left);
        }
    }

    if (h.size() == 0) {
        cout << 0;
    }
    else {
        cout << h.heap[0];
    }
    
}