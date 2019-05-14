#include <bits/stdc++.h>
using namespace std;

long long euler(int n) {
    long long res = n;
    long long a = n;
    for(int i = 2; i*i <= a; ++i) {
        if(a%i == 0) {
            res = res / i * (i-1);
            while(a%i == 0)
                a /= i;
        }
    }
    if(a > 1)
        res = res / a * (a-1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i <= 100; ++i) {
        cout << i << ' ' << euler(i) << endl;
    }
}