#include <bits/stdc++.h>

typedef long long ll;

ll fast_pow(int num, int exp) {
    ll ans = 1;
    ll base = num;

    while(exp != 0) {
        if(exp & 1) {
            ans *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return ans;
}

int main() {
    std::cout << fast_pow(2,20) << std::endl;
    return 0;
}