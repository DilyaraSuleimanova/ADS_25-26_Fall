/*
Given a string s, calculate the number of ways to divide s into 3 non-empty strings a, b, c such that:
a + b + c = S and a + c = b + c

Input format
You are given the string s (1 ≤ |s| ≤ 5 * 10^6), consisting of small Latin letters.

Output format
Print the number of ways to partite string.

Examples
Input
ababababcx
Output
2

Notes
String from the first testcase can be partitioned in two ways:
1. ab + ab + ababcx
2. abab + abab + cx
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            ++Z[i];
        }
        
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    long long ans = 0;
    
    for (int k = 1; 2 * k < n; ++k) {
        if (Z[k] >= k) {
            ++ans;
        }
    }
    cout << ans;

    return 0;
}