/*
You are given a list of integer points in a line. Find the pair of points with the least absolute difference. If there are more than one pairs output them all.

Input format
The first line contains an integer N (2 <= N <= 2 * 10^5), number of points. The next line represents N integer numbers (-10^7 <= points[i] <= 10^7) denoting the points in a line.

Output format
Output the pairs of points with the least absolute difference.

Examples
Input
6
-20 -3916237 -357920 -362060 30 6246457
Output
-20 30
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> list;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        
        list.push_back(x);
    }

    sort(list.begin(), list.end());

    int min_value = 10000000;
    for (int i = 1; i < n; ++i) {
        if (min_value > abs(list[i] - list[i - 1])) {
            min_value = abs(list[i] - list[i - 1]);
        }
    }

    for (int i = 1; i < n; ++i) {
        if (abs(list[i] - list[i - 1]) == min_value) {
            cout << list[i - 1] << " " << list[i] << " ";
        }
    }
}

