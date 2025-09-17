/*Zhansaya wants to find the sum of first and the last number of her deque. If she tired she shows the character ’!’ , if she wants to add a number to the begin she shows ’+’, and if she wants to add to the back , shows character ’-’ and if she shows ’*’, you have to find the sum of first and last elements and delete elements. Help her to solve this problem.

*/

#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int main(){
    deque <int> summ;
    vector <int> res;
    string str_res;
    char sign;
    cin >> sign;
    
    while (sign != '!') {
        int number;

        if (sign == '+') {
            cin >> number;
            summ.push_front(number);
        }
        else if (sign == '-') {
            cin >> number;
            summ.push_back(number);
        }
        else if (sign == '*') {
            if (summ.empty()) {
                res.push_back(-1);
            }
            else {
                res.push_back(summ.front() + summ.back());
                if (summ.size() == 1){
                    summ.pop_back();
                }
                else {                    
                    summ.pop_back();
                    summ.pop_front();
                }
            }
        }

        cin >> sign;
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == -1) {
            cout << "error" << endl;
        } 
        else { 
            cout << res[i] << endl;
        }
    }
    
}
/*216*/