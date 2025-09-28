/*You are in a casino, the croupier offers you to play. You started playing and there is given a sorted deck of cards numbered 1 to N. He shows you a trick:
 We pick up 1 card and put it on the back of the deck.
 Now, we pick up another card, it turns out to be card numbered 1, we put it outside the deck.
 Now we pick up 2 cards and put it on the back of the deck one by one.
 Now, we pick up another card and it turns out to be card numbered 2, we put it outside of the deck.
 ...
 We perform this steps till the last card.

Note, that at some step i the number of cards in the deck can be less than i, in this case some cards can processed several times, see notes. You are questioned if you can repeat that trick. Output initial arrangement of the deck if possible, or say if it is impossible.*/


#include <iostream>
#include <deque>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t != 0) {
        int n;
        cin >> n;

        deque <int> d;
        for (int i = n; i >= 1; i--) {
            d.push_front(i);

            for (int j = 0; j < i; j++) {
                if(d.empty()) break;

                d.push_front(d.back());
                d.pop_back();
            }
        }

        for (int i = 0; i < d.size(); i++){
            cout << d[i] << " ";
        }
        cout << endl;

        t--;
    }
    
}








// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     // ios::sync_with_stdio(false);
//     // cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         deque<int> dq;

//         // Build the deck backwards
//         for (int i = n; i >= 1; --i) {
//             // Put card i on top
//             dq.push_front(i);

//             // Move i cards from bottom to top
//             for (int j = 0; j < i; ++j) {
//                 dq.push_front(dq.back());
//                 dq.pop_back();
//             }
//         }

//         // Output the reconstructed deck
//         for (int i = 0; i < n; i++) {
//             cout << dq[i] << (i + 1 == n ? '\n' : ' ');
//         }
//     }

//     return 0;
// }
