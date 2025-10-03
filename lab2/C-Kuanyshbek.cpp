/*Solve this problem with linked list.

Kuanyshbek studied how multithreading works in operating systems. He wrote code that runs a single thread, which writes to a single file. Due to sloppiness, he launched two threads with different parameters that write to the same file. Since the OS allows only one thread to write data to a file in a single time, they worked synchronously. Kuanyshbek needs data from the first stream, help him delete the data of the second stream. To understand the whole situation you need to simulate the recording process. Implement your linked list, add items, and delete each second element. Kuanyshbek believes in you, good luck!*/

#include<iostream>

using namespace std;


class Node {
    public:
    int val;
    Node* next;

    Node(int newVal) {
        val = newVal;
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int newVal) {
        Node* newNode = new Node(newVal);

        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail -> next = newNode;
            tail = tail -> next;
        }
    }

    void print() {
        Node* temp = head;

        while(temp) {
            cout << temp -> val << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

};

int main() {
    int n;
    cin >> n;

    LinkedList arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i % 2 == 0) {
            arr.append(num);
        }
    }
    
    arr.print();
}