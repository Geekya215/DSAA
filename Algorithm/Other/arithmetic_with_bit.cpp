#include <bits/stdc++.h>
using namespace std;

int add_recursive(int a, int b) {
  int _xor = a ^ b;
  int forward = (a & b) << 1;
  return forward ? add_recursive(_xor, forward) : _xor;
}

int add_loop(int a, int b) {
  int _xor = a ^ b;
  int forward = (a & b) << 1;
  while(forward) {
    int t1 = _xor;
    int t2 = forward;
    _xor = t1 ^ t2;
    forward = (t1 & t2) << 1;
  }
  return _xor;
}

int negtive(int num) {
  return add_loop(~num, 1);
}

int _minus(int a, int b) {
  return add_loop(a, negtive(b));
}

int main() {
  int x = 12, y = 3;
  cout << _minus(x, y) << endl;
  cout << add_loop(x, -3) << endl;
  return 0;
}
