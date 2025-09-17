/*One day Nugman was solving problems from LAB1 and he almost solved every problem in the laboratory work. Just one problem left that Nugman couldn’t solve. Nugman asks for your help.

You are given N people in the queue, i-th person has age a_i. Queue starts at position 1. Each person wants to know if there is a younger person before him in a queue, in particular, the age of the closest person that is younger before him, otherwise print -1.*/


#include <iostream>
#include <vector>
// #include <stack>

using namespace std;

const size_t N = 100000;

class Stack{
    public:
        int a[N];
        int cnt = 0;

        void push(int n){
            if (cnt < N){
                a[cnt] = n;
                cnt++;
            }
        }

        void pop(){
            if (cnt < N) {
                int result = a[cnt - 1];
                a[cnt - 1] = 0;
                cnt--;
            }
        }

        int top(){
            if (cnt < N) {
                int result = a[cnt - 1];
                return result;
            }
            return -1;
        }

        bool empty() {
            if (cnt < N && cnt == 0) {
                return true;
            }
            return false;
        }


};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // stack <int> st;
    Stack st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }


        if (st.empty()) {
            res[i] = -1;
        }
        else {
            res[i] = a[st.top()];
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}
