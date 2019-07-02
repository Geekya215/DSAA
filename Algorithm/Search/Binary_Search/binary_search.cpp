#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& nums, int target) {
    int first = 0;
    int last = nums.size();
    int mid;
    int cnt = 0;
    // range => (first, last] 
    while(first < last) {
        // mid = (first + last) / 2; normal version, overflow bug
        // mid = first + (last - first) / 2; // bug fix version
        mid = (first & last) + ((first^last) >> 1); // best efficient and no overflow bug
	    if(nums[mid] < target) first = mid + 1;
	    else last = mid;
        cnt++;
    }
    cout << "cnt:" << cnt << endl;
    return last;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {1,3,9,12,32,41,45,62,75,77,82,95,100};
    int n;
    while(cin >> n,  ~n) cout << binary_search(arr,n) << endl;
    return 0;
}
