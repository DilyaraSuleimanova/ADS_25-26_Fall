/*
You are given a sorted array. Try to find number x from this array.

Input format
You are given n and n elements. After that, in the next line you are given a number x.

Output format
If the given number x is in this array, print Yes, else print No.

Examples
Input
5
1 2 3 4 5
1
Output
Yes
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> sort_arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> sort_arr[i];
    }

    int x;
    cin >> x;

    int low = sort_arr[0];    
    int high = sort_arr[n - 1];  

    bool in = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (x == mid) {
            in = true;
            break;
        }
        else if (x > mid) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (in) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}