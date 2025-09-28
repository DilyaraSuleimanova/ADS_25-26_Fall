/*Just print n-th prime number*/

// #include <iostream>

// using namespace std;

// int main(){
//     int n;
//     cin >> n;
    
//     int nth_prime = 0, cnt_prime = 0;

//     for (int i = 2; cnt_prime != n; i++){
//         int cnt = 0;
//         for (int j = 2; j <= i; j++){
//             if (i % j == 0){
//                 cnt++;
//             }
//         }

//         if (cnt == 1) {
//             nth_prime = i;
//             cnt_prime++;  
//         }
//     }

//     cout << nth_prime;
// }

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
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

    cout << cnt_point;

}