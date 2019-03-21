#include <bits/stdc++.h>

using namespace std;

const int size = 1e2+5;
int seg[size];
int len;
int n;


// normal version
void build() {
    for(n = 1; n <= len; n <<= 1);

    for(int i = n + 1; i <= n + len; ++i)
        cin >> seg[i];

    for(int i = n - 1; i; --i)
        seg[i] = seg[i<<1] + seg[i<<1|1];
}


void update(int i, int v) {
    for(i += n; i; i >>= 1)
        seg[i] += v;
}


int sum(int l, int r) {
    int sum = 0;

    for(l += n-1, r += n+1; l^r^1; l >>= 1, r >>= 1) {
        if(~l&1)
            sum += seg[l^1];
        if(r&1)
            sum += seg[r^1];
    }
    return sum;
}


// difference version

/*
void build() {
    for(n = 1; n <= len; n <<= 1);

    for(int i = n + 1; i <= n + len; ++i)
        cin >> seg[i];

    for(int i = n - 1; i; --i) {
        seg[i] = min(seg[i<<1], seg[i<<1|1]);
        seg[i<<1] -= seg[i];
        seg[i<<1|1] -= seg[i];
    }
}

*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> len;
    build();
    cout << sum(1,4) << endl;
    update(1,10);
    cout << sum(1,4) << endl;
    return 0;
}