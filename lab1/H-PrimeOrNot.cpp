/*Asman is very curious and likes to check whether some number is prime or not. Check if the number is prime. A prime number is a number that has only 2 divisors, it is 1 and the number itself.
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 2; i <= n; i++){
        if (n % i == 0){
            cnt++;
        }
    }

    if (cnt == 1){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}