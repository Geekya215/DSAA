/** Problem 2
 *
 * [Titile]:
 * Even Fibonacci numbers
 *
 * [Description]:
 * Each new term in the Fibonacci sequence is 
 * generated by adding the previous two terms.
 * By starting with 1 and 2, the first 10 terms
 * will be:1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ....
 *
 * [Goal]:
 * By considering the terms in the Fibonacci 
 * sequence whose values do not exceed four million, 
 * find the sum of the even-valued terms.
 */

#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int f1,f2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f1 = 1;
    f2 = 2;
    while(f2 <= 4000000) {
        if(f2%2 == 0)
            ans += f2;
        f2+=f1^=f2^=f1^=f2;
    }
    cout << ans << endl;
    return 0;
}

