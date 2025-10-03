/*You are given a list of integer numbers. Print its mode. Mode is the number that occurs most frequently in the list. If there is several modes, print them in descending order.
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000] = {0};

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        arr[num]++;
    }

    int max_mode = 1;
    for (int i = 0; i < 1000; i++) {
        if (max_mode < arr[i]) {
            max_mode = arr[i];
        }
    }

    for (int i = 1000; i >= 0; i--) {
        if (max_mode == arr[i]) {
            cout << i << " ";
        }
    }

}