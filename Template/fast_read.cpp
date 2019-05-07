#include <iostream>
using namespace std;

#define gcu getchar_unlocked

long long read() {
    long long res = 0;
    bool neg = false;
    char c;

    neg = (c = gcu()) == '-';

    if(!neg) {
        res = (res << 3) + (res << 1) + c-'0';
    }

    while((c = gcu()), c >= '0' && c <= '9') {
        res = (res << 3) + (res << 1) + c-'0';
    }
    return neg?-res:res;
}

int main() {
    long long ans = read();
    cout << ans << endl;
    return 0;
}