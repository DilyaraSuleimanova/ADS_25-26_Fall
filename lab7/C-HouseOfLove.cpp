/*
Once upon a time, in one university, created a one organization called "House of love" in which friendship is the main value. So they created one test to know level of their friendship. Two person write some numbers and gives it to you, to check common numbers.

Input format
First line contain two numbers n,m. Size of arrays. Next 2 line contain n numbers of first person and m numbers of second.

Output format
Print common numbers.

Examples
Input
4 2
1 2 2 1
2 2

Output
2 2 
*/


#include <iostream>
#include <vector>
#include <map>

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
    int n, m;
    cin >> n >> m;
    
    map <int, int> freq;
    vector <int> result;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++; 
    }

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }

    mergeSort(result, 0, result.size() - 1);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}