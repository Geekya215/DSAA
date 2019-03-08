/*
 * @Author: geekya215 
 * @Date: 2019-03-08 23:37:52 
 * @Last Modified by: geekya215
 * @Last Modified time: 2019-03-08 23:39:01
 */


#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int nums[], int len) {
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len-i-1; ++j) {
	        if(nums[j] > nums[j+1]) {
		        swap(nums[j],nums[j+1]);
	        }
        }
    }
}

int main() {
    int nums[5] = {7,4,11,3,1};
    bubble_sort(nums,5);
    for(int i = 0; i < 5; ++i)
        cout << nums[i] << ' ';
    return 0;
}