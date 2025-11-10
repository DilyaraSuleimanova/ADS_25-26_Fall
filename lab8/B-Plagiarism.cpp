#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull P = 131; 


vector<ull> compute_hash(const string &s) {
    int n = s.size();
    vector<ull> h(n + 1, 0);
    vector<ull> power(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        h[i + 1] = h[i] * P + (s[i] - 'a' + 1);
        power[i + 1] = power[i] * P;
    }

    return h;
}


ull get_hash(const vector<ull> &h, int l, int r, const vector<ull> &power) {
    return h[r + 1] - h[l] * power[r - l + 1];
}

int main() {

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n = s1.size();
    int m = t.size();


    vector<ull> power(max(n, m) + 1, 1);
    for (int i = 1; i <= max(n, m); ++i)
        power[i] = power[i - 1] * P;


    vector<ull> h1 = compute_hash(s1);
    vector<ull> h2 = compute_hash(s2);
    vector<ull> ht = compute_hash(t);

    ull target = ht.back(); 
    int count = 0;

    for (int i = 0; i + m <= n; ++i) {
        ull hash1 = get_hash(h1, i, i + m - 1, power);
        ull hash2 = get_hash(h2, i, i + m - 1, power);

        if (hash1 == target && hash2 == target)
            count++;
    }

    cout << count;
    return 0;
}