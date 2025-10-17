/*
Albert does not agree with the basic English alphabet. He thinks, that in the alphabet, first, we need to print vowel letters first and then consonants, and both vowels and consonants are ordered alphabetically. So he asks us to sort string according to his own alphabet.

Input format
The first line contains the number n (1 <= n <= 10^5), denoting the length of string. The second line contains the string s.

Output format
Print the answer.

Examples
Input
5
abcde
Output
aebcd

Input
5
wlree
Output
eelrw

Notes
Vowel letters are a, e, i, o and u.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


bool compare(char a, char b) {
    bool letter_a = isVowel(a);
    bool letter_b = isVowel(b);

    if (letter_a && !letter_b) return true;  
    if (!letter_a && letter_b) return false;  

    return a < b; 
}

int main() {

    int n;
    string s;
    cin >> n >> s;

    sort(s.begin(), s.end(), compare);

    cout << s;
}