/** Problem 7
 *
 * [Titile]:
 * 10001st prime
 *
 * [Description]:
 * By listing the first six prime numbers: 2, 3, 5,
 * 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * [Goal]:
 * What is the 10 001st prime number?
 */

#include <bits/stdc++.h>
using namespace std;

const int size = 1e6+5;
const int bound = 1e6;
int prime[size];
int vis[size];
int cnt = 0;

void sieve_of_euler() {
    for(int i = 2; i <= bound; ++i) {
        if(!vis[i]) prime[cnt++] = i;
        for(int j = 0; j<cnt && i*prime[j]<=bound; ++j) {
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve_of_euler();
    cout << prime[10000] << endl;
    return 0;
}
