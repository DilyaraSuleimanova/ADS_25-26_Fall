/*
Nurdana loves cookies! She stores all the cookies in separate boxes, but mom allows her to store only k boxes. Her dad is an assistant in this matter. He gives her a box in which there are n cookies. Help her calculate how many cookies she can have?

Input format
The first line contains two integers q and k (1 <= q,k <= 10^5). Each of the following q lines contains one command.
There are two types of commands:
insert n - dad gives a box with n cookies (0 <= n <= 10^9)
print - print the maximum number of cookies Nurdana can have

Output format
For each query of type print print the maximum sum of cookies if consider no more than k boxes.

Examples
Input
6 4
print
insert 9
insert 6
print
insert 10
print

Output
0
15
25

Notes
This problem must be solved using a heap.
Use long long type for the sum of elements.
Since k is fixed, you don’t need to store all numbers, only k largest elements.
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
    int n, k;
    cin >> n >> k;
    
    MinHeap h;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s == "insert") {
            int x;
            cin >> x;
            
            if (h.heap.size() < k) {
                h.push(x);
                sum += x;
            }
            else if (x > h.top()) {
                sum -= h.pop();
                h.push(x);
                sum += x;
            }
        }
        else if (s == "print") {
            cout << sum; 

            cout << endl;

        }
    }
}