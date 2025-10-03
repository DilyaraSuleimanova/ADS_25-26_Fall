/*
Jonathan almost finished his project by Object-Oriented Programing course. His code consists of N consecutive blocks, each of them consists of a certain amount of lines. Unfortunately, Jonathan made a lot of mistakes. Compiler showed that Jonathan made M mistakes, each of them is described by the number of line where this mistake was made. To debug his project faster, Jonathan wants to define number of block in which he made a mistake. Please, help Jonathan debug his project before deadline will expire.

Input format
First line consists of integers N and M - number of blocks and mistakes (1 <= N, M <= 2x10^5)
The second line contains N integers a_i - number of lines in the i-th block  (1 <= a_i <= 10^4)
Each of the next M lines contains one integer b_i - number of line where the i-th mistake was made  (1 <= b_i <= 2x10^9)

Output format
Print M lines, the i-th line must contain the number of block in which the i-th mistake was made.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector <int> blocks;
    vector <int> block_indx(n);
    int all = 0;
    for (int i = 0; i < n; ++i) {
        int block;
        cin >> block;
        blocks.push_back(block);
        
        all += block;
        block_indx[i] = all; 
        // cout << block_indx[i] << " ";
    }
    // cout << endl;
    
    while (m--) {
        int mistake, mis_block = 1;
        cin >> mistake;

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (block_indx[mid] >= mistake) {
                high = mid - 1;
                mis_block = mid; 
            }
            else {
                low = mid + 1;
            }
        }
        
        cout << mis_block + 1 << endl;
    }
    

}

// mid = 9 -> high = 9
// mid = 5 -> 