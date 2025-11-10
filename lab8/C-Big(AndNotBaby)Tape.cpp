#include <iostream>
#include <vector>

using namespace std;

const int P = 31;
const int M = 1e9 + 7;


vector<long long> computePrefixHash(const string& s, vector<long long>& pPow) {
    int n = s.size();
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; ++i)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * pPow[i]) % M;
    return h;
}


int main() {

    string big;
    int n;
    cin >> big >> n;

    vector<string> small(n);
    for (int i = 0; i < n; ++i) {
        cin >> small[i];
    }

    int L = big.size();
    vector<long long> pPow(L + 1);
    pPow[0] = 1;
    for (int i = 1; i <= L; ++i) {
        pPow[i] = (pPow[i - 1] * P) % M;
    }
        
    vector<long long> prefix = computePrefixHash(big, pPow);

    
    vector<long long> smallHashes(n);
    for (int i = 0; i < n; ++i) {
        smallHashes[i] = computePrefixHash(small[i], pPow)[small[i].size()];
    }

    vector<int> covered(L, 0);

    
    for (int i = 0; i < n; ++i) {
        int len = small[i].size();
        long long hashS = smallHashes[i];

        for (int j = 0; j + len <= L; ++j) {
            
            long long subHash = (prefix[j + len] - prefix[j] + M) % M;
            if (subHash == (hashS * pPow[j]) % M) {
                for (int k = j; k < j + len; ++k) {
                    covered[k]++;
                }
            }
        }
    }

    
    for (int i = 0; i < L; ++i) {
        if (!covered[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
