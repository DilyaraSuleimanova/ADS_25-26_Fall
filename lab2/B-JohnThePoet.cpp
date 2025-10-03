/*Jonathan the Poet has finished his new poem recently. But something went wrong and now he thinks that rhyme could be better. He believes that applying cyclic shift by K positions will fix the problem. Jonathan’s new poem is a sequential list of words. Jonathan is tired and asked your help to find such cyclic shift.

To clarify, you are given a poem of N words as a single linked list. Your task is to write function that shifts linked list by K positions and returns the head of new linked list.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    vector <string> poem;

    cin >> n >> k;

    for (int i = 0; i < n; i++ ) {
        string s;
        cin >> s;
        poem.push_back(s);
    }

    for (int i = k; i < n; i++) {
        cout << poem[i] << " ";
    }

    for (int i = 0; i < k; i++) {
        cout << poem[i] << " ";
    }
}