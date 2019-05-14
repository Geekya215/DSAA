#include <bits/stdc++.h>
using namespace std;

const int size = 1e2+5;

int prime[size];
int vis[size];
int n;

void sieve_of_eratosthenes(int n) {
    for(int i = 2; i*i <= n; ++i) {
        if(!vis[i]) {
            for(int j = 2*i; j <= n; j += i)
                vis[j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    sieve_of_eratosthenes(n);
    for(int i = 2; i <= n; ++i) {
        if(!vis[i])
            cout << i << endl;
    }
    return 0;
}