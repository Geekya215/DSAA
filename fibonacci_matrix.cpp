#include <bits/stdc++.h>

using namespace std;

struct matrix {
    int m[2][2];

    matrix() {
        memset(m,0,sizeof(m));
    }

    friend matrix operator*(const matrix& a, const matrix& b) {
        matrix res;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                for(int k = 0; k < 2; ++k) {
                    res.m[i][j] = res.m[i][j] + a.m[i][k]*b.m[k][j];
                }
            }
        }
        return res;
    }
};

long long fib_matrix(int exp) {
    matrix ans;
    ans.m[0][0] = 1;
    ans.m[1][1] = 1;
    matrix base;
    base.m[0][0] = 1;
    base.m[0][1] = 1;
    base.m[1][0] = 1;
    base.m[1][1] = 0;
    while(exp) {
        if(exp&1) {
            ans = ans*base;
        }
        base = base*base;
        exp >>= 1;
    }
    return ans.m[1][0];
}

int main() {
    int n;
    while(cin>>n,~n) {
        cout << fib_matrix(n) << endl;
    }
}