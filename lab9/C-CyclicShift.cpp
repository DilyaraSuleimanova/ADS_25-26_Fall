/*
Tamerlan once wrote on a piece of paper a line consisting of large and small Latin letters, and then went to help Askar. When he returned, he found that his friend Alikhan had written another line of the same length under his line. Alikhan claims that he got his line by cyclic shift of Tamerlan’s line a few steps to the right (cyclic shift of qwerty line for 2 positions to the right will give ertyqw line). However, Alikhan is known for the fact that he can accidentally make a mistake in a large number of calculations, so Tamerlan is at a loss – whether to believe Alikhan? Help him! From given line, print the minimum possible shift size or -1 if Alikhan is wrong.

Input format
The first two lines of input data contain Tamerlan and Alikhan lines, respectively. The line lengths are the same, do not exceed 10000 and are not equal to 0.

Output format
Print the single number - the answer to the problem question.

Examples
Input
zabcd
abcdz
Output
4
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(const string &pat) {
    int n = pat.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len == 0) {
                i++;
            } else {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

int KMP(const string &text, const string &pat) {
    vector<int> lps = computeLPS(pat);

    int i = 0, j = 0;
    int n = text.size(), m = pat.size();

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                return i - j;  
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }
    return -1;
}

int main() {
    string S, T;
    cin >> S >> T;

    if (S.size() != T.size()) {
        cout << -1;
        return 0;
    }

    string doubled = S + S;

    int pos = KMP(doubled, T);

    if (pos == -1) {
        cout << -1;
        return 0;
    }

    int n = S.size();
    int shift = (n - pos % n) % n;

    cout << shift;

    return 0;
}
