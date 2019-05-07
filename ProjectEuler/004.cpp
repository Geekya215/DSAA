/** Problem 4
 *
 * [Titile]:
 * Largest palindrome product
 *
 * [Description]:
 * A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of 
 * two 2-digit numbers is 9009 = 91 × 99.
 *
 * [Goal]:
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */


#include <bits/stdc++.h>
using namespace std;

pair<int,int> p;

int check(int num) {
    int p1 = num / 1000;
    int temp = num % 1000;
    int p2 = temp%10*100+temp/100+temp/10%10*10;
    return p1 == p2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = -1;
    for(int i = 999; i >= 100; --i) {
        for(int j = i; j >= 100; --j) {
            if(i*j < 10000) break;
            if(check(i*j)) {
            	if(i*j > ans) {
            		ans = i*j;
            		p = make_pair(i,j);
            	}
            }
        }
    }
    cout << ans << endl;
    cout << p.first << endl;
    cout << p.second << endl;
    return 0;
}