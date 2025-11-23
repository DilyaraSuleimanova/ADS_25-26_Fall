/*
The string s was written many times in a row, after which a substring was taken from the resulting string and given to you. Your task is to determine the minimum possible length of the original string s.

Input format
The only line contains string S (0 ≤ |s| ≤ 50000).

Output format
The solution of the task.

Examples
Input
zzz
Output
1

Input
bcabcab
Output
3
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
        if (pat[i] == pat[len]) { // case 1.
            len++;
            lps[i] = len;
            i++;
        } else { 
            if (len == 0) { // case 2.
                lps[i] = 0;
                i++;
            } else { // case 3: len > 0.
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

int main() {
    string s;
    cin >> s;

    vector<int> lps = computeLPS(s);
    int last = lps.back();
    int ans = s.size() - last;

    cout << ans;
    
}