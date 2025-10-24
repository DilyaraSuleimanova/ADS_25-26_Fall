/*
Given two sorted integer arrays a and b, merge a into b as one sorted array.

Input format
The first line contains one integer n (1 ≤ n ≤ 10^5) - a size. The second line contains n integers a_i (1 ≤ a_i ≤ 10^5) - elements of array. The third line contains one integer m (1 ≤ m ≤ 10^5) - b size. The next line contains m integers b_i (1 ≤ bi ≤ 10^5) - elements of array.

Output format
Array B into sorted order.

Examples
Input
5
4 5 6 7 10
5
2 4 6 7 8

Output
2 4 4 5 6 6 7 7 8 10 
*/


#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int>& arr, int mid, int left, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }

        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

void mergeSort(vector <int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, mid, left, right);
}

int main() {
    int a;
    cin >> a;

    vector <int> list;

    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        list.push_back(x);
    }

    cin >> a;

    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        list.push_back(x);
    }
    
    int n = list.size();

    mergeSort(list, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << list[i] << " ";
    }
}
