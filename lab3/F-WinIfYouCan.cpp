/*
Mark is going to fight for Fight Club. There were N competitors with different powers. There will be P rounds to fight and in each round Mark’s power will be changed. With power M, Mark can kill all the competitors whose power is equal to or less than his. Round by round, all the competitors who are dead in the previous round will be reborn. Such that in each round there will be N competitors to fight. As Mark is tired, please, help him to count the number of competitors that he can win in each round and the total sum of their powers.

Input format
The first line contains an integer N (1 <= N <= 10^6) - the number of competitors without Mark. Next line contains N integers a_i (1 <= a_i <= 10^3) - powers of these competitors. The third line contains one integer P (1 <= P <= 10^6) number of rounds. Each of the next P lines contains an integer p_i (1 <= p_i <= 10^3) - power of Mark at each round.

Output format
On each of the P lines print one integer - how many competitors Mark will win and the sum of their powers.

Examples
Input
7
7 9 1 8 2 6 2
2
4
8

Output
3 5
6 26
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n;

    vector <int> competitors;
    for (int i = 0; i < n; ++i) {
        int competitor;
        cin >> competitor;
        competitors.push_back(competitor);
    }

    sort(competitors.begin(), competitors.end());

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + competitors[i];
    }
    
    cin >> p;
    while (p--) {
        int mark_power;
        cin >> mark_power;
        
        int rounds = 0;
    
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (competitors[mid] > mark_power) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
                rounds = mid + 1;
            }


        }

        cout << rounds << " " << prefix[rounds] << endl;

    }
}