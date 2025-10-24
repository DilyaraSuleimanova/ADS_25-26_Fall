/*
Almas loves to sort numbers with specific rules that he comes up with himself. Today he wants to sort rows, each row contain m integer elements. He decided to sort rows in decreasing order of their sum, i.e. the row with larger sum will be the first. In case the sums are equal, then he order rows lexicographically, i.e. The row with least first element will be the first, if first elements are equal, then compare second element, third element, etc. He successfully finished sorting. He wanted to put the result in the closet, but accidentally put it in the shredder and divided everything into rows again. Help him sort it again.

Input format
The first line contains two numbers, n and m the number of rows and number of elements in a row. The next n lines contain m numbers, elements of each row.
1 <= n, m <= 500
0 <= row[i] <= 5000

Output format
Print rows in desired sorted order.

Examples
Input
5 3
1 2 3
1 2 4
1 3 2
6 0 0
2 3 2

Output
1 2 4 
2 3 2 
1 2 3 
1 3 2 
6 0 0 
*/


#include <iostream>
#include <vector>

using namespace std;

int rowSum(vector <int>& row) {
    int sum = 0;

    for (int x : row) {
        sum += x;
    }

    return sum;
}

bool cmp(vector <int>& a, vector <int>& b) {
    int sumA = rowSum(a);
    int sumB = rowSum(b);

    if (sumA != sumB) {
        return sumA > sumB;
    }

    return a < b; 
}

void merge(vector <vector <int>>& arr, int mid, int left, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <vector <int>> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j])) {
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

void mergeSort(vector <vector <int>>& arr, int left, int right) {
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

    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> rows[i][j];
        }
    }

    mergeSort(rows, 0, n - 1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << rows[i][j] << " ";
        }

        cout << endl;
    }
}