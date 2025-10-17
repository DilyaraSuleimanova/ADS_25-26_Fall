/*
You are given matrix with n rows and m columns.
You have to sort each column of matrix in descending order.

Input format
The first line consists of two integers n and m - number of rows and columns of matrix respectively.
Each of the next n lines contains m integers d_i,j - elements of the matrix at the intersection of ith row and jth column.

Output format
Print this matrix after sorting.

Examples
Input
4 3
1 2 3
4 5 6
6 7 8
9 8 7

Output
9 8 8 
6 7 7 
4 5 6 
1 2 3 
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    
    for (int j = 0; j < m; ++j) {
        vector <int> sort_arr;

        for (int i = 0; i < n; ++i) {
            sort_arr.push_back(arr[i][j]);
            // cout << arr[i][j] << " ";
        }
        
        sort(sort_arr.begin(), sort_arr.end());
        reverse(sort_arr.begin(), sort_arr.end());
        
        for (int i = 0; i < n; ++i) {
            arr[i][j] = sort_arr[i];
            // cout << sort_arr[i] << " ";
        }
        // cout << endl;

    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}