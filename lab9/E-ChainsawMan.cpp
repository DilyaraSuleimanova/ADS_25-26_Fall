/*
After endterm Makima decided to do the problems for the final exam. Do you know what is the hardest thing in making a problem? It is the name of the task.
Makima has a task name draft s. The name of the task must contain a given string as a substring at least k times. But she has a limitation: the name of the task cannot be very long, and she wants to find the shortest one. Help Makima to find the length of the shortest task name satisfying desired condition.

Input format
The first line contains a single integer t - the number of testcases. Each of the next t lines contains string s consisting of only lowercase letters and a number k(1 < k < 10^6). The sum of lengths of strings over all testcases will not exceed 5 . 10^5

Output format
For each test case print answer in separate line.

Examples
Input
3
asas 3
aaa 1
b 2
Output
8
3
2
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(string& pat) {
    int n = pat.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) { // case 1.
            len++;
            lps[i] = len;
            i++;
        } else { 
            if (len == 0) { // case 2.
                lps[i] = 0;
                i++;
            } else { // case 3: len > 0.
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

int main() {

    int n;
    cin >> n;

    vector<int> result;

    for (int i = 0; i < n; ++i) {
        string s;
        int k;
        cin >> s >> k;

        
        vector<int> lps = computeLPS(s);
        
        int last_l = lps.back();
        int size_s = s.size();

        int res = size_s + (k - 1) * (size_s - last_l);

        result.push_back(res);

    }
    
    for (auto& l: result) {
        cout << l << endl;
    }

    return 0;
}