/*You are given array a (1 <= a_i <= 10^9) of length n (1 <= n <= 100) and q (1 <= q <= 100) queries. In query i you are given two pairs of segments l1, r1, l2, r2 (1 <= l1 <= r1 <= 10^9, 1 <= l2 <= r2 <= 10^9), find number of indices c (1 <= c <= n) for which one of the following conditions is satisfied: l1 <= a_c <= r1 or l2 <= a_c <= r2.

Input format
First line contains two integers n, q. The next q lines contain 4 integers l1, r1, l2, r2.

Output format
Output q lines - answers to the queries.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector <int> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }


    sort(array.begin(), array.end());
    
    
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt1 = upper_bound(array.begin(), array.end(), r1) -
                   lower_bound(array.begin(), array.end(), l1);

                   
        int cnt2 = upper_bound(array.begin(), array.end(), r2) -
                   lower_bound(array.begin(), array.end(), l2);

                   
        int L = max(l1, l2);
        int R = min(r1, r2);
        int overlap = 0;
        if (L <= R) {
            overlap = upper_bound(array.begin(), array.end(), R) -
                      lower_bound(array.begin(), array.end(), L);
        }

        cout << (cnt1 + cnt2 - overlap) << endl;
    }

}


