/*
The ICPC finals will be held soon, so Yergeldi and his team needs your help. While they were preparing for the competition, they faced an interesting task. You have a list of length N which consists of arrays of different lengths. You have one single operation, you can take any two arrays and merge them into one, the cost of the operation is equal to the sum of their lengths. As a result, you will have a list of N - 1 arrays. The process repeats until there is only one final array left. Find out for what minimum cost it is possible to combine all arrays. 

Input format 
The first line contains an integer n ( 1<=n<=2*10^5), the size of the list a. The next line contains positive integers n, a_1,a_2 ...,a_n (1<=a_i<=2*10^5), representing the sizes of arrays in the list a. 

Output format 
Print a single integer - the minimum cost of operations.

Input
4
6 5 3 9
Output
45

Notes
Explanation for the first test case:
[6, 5, 3, 9] –> First, merge arrays of lengths 5 and 3 that will cost 8.
[6, 8, 9] –> Next, merge arrys of lengths 6 and 8 that will cost 14.
[14, 9] –> Finally, merge the remaining two arrays that will cost 23.
Therefore, the total cost for merging all arrays is 8 + 14 + 23 = 45.
*/


#include <iostream>
#include <vector>

using namespace std;

void swap(long long& a, long long& b) {
    long long temp = a;
    a = b;
    b = temp;
}

class MinHeap {
public:
    vector <long long> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void push(long long x) {
        // for (int v : heap) {
        //     if (v == x) return;  
        // }

        heap.push_back(x);
        HeapifyUp(heap.size() - 1);
    }

    long long pop() {
        if (heap.empty()) {
            return -1;
        }

        long long top = heap[0];
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
    int n;
    cin >> n;
    
    MinHeap heap;
    for (int i = 0; i < n; ++i) {
        long long el;
        cin >> el;
        heap.push(el);
        
    }

    long long minCost = 0;

    
    while (heap.size() != 1) {
        long long first = heap.pop();
        long long second = heap.pop();

        long long merged = first + second;
        minCost += merged;
        heap.push(merged);

        // cout << "first = " << first << " second = " << second << " merged = " << merged << " total = " << minCost << endl;
    }

    cout << minCost << endl;
}