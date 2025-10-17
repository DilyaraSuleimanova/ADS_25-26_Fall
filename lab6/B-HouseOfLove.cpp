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
Input
3 5
4 9 5
4 3 2 1 9
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

}