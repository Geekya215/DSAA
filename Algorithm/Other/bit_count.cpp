#include <bits/stdc++.h>
using namespace std;

int normal(int number) {
  int ans = 0;
  while(number) {
    ans += number & 1;
    number >>= 1;
  }
  return ans;
}

int ex_normal(int number) {
  int ans = 0;
  while(number) {
    ans++;
    number = number & (number - 1);
  }
  return ans;
}

int advance(int x) {
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x + (x >> 4)) & 0x0F0F0F0F;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x0000003F;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << normal(n) << endl;
  cout << ex_normal(n) << endl;
  cout << advance(n) << endl;
  return 0;
}
