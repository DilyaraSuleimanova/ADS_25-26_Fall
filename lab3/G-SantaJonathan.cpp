/*
Christmas is coming! It means that each child living in the Duck Islands must receive a long-awaited gift. All children from the same island wish for a rubber duck of the same color (colors are distinct among all islands). During one flight Santa Jonathan can deliver gifts only of one color and the number of gifts that he can deliver at a time is restricted by the capacity of his bag. Santa Jonathan appreciates his time very much, so he wants to do no more than f flights. Please, help him find the least possible capacity of the bag to deliver all gifts during no more than f flights.

Input format
The first line of the input contains two integers n and f - number of islands in the Duck Kingdom and number of flights (1 <= n <= f <= 10^5)
The second line of the input contains n integers c_i - number of children in the i-th island (1 <= c_i <= 10^4).

Output format
Please, find the least posible capacity of the bag that satisfies all conditions

Examples
Input
3 6
10 10 10

Output
5

Input
5 7
10 34 14 6 20

Output
17
 */

#include <iostream>
#include <vector>

using namespace std;

int total_flights(int capacity, const vector <int>& childs) {
    long long summa = 0;
    for (int c: childs) {
        summa += (c + capacity - 1) / capacity;
    }

    return summa;
}

int main() {
    int n, f;
    cin >> n >> f;

    vector <int> childs_in_island(n);
    int max_gift = 1;
    for (int i = 0; i < n; ++i) {
        cin >> childs_in_island[i];
        max_gift = max(max_gift, childs_in_island[i]);
    }

    int low = 1;
    int high = max_gift;
    int min_gifts = max_gift;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (total_flights(mid, childs_in_island) <= f) {
            min_gifts = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    

    cout << min_gifts;

}

// 10 34 14 6 20
// 6 10 14 20 34