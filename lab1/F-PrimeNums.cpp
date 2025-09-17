/*Just print n-th prime number*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int nth_prime = 0, cnt_prime = 0;

    for (int i = 2; cnt_prime != n; i++){
        int cnt = 0;
        for (int j = 2; j <= i; j++){
            if (i % j == 0){
                cnt++;
            }
        }

        if (cnt == 1) {
            nth_prime = i;
            cnt_prime++;  
        }
    }

    cout << nth_prime;
}