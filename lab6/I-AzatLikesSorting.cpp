/*
Azat is a perfectionist and he likes everything to be perfect. Help Azat sort letters alphabetically. good luck!

Input format
The input string and only small letters.

Output format
Print answer.

Examples
Input
ijnuhbygvtfcrdx

Output
bcdfghijnrtuvxy

Input
asdzxchfg

Output
acdfghsxz

Notes
you cannot use the sort function
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (s[i] < s[j]) {
                char temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }

    cout << s;
}

/*
 i
qwertyuioplkjvbn
j
*/