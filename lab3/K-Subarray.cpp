/*
You are given an array of non negative integers and a number k. Let’s define subarray as a non-empty consecutive elements of an array. Among all subarrays of the given array, find the one, such that sum of its elements is no less than k and such that this subarray would contain minimum possible number of elements.

Input format
First line contains two space separated numbers n, k — number of elements in given array and number that was mentioned above, respectively (1 <= n <= 10^5), (0 <= k <= 10^9).
Second line contains n space separated numbers a_1, a_2, ..., a_n — given array (0 <= a_i <= 10^4).
It is guaranteed that at least one subarray’s some is not less than k.

Output format
Output single number x — minimum possible number of elements of some subarray, such that sum of elements of this subarray is not less than k.

Examples
Input
3 12
3 5 7

Output
2

Notes
In the first test case we have three elements. Subarrays are [3], [3, 5],  [3, 5, 7], [5], [5, 7], [7]. Only two subarrays have sum that is not less than k = 12: [3, 5, 7], [5, 7]. Out of these two subarrays, [5, 7] has minimum possible length of 2.

Hint

For a fixed left end of subarray, sums of subarray increase, if we increase number of elements in it. So we can do binary search on right end of subarray for a fixed left end.
In order to quickly know sum of subarray we can calculate prefix sums. For example for the given array from the first test case prefix sums would be [3, 8, 15]. In order to get sum of second and third element, from prefix sum at position 3 we subtract prefix sum at position 1: 15 - 3 = 12.
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector <int> prefix(n + 1);

    for (int i = 1; i <= n; ++i) {
        int element;
        cin >> element;
        prefix[i] = prefix[i - 1] + element;
    }

    int ans = n; 
    for (int l = 1; l <= n; l++) {
        
        long long target = prefix[l - 1] + k;
        auto it = lower_bound(prefix.begin(), prefix.end(), target);

        if (it != prefix.end()) {
            int r = it - prefix.begin();
            ans = min(ans, r - (l - 1));
        }
    }

    cout << ans << endl;
}

// [0, 3, 8, 15]
//  target = 12, it = 4, r = 4, ans = 4
//  target = 15, it = 4, ans = 4
//  target = 20, it = 4, r = 4, ans = 2
//  target = 27, it = 4, r = 4, ans = 1