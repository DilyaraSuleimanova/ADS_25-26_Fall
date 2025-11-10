#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 1e9 + 7;
const long long P = 11;


long long computeHash(const string &s) {
    long long hash = 0;
    long long pPow = 1;
    for (char c : s) {
        hash = (hash + (c - 47) * pPow) % MOD;
        pPow = (pPow * P) % MOD;
    }
    return hash;
}

bool inVector(vector<string> arr, long long hash) {
    string s = to_string(hash);
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] == s) return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> input(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> input[i];
    }

    vector<pair<string, long long>> res;

    
    for (auto &s: input) {        
        long long h = computeHash(s);
        if (inVector(input, h)) {
            res.push_back({s, h});
        }
    }

    for (auto it = res.begin(); it != res.end(); it++) {
        cout << "Hash of string \"" << it->first << "\" is " << it->second << "\n";
    }

    return 0;
}
