/** Problem 1
 *
 * [Titile]:
 * Multiples of 3 and 5
 *
 * [Description]:
 * If we list all the natural numbers below 10 that 
 * are multiples of 3 or 5, we get 3, 5, 6 and 9. The
 * sum of these multiples is 23.
 *
 * [Goal]:
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for(int i = 3; i < 1000; ++i) {
        if(i%3==0 || i%5==0)
            ans += i;
    }
    cout << ans << endl;
    return 0;
}


// Optimize Methods

/*

#include<bits/stdc++.h>
using namespace std;

long long tot = 1000 - 1;

long long factorSum(int n) {
    long long p = tot / n;
    return n * (p * (p+1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << factorSum(3) + factorSum(5) - factorSum(15) << endl;
    return 0;
}

*/