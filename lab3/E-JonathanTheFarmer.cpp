/*
Jonathan is the Farmer whose household was damaged by a huge hurricane. He lost majority of his cattle. One day he walked near his farm and observed that there are N sheeps on the field. Each sheep is always grazing inside some rectangular area. Jonathan remembered such areas for each sheep. When he came home, he decided to build a paddock to catch at least K sheeps (to catch a sheep Jonathan must cover sheep's pasture fully). Jonathan prefers squares rather than usual rectangles, therefore he want to build square paddock with the corner at point (0, 0). Material for paddock costs money, so Jonathan wants to minimize the length of paddock side. He is not very good at math, please help him find this length.

Input format
The first line  of the input contains two integers N and K (1 <= K <= N <= 2x10^5) - number of sheeps grazing in the field and the number of sheeps Jonathan wants to catch.

Each of the next N lines contain four integers x_i1, y_i1, x_i2, y_i2 (1 <= x_i1 < x_i2< <= 10^9, 1 <= y_i1 < y_i2< <= 10^9) - coordinates of bottom-left and top-right corners of the i-th sheep’s pasture.

Output format
Find the minimum length of square paddock such that at least K sheeps' pastures fit there.

EXAMPLE
Input
10 7
5 1 7 8
1 3 5 4
5 8 8 10
7 1 8 5
9 1 10 5
4 4 7 5
1 6 7 7
5 7 9 10
4 8 5 9
4 2 5 3

Output
9
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector <long long> max_values(n);
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        max_values[i] = max(x2, y2);
    }

    sort(max_values.begin(), max_values.end());

    cout << max_values[k - 1];
}