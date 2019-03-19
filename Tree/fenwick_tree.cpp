#include <bits/stdc++.h>

using namespace std;

const int m_size = 1e2+5; // max size of fenwick tree array
int fenwick_tree[m_size]; // fenwick tree array
int num[m_size]; // default array to get sum
int len; // length of the array


// for time optimize do not use function
int lowbit(int x) {
    return x&(-x);
}

void build() {
    int temp;
    for(int i = 1; i <= len; ++i) {
        temp = lowbit(i)-1;
        while(~temp) {
            fenwick_tree[i] += num[i-temp];
            --temp;
        }
    }
}

int sum(int index) {
    int sum = 0;
    for(int i = index; i > 0; i -= lowbit(i)) 
        sum += fenwick_tree[i];
    return sum;
}


int getSum(int left, int right) {
    return sum(right) - sum(left-1);
}

void update(int index, int value) {
    for(int i = index+1; i <= len; i += lowbit(i))
        fenwick_tree[i] += value;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> len;
    for(int i = 1; i <= len; ++i)
        num[i] = i;
    build();
    cout << sum(6) << endl;
    cout << getSum(2,4) << endl;
}