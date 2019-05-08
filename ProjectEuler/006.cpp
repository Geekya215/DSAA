/** Problem 6
 *
 * [Titile]:
 * Sum square difference
 *
 * [Description]:
 * The sum of the squares of the first ten natural 
 * numbers is,1^2 + 2^2 + ... + 10^2 = 385 The square 
 * of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025. Hence the difference 
 * between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * [Goal]:
 * Find the difference between the sum of the squares of 
 * the first one hundred natural numbers and the square of the sum.
 */

#include <bits/stdc++.h>
using namespace std;

long long qs;
long long sq;
const int num = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    qs = num*(num+1)*(2*num+1)/6;
    sq = pow((num)*(num+1)>>1,2);
    cout << sq - qs << endl;
    return 0;
}