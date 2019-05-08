/** Problem 5
 *
 * [Titile]:
 * Smallest multiple
 *
 * [Description]:
 * 2520 is the smallest number that can be divided by 
 * each of the numbers from 1 to 10 without any remainder.
 *
 * [Goal]:
 * What is the smallest positive number that is evenly 
 * divisible by all of the numbers from 1 to 20?
 */

#include <bits/stdc++.h>
using namespace std;

long long ans = 1;

long long gcd(long long a, long long b) {
    while(a^=b^=a^=b%=a);
    return b;
}

long long lcm(long long a, long long b) {
    return a/gcd(a,b)*b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a,b;
    for(int i = 2; i <= 20; ++i) {
        ans = lcm(ans,i);
    }
    cout << ans << endl;
    return 0;
}