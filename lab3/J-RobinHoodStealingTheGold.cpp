/*
Robin Hood wants to steal the golden bars from the bank of High Sheriff aiming to distribute them to poor local people. There are N bags of golden bars, the i-th bag has bags[i] bars. Sheriff has gone and will return in H hours.
Robin can steal K bars per hour. Each hour, he chooses a single bag of golden bars, and steals K bars from that bag. If there are less than K bars in the bag, he steals them all, and won’t steal any more during this hour.
Robin Hood wants to steal all of the golden bars before the Sheriff comes back.
Return the minimum number K such that Robin can steal ALL of the golden bars within H hours.

Input format
The first line of the input contains two space-separated integers N (1 <= N <= 10^4), H (N <= H <= 10^9), the number of bags of golden bars and the number of hours for which Sheriff has gone. The next line contains N space-separated integers (1 <= bags[i] <= 10^9) denoting the number of golden bars in each bag.

Output format
Print the minimum number K such that Robin Hood can steal all of the N golden bars within the limit of H hours.

Examples
Input
4 8
3 6 7 11

Output
4

Notes
K is Robin’s speed of stealing the bars such that sum(bags[i]/K) = H, i = from 1 to N.
If Robin can finish stealing all the bars (within H hours) with speed of K, he can finish with a larger speed too.
If we let possible(K) be true if and only if Robin can finish with a speed of K, then there is some X such that possible(K) = true iff K >= X.
For the first test case there is some X = 4 so that possible(1) = possible(2) = possible(3) = false, and possible(4) = possible(5) = ... = true. K = 4 is minimum K such that 3/4 + 6/4 + 7/4 + 11/4 = 1 + 2 + 2 + 3 = 8. K = 5 is also a right answer but it is not a minimum K.
*/


#include <iostream>
#include <vector>

using namespace std;

int total_hours(int speed, const vector <int>& bars) {
    long long summa = 0;
    for (int b: bars) {
        summa += (b + speed - 1) / speed;
    }

    return summa;
}

int main() {
    int n, h;
    cin >> n >> h;

    vector <int> golden_bars(n);
    int max_golds = 1;
    for (int i = 0; i < n; ++i) {
        cin >> golden_bars[i];
        max_golds = max(max_golds, golden_bars[i]);
    }

    int low = 1;
    int high = max_golds;
    int min_golds = max_golds;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (total_hours(mid, golden_bars) <= h) {
            min_golds = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    

    cout << min_golds;

}