/*
You have one letter. Your task is to find "balanced" char in array. "Balanced" char is the smallest in array, but more than your letter.

Input format
You are given integer n. n - number of elements in array.Then goes an array. Array has only sorted lowercase letter.

Output format
Print the "balanced" letter.

Examples
Input
3
c f g
a
Output
c

Input
3
c f j
f
Output
j

Input
3
c f j
j
Output
c

Input
3
c f j
k
Output
c

Notes
Size of array should be more than 1;
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <char> list;

    for (int i = 0; i < n; ++i) {
        char letter;
        cin >> letter;

        list.push_back(letter);
    }

    char my_l;
    cin >> my_l;

    sort(list.begin(), list.end());

    char min_l = ' ';
    
    for (int i = 0; i < n; ++i) {
        if (list[i] > my_l) {
            min_l = list[i];
            break;
        }
    }
    
    if (min_l != ' ') {
        cout << min_l;
    }
    else {
        cout << list[0];
    }
}