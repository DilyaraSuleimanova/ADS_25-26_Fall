/*Given two strings. Each string contains lower case English letters and the # symbol, which means you typed backspace. Check if two strings are equal.*/

#include <iostream>

using namespace std;

const size_t N = 100001;

class Stack {
    public:
        char a[N];
        int cnt = 0;

        void push(char n) {
            if (cnt < N) {
                a[cnt] = n;
                cnt++;
            }  
        }

        char pop() {

            if (cnt > 0) {
                char result = a[cnt - 1];
                a[cnt - 1] = 0;
                cnt--;
                return result;
            }
            return -1;
        }

        char top() {

            if (cnt > 0) {
                return a[cnt - 1];
            }
            return -1;
        }


        int size() {
            return cnt;
        }
};

Stack sorted_str(string str){
    Stack s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '#') {
            s.pop();
        }
        else {
            s.push(str[i]);
        }
    }
    return s;
}

int main(){
    string str1, str2;
    Stack s1, s2;
    cin >> str1 >> str2;
    
    s1 = sorted_str(str1);
    s2 = sorted_str(str2);


    if (s1.size() == s2.size()){
        for (int i = 0; i < s1.size(); i++){
            if (s1.pop() != s2.pop()) {
                cout << "No";
                return 0;
            }
        } 
        cout << "Yes";
    }
    else {
        cout << "No";
    }

}