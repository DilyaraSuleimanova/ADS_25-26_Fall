/*
Given two strings A and B. Your task is to find the minimum number of times A has to be repeated such that B is a substring of it. If B cannot be found in A after it’s extension, return -1. If A already contains B, the number of repetitions is equal to one by default.

Input format
Input contains two lines, where the first line denotes the string A, and the second line - string B. Input strings contain either lowercase or uppercase letters. Lengths of A and B are between 1 and 10^5.

Output format
Print the minimum number of repetitions of A, such that B is a substring of A.

Examples
Input
abcd
cdabcdab
Output
3

Input
aaa
a
Output
1
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

bool search(string& text, string& pat) {
    vector<int> patLps = computeLPS(pat);

    int n = text.size();
    int m = pat.size();

    int i = 0;
    int j = 0;

    vector<int> result;

    while(i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;

            if (j == m) {
                return true;
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = patLps[j - 1];
            }
        }
    }

    return false;
}

int main() {

    string A, B;
    cin >> A >> B;

    int cnt = 1;
    string repeat = A;
    
    while (repeat.size() < B.size()) {
        repeat += A;
        cnt++;
    }
    
    cout << repeat << endl;

    if (search(repeat, B)) {
        cout << cnt;
        return 0;
    }

    repeat += A;
    cnt++;

    if (search(repeat, B)) {
        cout << cnt;
    } else {
        cout << -1;
    }

    return 0;
}