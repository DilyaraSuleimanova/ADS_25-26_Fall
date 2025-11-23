/*
You are given two numbers A and B.

You can do one of the operations with A in each turn.
-Multiply number by 2.
-Decrease the number by 1.

You need to find the minimum number of operations, to make A equal to B.
Also print the every element after doing the operation.

Input format
In the first line given two integers A, B where 1 <= A, B <= 10^4.

Output format
Print one integer m the minimum number of operations. In the second line print m integers, number after every operation.

Examples
Input
5 9
Output
2
10 9 

Notes
Be careful about overflow
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<int> path;

    int a = A, b = B;


    while (b > a) {
        path.push_back(b);
        if (b % 2 == 0) b /= 2;
        else b += 1;
    }

    while (b < a) {
        path.push_back(b);
        b++;
    }


    reverse(path.begin(), path.end());


    cout << path.size() << "\n";


    for (int x : path) cout << x << " ";
}