/*
 * @Author: geekya215 
 * @Date: 2019-03-09 20:16:07 
 * @Last Modified by: geekya215
 * @Last Modified time: 2019-03-09 20:16:52
 */
#include <bits/stdc++.h>

using namespace std;

void shell_sort(int nums[], int len) {
     for(int gap = len/2; gap > 0; gap /= 2) {
         for(int i = gap; i < len; i++) {
             for(int j = i-gap; j >= 0; j-=gap) {
                 if(nums[j] > nums[i]) {
                     swap(nums[i],nums[j]);
                }
            }
        }
    }
}

int main() {
    int nums[6] = {91,7,33,1,4,2};
    shell_sort(nums,6);
    for(int n:nums)
        cout << n << ' ';
    cout << endl;
    return 0;
}