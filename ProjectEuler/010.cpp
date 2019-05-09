/** Problem 10
 *
 * [Title]:
 * Summation of primes
 *
 * [Description]:
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
 *
 * [Goal]:
 * Find the sum of all the primes below two million.
 */

#include <bits/stdc++.h>
using namespace std;

const int bound = 2e6;
const int size = 2e6+5;
int prime[size];
int vis[size];
int cnt = 0;
long long ans = 0;

void sieve_of_euler() {
    for(int i = 2; i <= bound; ++i) {
        if(!vis[i]) {
            prime[cnt++] = i;
            ans += i;
        }
        for(int j = 0; j<cnt && i*prime[j]<=bound; ++j) {
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve_of_euler();
    cout << ans << endl;
    return 0;
}