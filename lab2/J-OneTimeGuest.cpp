/*Jojo given an input stream of N characters consisting only of lowercase latin letters. After each input character, output first (or leftmost) non-repeating characher The task is to find the first (or leftmost) non-repeating character each time a character is inserted to the stream. If no non-repeating element occur, then print -1. Help Jojo to solve this problem.

Input format
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream. Constraints: <= T <= 200 <= N <= 500

Output format
For each test case in a new line print the first non repeating element for each new character added to stream, separated by the spaces. If no such element occur print -1.



Examples
Input
2
4
a a b c
3
a a c

Output
a -1 b b 
a -1 c 
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector <int> freq(26, 0);
        queue <char> guests;

        
        for (int i = 0; i < n; ++i) {
            char guest;
            cin >> guest;

            freq[guest - 'a']++;
            guests.push(guest);

            while (!guests.empty() && freq[guests.front() - 'a'] > 1) {
                guests.pop();
            }
            
            if (!guests.empty()) {
                cout << guests.front() << " ";
            } else {
                cout << -1 << " ";
            }
            
        }
        
        cout << endl;
    }

}


/*
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        queue <string> one_time;
        
        for (int i = 0; i < n; ++i) {
            string guest;
            cin >> guest;

            if (one_time.empty()) {
                one_time.push(guest);
            }
            else if (one_time.back() == guest) {
                one_time.push("-1");
            }
            else  if (one_time.back() != "-1") {
                one_time.push(one_time.back());
            }
            else {
                one_time.push(guest);
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << one_time.back() << " ";
            one_time.pop();
        }
        
    }

}
*/