/*
One day Olzhas was bored and he wanted to play the game Towns with friends. But the game has been slightly modified. In this game, each participant in his turn calls another real city of any country, the name of which begins with the maximum possible length of suffix, which ends with the name of the city of the previous participant. It was the turn of Olzhas and he should choose the name of the city. Help him with the choice of the name of the city.

Input format
Given string P (1 ≤ |P| ≤ 400) - the name of the city of the previous participant.
In the next line given N (1 < N ≤ 10^3) - the number of city names that Olzhas know.
Next N lines represent name di (1 ≤ |di| ≤ 400) of the cities. Each city name starts with an uppercase letter and other letters are lowercase.

Output format
The first line should contain integer M - the number of possible names of the cities which could say Olzhas.
Each of the next M lines should consist of the possible names of the cities in the order of their input.

Examples
Input
Kokshetau
5
Astana
Tauemel
Tainan
Almaty
Budapest
Output
1
Tauemel
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(const string &pat) {
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
    string P;
    int n;
    cin >> P >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i];

    int maxMatch = 0;
    vector<string> result;

    for (auto &city : cities) {
        string city_l = city;
        city_l[0] = tolower(city_l[0]);

        string combined = city_l + "#" + P;
        vector<int> lps = computeLPS(combined);

        int matchLen = lps.back();  

        if (matchLen > maxMatch) {
            maxMatch = matchLen;
            result.clear();
            result.push_back(city);
        } 
        else if (matchLen == maxMatch && matchLen != 0) {
            result.push_back(city);
        }
    }

    cout << result.size() << "\n";
    for (auto &c : result)
        cout << c << "\n";

    return 0;
}
