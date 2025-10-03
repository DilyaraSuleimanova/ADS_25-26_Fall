/*THE CODE TEMPLATE IS IN THE NOTE BELOW.
Zoro got lost again, this time in the maze. Walking along a random corridor, he stumbles upon a mysterious door, which says that this is the exit from the maze. The door mechanism works on specific functions for the linked list. But due to the fact that the door is very old, the functions have been erased. Zoro discovered an ancient stone paneglyph nearby, which lists about each function:
 - inserts - add a node on position p.
 - remove - remove the node from position p.
 - print - print all values of list separated by a space.
 - replace - move the node from position p1 and to position p2. Position p2 is considered at the moment after its removal.
 - reverse - reverse the entire list.
 - cyclic_left - do a cyclic shift to the left x times.
 - cyclic_right - do a cyclic shift to the right x times.
Also, there are indicated the commands that need to be executed in order for the door to open. It is known that each command calls a specific function. Help Zoro to restore functions.

    Input format
Each line of input starts with integer which indicates command:

If command 0, exit the program.

If command 1, then the same line of input contains numbers x (1 <= x <= 10^6) and p (0 <= p). Add a new node with value x to the position p. It is guaranteed that p does not exceed the length of the list.

If command 2, then the same line of input contains number p (0 <= p). Delete the node from position p. It is guaranteed that p is less than the length of the list.

If command 3, print the whole list. Print -1 if list is empty.

If command 4, then the same line of input contains numbers p1 and p2 (0 <= p1, p2). Move node from position p1 to position p2. Position p2 is counted from the moment when we have already retrieved the node from position p1. It is guaranteed that p1 and p2 are less than the length of the list.

if command 5, reverse whole list.

If command 6, then the same line of input contains number x. Make left cyclic shift x (0 <= x) times. It is guaranteed that x is less than the length of the list.

If command 7, then the same line of input contains number x. Make right cyclic shift x (0 <= x) times. It is guaranteed that x is less than the length of the list.


    SUBTASK
(20%) Implement each function in O(N^2) or faster.
(20%) Implement functions inserts, remove, print and replace in O(N).
(20%) Implement functions inserts, remove, print and reverse in O(N).
(20%) Implement functions inserts, remove, print, cyclic_left and cyclic_right in O(N).

    NOTE
Each function except print must return the head of the linked list.
    CODE TEMPLETES
C++ : https://pastebin.com/BAG1n8Kp
Python : https://pastebin.com/9mwkZnEh
Java : https://pastebin.com/jfhpYWYR

Just leave it to luck
— Roronoa Zoro, One Piece
*/

#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    
    if(p == 0) {
        node -> next = head;
        return node;
        
    }

    Node* cur = head;

    for (int i = 0; i < p - 1 && cur; i++){
        cur = cur -> next;
    }

    if (cur) {
        node -> next = cur -> next;
        cur -> next = node;
        return head;
    }
}
 
Node* remove(Node* head, int p){

    if (!head) {
        return nullptr;
    }

    if (p == 0) {
        Node* removed = head;
        head = head -> next;
        delete removed;
    }
    
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; i++){
        cur = cur -> next;
    }
    
    if (cur -> next) {
        Node* removed = cur -> next;
        cur -> next = cur -> next -> next;
        delete removed;
    }

    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    
    if (!head || p1 == p2) {
        return head;
    }

    Node* prev1 = nullptr;
    Node* cur1 = head;

    for (int i = 0; i < p1; i++) {
        prev1 = cur1;
        cur1 = cur1 -> next;
    }

    if (prev1) {
        prev1 -> next = cur1 -> next;
    } 
    else {
        head = cur1 -> next; 
    }

    
    if (p2 == 0) {
        cur1 -> next = head;
        head = cur1;
    } 
    else {
        Node* prev2 = head;

        for (int i = 0; i < p2 - 1; i++) {
            prev2 = prev2 -> next;
        }

        cur1 -> next = prev2 -> next;
        prev2 -> next = cur1;
    } 

    return head;
}
 
Node* reverse(Node* head){
    
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nextVal = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nextVal;
    }

    return prev;
}
 
void print(Node* head){
    
    if (!head) {
        cout << -1 << endl;
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){

    if(!head) {
        return nullptr;
    }

    Node* cur = head;
    Node* endVal = head;
    while (endVal -> next) {
        endVal = endVal -> next;
    }
    
    while (x--) {
        head = cur -> next;
        endVal -> next = cur;
        cur -> next = nullptr;
        endVal = endVal -> next;
        cur = head;
    }

    return head;
}
 
Node* cyclic_right(Node* head, int x){

    if (!head) {
        return nullptr;
    }
    
    int len = 1;
    Node* tail = head;
    while (tail -> next) { 
        tail = tail -> next; 
        ++len;
    }
    x %= len;

    if (x == 0) {
        return head;
    }
    return cyclic_left(head, len - x);
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }
        else if(command == 1){
            int x, p; 
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2){
            int p; 
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3){
            print(head);
        }
        else if (command == 4){
            int p1, p2; 
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5){
            head = reverse(head);
        }
        else if (command == 6){
            int x; 
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7){
            int x; 
            cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}