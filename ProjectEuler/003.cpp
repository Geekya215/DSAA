/** Problem 3
 *
 * [Titile]:
 * Largest prime factor
 *
 * [Description]:
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * [Goal]:
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <bits/stdc++.h>
using namespace std;

int prime(int n) {
    int cnt = 1;
    while(n%(++cnt));
    return n-cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long num = 600851475143;
    int n = sqrt(num);
    while(1) {
    	if(!prime(n) && num%n==0) break;
    	n--;
    }
    cout << n << endl;
    return 0;
}