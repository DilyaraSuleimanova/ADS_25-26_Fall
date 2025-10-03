/*In this problem you need to complete the template https://paste.ubuntu.com/p/hMJK6v55br/
Implement the doubly linked list data structure. The program reads a sequence of command, performs one or another operation. The linked list stores the names of books.
Possible commands for the program:
 add - front Add a new book to the beginning of the linked list. The program should output "ok"
 add_back - Add a new book to the end of linked list. The program should output "ok"
 erase_front - Erase the first book in the linked list. The program should output name of erased book
 erase back - Erase the last book in the linked list. The program should output name of erased book
 front - Print the name of the first book.
 back - Print the name of the last book
 clear - Erase the all books in the linked list. The program should output "ok"
 exit - The program should output "goodbye" and exit
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string s) {
        data = s;
        prev = NULL;
        next = NULL;
    }
};

struct DoublyList {
    Node* head;
    Node* tail;
    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void add_front(string s) {
        Node* node = new Node(s);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        cout << "ok" << endl;
    }

    void add_back(string s) {
        Node* node = new Node(s);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        cout << "ok" << endl;
    }

    void erase_front() {
        if (!head) {
            cout << "error" << endl;
            return;
        }
        cout << head->data << endl;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }

    void erase_back() {
        if (!tail) {
            cout << "error" << endl;
            return;
        }
        cout << tail->data << endl;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete temp;
    }

    void front() {
        if (!head) cout << "error" << endl;
        else cout << head->data << endl;
    }

    void back() {
        if (!tail) cout << "error" << endl;
        else cout << tail->data << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        cout << "ok" << endl;
    }
};

int main() {
    DoublyList list;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "add_front") {
            string book;
            cin >> book;
            list.add_front(book);
        } else if (cmd == "add_back") {
            string book;
            cin >> book;
            list.add_back(book);
        } else if (cmd == "erase_front") {
            list.erase_front();
        } else if (cmd == "erase_back") {
            list.erase_back();
        } else if (cmd == "front") {
            list.front();
        } else if (cmd == "back") {
            list.back();
        } else if (cmd == "clear") {
            list.clear();
        } else if (cmd == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}