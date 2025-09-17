/*You are given a string S containing lowercase Latin letters [a-z]. Determine if string is balanced.
Here is description of balanced strings:
 - empty string is balanced
 - if strings s and t are balanced, then string st (concatenation) is also balanced
 - if string s is balanced, then string xsx is balanced for any lowercase Latin letter x.

For example, string abba is balanced, but string abbb is not.*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack <char> st;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (!st.empty() && st.top() == ch) {
            st.pop();
        } else {
            st.push(ch);
        }
    }

    if (st.empty())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}