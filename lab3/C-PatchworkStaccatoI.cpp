/*You are given array a (1 <= a_i <= 10^9) of length n (1 <= n <= 10^5) and q (1 <= q <= 10^5) queries. In query i you are given two pairs of segments l1, r1, l2, r2 (1 <= l1 <= r1 <= 10^9, 1 <= l2 <= r2 <= 10^9), find number of indices c (1 <= c <= n) for which one of the following conditions is satisfied: l1 <= a_c <= r1 or l2 <= a_c <= r2.

Input format
First line contains two integers n, q. The next q lines contain 4 integers l1, r1, l2, r2.

Output format
Output q lines - answers to the queries.
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector <long long> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    
    
    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((l1 <= array[i] && array[i] <= r1) || (l2 <= array[i] && array[i] <= r2)) {
                cnt++;
            }
        }

        cout << cnt << endl;

    }


}