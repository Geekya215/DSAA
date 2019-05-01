#include <bits/stdc++.h>
using namespace std;

const int size = 1e2+5;

int prime[size];
int vis[size];
int cnt = 0;
int n;

void sieve_of_euler(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!vis[i])
            prime[cnt++] = i;
        for(int j = 0; j<cnt && i*prime[j]<=n; ++j) {
            vis[i*prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    sieve_of_euler(n);
    for(int i = 0; i < cnt; ++i)
        cout << prime[i] << endl;
    return 0;
}