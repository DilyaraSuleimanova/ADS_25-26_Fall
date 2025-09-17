/*On the previous quiz, you needed to find n-th prime for Vanya. I think it was very easy, so let’s make it a little harder. You need to find a prime whose index is n-th prime. As an example prime numbers is: 2, 3, 5, 7... have indexes 1,2,3,4... so 2 and 3 indexes are primes too, therefore we have sequence of "superprimes" like: 3, 5, 11, 17... Find n-th superprime.
*/

#include <iostream>

using namespace std;

int main(){
    int n, arr[500];
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

    
    int superprime = 0, cnt_superprime = 0;
    
    for (int i = 2; cnt_superprime != nth_prime; i++){
        int cnt = 0;
        for (int j = 2; j <= i; j++){
            if (i % j == 0){
                cnt++;
            }
        }
        
        if (cnt == 1) {
            superprime = i;
            cnt_superprime++;  
        }
    }

    cout << superprime;
}