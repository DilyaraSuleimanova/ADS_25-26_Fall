    /*Write a program that outputs the coordinates of elements from a array of size n x m, which is filled like snake. Snake array - which is filled in like this:

    - For all j and k (j < k): a_ij > a_(i + 1)j.
    - If i is even then, for all j and k (j < k): a_ij > a_ik.
    - If i is odd then, for all j and k (j < k): a_ij < a_ik.

    Here is an example of 3 x 4 Snake array:
    25 23 20 19
    13 15 17 18
    12 10 9 8

    Input format
    The first line of input contains a single number t - the number of elements which you must find. 1 <= t <= 1000.
    The next line contains t integers - the values of the elements that you need print their coordinates.
    The next line of input contains 2 space-separated integers, n and m, the number of rows and the columns. 1 <= n, m <= 800.
    The next n lines contain m integers. Snake array n x m, -10^7 <= a_ij <= 10^7 for each 0 <= i <= n, 0 <= j <= m. 

    Output format
    Print k lines the answer with coordinates for each case. If the given element is not in the snake array, then print -1.
    */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;                        
    vector<int> queries(t);

    for (int i = 0; i < t; i++) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;                 

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int val : queries) {
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            
            int low = 0;
            int high = m - 1;

            if (i % 2 == 0) {

                while (low <= high) {

                    int mid = low + (high - low) / 2;
                    
                    if (arr[i][mid] == val) {
                        cout << i << " " << mid << endl;
                        found = true;
                        break;
                    }

                    if (arr[i][mid] > val) low = mid + 1;

                    else high = mid - 1;
                }
            } 
            else {
            
                while (low <= high) {
                    
                    int mid = low + (high - low) / 2;

                    if (arr[i][mid] == val) {
                        cout << i << " " << mid << endl;
                        found = true;
                        break;
                    }
                    
                    if (arr[i][mid] < val) low = mid + 1;

                    else high = mid - 1;
                }
            }
        }

        if (!found) {
            cout << -1 << endl ;
        }
    }

    return 0;
}