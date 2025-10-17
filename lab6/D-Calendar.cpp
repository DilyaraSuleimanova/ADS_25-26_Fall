/*
You’re given n dates in format DD-MM-YYYY. Sort them in ascending and print in the same format.

Input format
The first line contains one integer n (1 <= n <= 1000). Next n lines contain dates in format DD-MM-YYYY (1 <= D <= 31, 1 <= M <= 12, 1900 <= Y <= 3000).

Output format
Print sorted dates in the same format as the input.

Examples
Input
3
01-12-2000
01-11-2000
31-10-2000

Output
31-10-2000
01-11-2000
01-12-2000
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector <vector <string>> dates(n, vector <string> (3));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dates[i][0] = s.substr(6, 4);
        dates[i][1] = s.substr(3, 2);
        dates[i][2] = s.substr(0, 2);
    }

    sort(dates.begin(), dates.end());
    for (int i = 0; i < n; ++i) {
        cout << dates[i][2] << "-" << dates[i][1] << "-" << dates[i][0] << endl;
    }
}