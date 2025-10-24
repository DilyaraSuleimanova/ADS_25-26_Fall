/*
Given a set of strings print the set sorted according to their size. If the size of the strings are equal, must maintain the original order of the set.

Input format
The first line of input has an integer T that indicates the number of sets of strings, each set may contain between 1 and 50 inclusive elements, and each of the strings of the set may contain between 1 and 50 inclusive characters(’a’ to ’z’).

Output format
The output should contain the set of input strings ordered by the length of strings.A blank space must be printed between two words.

Examples
Input
3
ab cd e j asd ljffg df
a a b b c c
xy yx zxy zx xzy xxx

Output
e j ab cd df asd ljffg 
a a b b c c 
xy yx zx zxy xzy xxx 
*/


#include <iostream>
#include <vector>

using namespace std;

void merge(vector <string>& arr, int left, int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <string> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].size() <= R[j].size()) {
            arr[k] = L[i];
            i++;
        }

        else if (L[i].size() > R[j].size()) {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector <string>& arr, int left, int right){
    
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}



int main() {

    int n;
    cin >> n;

    vector <string> list;

    while (n--) {
        string s;

        while (cin >> s) {
            list.push_back(s);

            if (cin.peek() == '\n') {
                break;
            }
        }

        int m = list.size() - 1;

        mergeSort(list, 0, m);

        for (int j = 0; j <= m; ++j) {
            cout << list[j] << " ";
        }

        cout << endl;

        list.clear();
    }
    
}