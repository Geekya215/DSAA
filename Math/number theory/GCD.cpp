#include <bits/stdc++.h>
using namespace std;

int gcd_recursive(int a, int b) {
    return b ? gcd_recursive(b,a%b) : a;
}

int gcd_loop(int a, int b) {
	while(b) {
		a^=b^=a^=b;
		b %= a;
	}
	return a;
}

int gcd_trick(int a, int b) {
    while(a^=b^=a^=b%=a);
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int a,b;
	cin >> a >> b;
//	cout << gcd_recursive(a,b) << endl;
//	cout << gcd_loop(a,b) << endl;
	cout << gcd_trick(a,b) << endl;
    return 0;
}