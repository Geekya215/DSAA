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


// method 1
/*

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

*/

// method 2

#include <bits/stdc++.h>
using namespace std;

const long long num = 600851475143;
const int temp = 775146;
const int size = temp + 5;

int prime[size];
int vis[size];
int cnt = 0;

void sieve_of_euler() {
    for(int i = 2; i <= temp; ++i) {
        if(!vis[i])
            prime[cnt++] = i;
        for(int j = 1; j<cnt && i*prime[j]<=temp; ++j) {
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
    for(int i = cnt-1; ; --i) {
        if(num%prime[i] == 0) {
            cout << prime[i] << endl;
            return 0;
        }
    }
    return 0;
}