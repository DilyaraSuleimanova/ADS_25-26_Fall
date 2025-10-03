/*There is only one road and n houses in the Tokyo, and all the houses are on this road. House numbered from 1 to n and appear in this order. There are a_i ghouls living in the i-th house. Due to the RC-cells infection, a k - 1 roadblock needs to be installed between houses in Tokyo, so that k blocks of houses are detached. Kaneki Ken wants to divide ghouls so that the maximum number of ghouls over blocks (consecutive houses detached by roadblocks) is minimal. Help Kaneki find this number.

Input format
The first line contains integers n and k (1 <= k <= n <= 10^5). The second line contains the elements of the array a_i (1 <= a_i <= 10^9).

Output format
Print one number - the minimum possible maximum number of ghouls on the section of the roadblock.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector <long long> ghouls(n);
    for(int i = 0; i < n; i++) {
        cin >> ghouls[i];
    }

    long long low = *max_element(ghouls.begin(), ghouls.end());
    long long high = accumulate(ghouls.begin(), ghouls.end(), 0);

    while (low < high) {
        long long mid = low + (high - low) / 2;
        int group_cnt = 1;
        long long group_sum = 0;

        for (int i = 0; i < n; i++) {
            if (group_sum + ghouls[i] > mid){
                group_cnt++;
                group_sum = 0;
            }
            
            group_sum += ghouls[i];
        }


        if (group_cnt <= k) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << low << endl;
}