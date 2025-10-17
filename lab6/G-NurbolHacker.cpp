/*
This is a continuation of the story about the Aslan and Password task from the last quiz. The story is that Nurbol successfully hacked Aslan’s Steam account. Aslan was of course upset, but he doesn’t give up. He decided to restore his Steam account. To do this, he wrote in support of Steam. Aslan gave them the nickname of his account. But it is possible for Nurbol to change the nickname of the account. And now Steam employees must understand what the new nickname is. Employees have logs of changing nicknames, the logs consist of n lines. The line itself consists of two words, the old nickname, and the new one. Help employees to display all original nicknames and new nicknames next to them.

Input format
The first line is number n (1 <= n <= 1000) the number of requests to change the nickname. Next n lines consist of two strings, old nickname and new nickname.

Output format
The first line is the number q - unique users who changed their nicknames. Next q lines consist of two strings, old nickname and new nickname. (Use map to sort old nicknames)

Examples
Input
2
Aslan Nurbol
Nurbol HackMachine
Output
1
Aslan HackMachine

Input
6
Sens3i Danya
S1mple Papa
M9snoyPovar AWPMaster
IAmNoob IAmPro
Papa Sanya
IAmPro IAmNoob
Output
4
IAmNoob IAmNoob
M9snoyPovar AWPMaster
S1mple Sanya
Sens3i Danya

Notes
In the first test nickname "Aslan" was changed to nickname "Nurbol". Then this nickname was changed to "HackMachine". As a result, the original nickname "Aslan" became "HackMachine".


*/


#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map <string, string> nicknames;

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;

        if (nicknames.empty()) {
            nicknames[s1] = s2;
        }
        else {
            bool found = false;
            for (auto& it : nicknames) {
                if (it.second == s1) {
                    it.second = s2;
                    found = true;
                    break;
                }
            }

            if (!found) {
                nicknames[s1] = s2;
            }
        }
    }

    cout << nicknames.size() << endl;
    for (auto it: nicknames) {
        cout << it.first << " " << it.second << endl;
    }
}