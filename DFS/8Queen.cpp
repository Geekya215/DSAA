#include <iostream>
using namespace std;

const int size = 1e2+5;
int a[size];
int len;
int ans = 0;

int check(int n) {
    for(int i = n-1; i > 0; --i) {
        if(a[n]==a[i] || abs(a[n]-a[i])==n-i)
            return 0;
    }
    return 1;
}

void dfs(int n) {
    if(n == len+1) {
        ans++;
        return ;
    }

    for(int i = 1; i <= len; ++i) {
        a[n] = i;
        if(check(n))
            dfs(n+1);
    }
}

int main() {
    cin >> len;
    dfs(1);
    cout << ans << endl;
    return 0;
}