/** Problem 9
 *
 * [Title]:
 * Special Pythagorean triplet
 *
 * [Description]:
 * A Pythagorean triplet is a set of three natural numbers, 
 * a < b < c, for which,a2 + b2 = c2. For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * [Goal]:
 * There exists exactly one Pythagorean triplet for 
 * which a + b + c = 1000.Find the product abc.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i <= 1000; ++i) {
        int temp = 1000-i;
        for(int j = 0; j <= temp; ++j) {
            int k = temp - j;
            if(i*i + j*j == k*k) {
                cout << i*j*k << endl;
                return 0;
            }
        }
    }
    return 0;
}