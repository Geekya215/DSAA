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
    for(int i = 3; i <= 1000; i += 3) ans += i;
    for(int i = 5; i <= 1000; i += 5) ans += i;
    cout << ans << endl;
    return 0;
}