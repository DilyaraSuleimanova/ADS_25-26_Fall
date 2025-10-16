/*
Kakyoin loves football and he goes to the final of the World Cup. At the stadium, he noticed that there are n rows, each can accommodate a distinct number of people. The price of the ticket depends on the row. If there are k (k > 0) free seats in the row, then the price of one ticket will be equal to k. What is the maximum amount of money stadium management can get if there are x people in line for a ticket?

Input format
The first line consists of n and x (1 <= n, x <= 10^5). n denotes the number of seating rows in the stadium and x denotes the number of football fans waiting in line to get a ticket for the match.
Next line consists of n space separated integers a_1, a_2, a_3, ... , a_n where ai (1 <= a_i <= 10^5) denotes the number of empty seats initially in the i-th row.
It is guaranteed that there are enough free seats for all visitors.

Output format
Print one integer - the maximum amount of money the stadium can earn.

Examples
Input
3 10
6 8 9
Output
67

Input
1 2
5
Output
9
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
    int n, x;
    cin >> n >> x;
    
    MaxHeap h;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        h.push(a);        
    }

    long long sum = 0;

    while (x--) {
        int top = h.pop();
        sum += top;
        // cout << top << " "; 

        top--;
        h.push(top);
    }
    // cout << endl;
    cout << sum;
}