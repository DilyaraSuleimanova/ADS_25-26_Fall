/*
Thomas received a new password from his employee. Since Thomas always checks the information, he asks you to check if the password is correct.
It is known that the password is correct only if it occurs at least K times on a piece of paper that the Bank Director gave to Thomas.

Input format
The first line contains a string s and an integer K (3 <= |s| <= 10^5, 1 <= K <= 10000), where s is a new password. The second line contains a string T (3 <= |T| <= 10^5), a string on a piece of paper.

Output format
Print YES if password is correct, otherwise print NO

Examples
Input
hello 2
helloThomashelloArthurhelloJohnhello
Output
YES
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(string& pat) {
    int n = pat.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                len = lps[i - 1];
            }
        }
    }
    return lps;
}

vector<int> search(string& text, string& pat) {
    vector<int> patLPS = computeLPS(pat);

    int n = text.size();
    int m = pat.size();

    int i = 0;
    int j = 0;

    vector<int> result;

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {
                result.push_back(i - j);
                j = patLPS[j - 1];
            }
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = patLPS[j - 1];
            }
        }
    }

    return result;
}

int main(){
    string ps, s;
    int k;
    cin >> ps >> k >> s;

    vector<int> searchIdx = search(s, ps);

    int n = searchIdx.size();

    if (k <= n) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

}