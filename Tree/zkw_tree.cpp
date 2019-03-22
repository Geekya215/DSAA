#include <bits/stdc++.h>

using namespace std;

const int size = 1e2+5;
int seg[size];
int len;
int n;


// normal version
/*
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


int query(int l, int r) {
    int sum = 0;

    for(l += n-1, r += n+1; l^r^1; l >>= 1, r >>= 1) {
        if(~l&1)
            sum += seg[l^1];
        if(r&1)
            sum += seg[r^1];
    }
    return sum;
}
*/


// difference version

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


void update(int l, int r, int v) {
    int temp;

    for(l += n-1, r += n+1; l^r^1; l >>= 1, r >>= 1) {
        if(~l&1)
            seg[l^1] += v;
        if(r&1)
            seg[r^1] += v;
        
        temp = min(seg[l],seg[l^1]);
        seg[l] -= temp;
        seg[l^1] -= temp, seg[l>>1] += temp;

        temp = min(seg[r],seg[r^1]);
        seg[r] -= temp;
        seg[r^1] -= temp, seg[r>>1] += temp;

    }

    for(; l != 1; l >>= 1) {
        temp = min(seg[l],seg[l^1]);
        seg[l] -= temp;
        seg[l^1] -= temp, seg[l>>1] += temp;
    }
}


int query(int l, int r) {
    int lsum = 0;
    int rsum = 0;
    l += n;
    r += n;
    if(l != r) {
        for(; l^r^1; l >>= 1, r >>= 1) {
            lsum += seg[l];
            rsum += seg[r];
            if(~l&1)
                lsum = min(lsum, seg[l^1]);
            if(r&1)
                rsum = min(rsum, seg[r^1]);
        }
    }

    int sum = min(lsum + seg[l], rsum + seg[r]);

    while(l > 1)
        sum += seg[l >>= 1];
    
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> len;
    build();
    cout << query(1,4) << endl;
    update(1,4,1);
    cout << query(1,4) << endl;
    for(int i = 1; i <= n+len; ++i)
        printf("seg[%d]:%d\n",i,seg[i]);
    return 0;
}