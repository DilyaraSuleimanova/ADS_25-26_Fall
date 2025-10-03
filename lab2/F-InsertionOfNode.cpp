/*You’re given a linked list A, an integer data to add to the list and the position at which the integer must be inserted. Create a new node with the given integer, insert this node at the desired position.

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on.

As an example, if your list starts as 1 -> 2 -> 3 and you want to insert a node at position 2 with data = 4, your new list should be 1 -> 2 -> 4 -> 3
*/

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

    void print(int data, int pos) {
        Node* temp = head;

        int i = 0;
        while(temp) {
            if (i == pos) {
                cout << data << " ";
            }
            else {
                cout << temp -> val << " ";
                temp = temp -> next;
            }
            i++;
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
        arr.append(num);
    }

    int data, pos;
    cin >> data >> pos;

    arr.print(data, pos);

}