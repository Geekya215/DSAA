#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const double base = 1.0;

double sqrt(double n) {
    double a = base;
    double b = (a + n / a) / 2;

    while(fabs(a-b) >= eps) {
	    a = b;
	    b = (a + n / a) / 2;
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    printf("%.8lf",sqrt(2));
    return 0;
}
