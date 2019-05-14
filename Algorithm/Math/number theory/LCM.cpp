#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    int ta = a;
    int tb = b;
    while(a^=b^=a^=b%=a);
    return ta/b*tb;
}

int main() {
    int a,b;
    ios::sync_with_stdio(false);
   cin.tie(nullptr);
    cin >> a >> b;
    cout << lcm(a,b) << endl;
    return 0;
}