/*On the previous quiz, you needed to find n-th prime for Vanya. I think it was very easy, so let’s make it a little harder. You need to find a prime whose index is n-th prime. As an example prime numbers is: 2, 3, 5, 7... have indexes 1,2,3,4... so 2 and 3 indexes are primes too, therefore we have sequence of "superprimes" like: 3, 5, 11, 17... Find n-th superprime.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, arr[500];
    cin >> n;
    
    vector <bool> is_prime(n * n, true);
    is_prime[0] = false;
    is_prime[1] = false;
    int cnt_prime = 0, cnt_point;

    for (int i = 2; cnt_prime != n; i++){
        if (is_prime[i]) {
            for (int j = i + i; j < n * n; j += i) {
                is_prime[j] = false;
            }

            cnt_prime++;
            cnt_point = i;
        }
    }

    
    int superprime = 0, cnt_superprime = 0;
    
    for (int i = 2; cnt_superprime != cnt_point; i++){
        if (is_prime[i]) {
            for (int j = i + i; j < cnt_point * cnt_point; j += i) {
                is_prime[j] = false;
            }

            cnt_superprime++;
            superprime = i;
        }
    }

    cout << superprime;
}

