/*In class A, students want to establish a class leader. The class splitted into two fractions: Sakayanagi and Katsuragi. They decided to decide the leader by the following procedure:

1. Each of n students makes a statement. They make statements one by one starting from student 1 and finishing with student n. If student were kicked from the procedure, he/she is skipped.
2. When student makes a statement, he/she can kick any other student from procedure. If someone is kicked from procedure he no longer participates in the procedure till the very end.
3. When the round is finished, i.e. all students are done with their statements, the procedure repeats from step 1.
4. The process repeats until there is only one student eligible to participate and this student becomes the group leader.

Determine the fraction of the group leader, if both fractions play optimally (i.e. both fractions act best they can to make the group leader from their fraction).

*/


#include <iostream>
// #include <queue>

using namespace std;

const size_t N = 500000;

class Queue{
    public:
        int a[N];
        int cnt = 0, beginning = 0;

        void push(int n){
            if (cnt < N){
                a[cnt] = n;
                cnt++;
            }
        }

        void pop(){
            if (cnt > beginning) {
                int result = a[beginning];
                a[beginning] = 0;
                beginning++;
            }
        }

        int front(){
            if (cnt > beginning) {
                int result = a[beginning];
                return result;
            }
            return -1;
        }

        bool empty() {
            if (cnt < N && cnt - beginning == 0) {
                return true;
            }
            return false;
        }


};

int main() {
    // queue <int> S, K;
    Queue S, K;
    string str; 
    int i, n, arr[2] = {0, 0};

    cin >> n >> str;

    for (i = 0; i < n; i++){
            if (str[i] == 'S'){
                S.push(i);
            }
            else {
                K.push(i);
            }
    }
    
    while (!S.empty() && !K.empty()){
            int InsdexS = S.front();
            S.pop();
            int InsdexK = K.front();
            K.pop();

            if (InsdexK > InsdexS) {
                S.push(InsdexS + n);
            } 
            else {
                K.push(InsdexK + n);
            }

    }

    if (S.empty()) {
        cout << "KATSURAGI";
    }
    else {
        cout << "SAKAYANAGI";
    }

    
    
}