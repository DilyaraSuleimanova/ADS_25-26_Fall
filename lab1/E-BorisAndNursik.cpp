/*Boris and Nursik play a drunkard card game. In the drunkard card game, all cards are divided equally between two players. Then they reveal one top card, and the one whose card is higher takes both of the revealed cards for himself, which are put under the bottom of his deck. The one who is left without cards loses.

The player who takes the cards for himself first puts the Boris’s card under the bottom of his deck, then the Nursik’s card (that is, the Nursik’s card is at the bottom of the deck).

Write a program that simulates the drunkard card game and determines who wins. The game involves 10 cards with values from 0 to 9, the larger card wins the smaller one. The one special thing is that the card with a value of 0 wins card 9.*/


#include <iostream>
#include <queue>

using namespace std;

const size_t N = 100000;

class Queue{
    public:
        int a[N];
        int cnt = 0, beginning = 0;

        void push(int n){
            if (cnt < N){
                a[cnt] = n;
                cnt++;
            }
        }

        void pop(){
            if (cnt > beginning) {
                int result = a[beginning];
                a[beginning] = 0;
                beginning++;
            }
        }

        int front(){
            if (cnt > beginning) {
                int result = a[beginning];
                return result;
            }
            return -1;
        }

        bool empty() {
            if (cnt < N && cnt - beginning == 0) {
                return true;
            }
            return false;
        }


};

bool WhoWins(int b, int n) {
    
    if (b == 0 && n == 9) return true;  
    if (b == 9 && n == 0) return false;  
    return b > n; 
}

int main(){
    // queue<int> Boris, Nursik;
    Queue Boris, Nursik;

    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        Boris.push(num);
    }
    
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        Nursik.push(num);
    }
    
    int cnt = 0;
    int MAX_MOVES = 1000000;
    
    while (!Boris.empty() && !Nursik.empty()) {
        int B = Boris.front(), N = Nursik.front();
        
        Nursik.pop();
        Boris.pop();

        if (WhoWins(B, N)) {
            Boris.push(B);
            Boris.push(N);
        }
        else {
            Nursik.push(B);
            Nursik.push(N);
        }
        cnt++;
    }
    
    if (cnt >= MAX_MOVES) {
        cout << "blin nichya";
    } else if (Nursik.empty()) {
        cout << "Boris " << cnt;
    } else {
        cout << "Nursik " << cnt;
    }
    
}

