/*You are given list of integers and an integer k. Find nearest to k number in the list. Distance between numbers is defined as absolute value of their difference. If there are multiple such numbers, choose the first one.*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> k;
    
    for (int i = 0; i < n; i++) {
        int dis = abs(k - arr[i]);
        arr[i] = dis;
    }
    
    int minimum = arr[0], min_ind = 0;
    for (int i = 1; i < n; i++){
        if (minimum > arr[i]) {
            minimum = arr[i];
            min_ind = i;
        }
    }
    
    cout << min_ind;

}