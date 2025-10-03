/*KBTU has a database crash. That’s why the list of all students is now wrong. Some names of this list were duplicated. Due to the nature of crash, it is known that duplicates of the same name occupy subsequent positions in the list. For instance, name “Dana” may occupy positions 2, 3, 4, but cannot occupy positions 2, 3, 5 since these positions are not consequent. Help teachers to get rid of these duplicates.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names;
    string prev = "";

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

  
        if (names.empty() || name != prev) {
            names.push_back(name);
            prev = name;
        }
    }

    cout << "All in all: " << names.size() << endl;
    cout << "Students:" << endl;
    for (int i = names.size() - 1; i >= 0 ; i--) {
        cout << names[i] << endl;
    }

    return 0;
}