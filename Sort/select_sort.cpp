/*
 * @Author: geekya215 
 * @Date: 2019-03-08 23:52:32 
 * @Last Modified by: geekya215
 * @Last Modified time: 2019-03-08 23:53:23
 */
#include <bits/stdc++.h>

using namespace std;

void select_sort(int nums[], int len) {
    int min_index;
    for(int i = 0; i < len-1; ++i) {
        min_index = i;
        for(int j = i+1; j < len; ++j) {
            if(nums[min_index] > nums[j]) {
                min_index = j;
            }
        }
        swap(nums[min_index],nums[i]);
    }
}

int main() {
    int nums[6] = {9,23,55,8,49,2};
    select_sort(nums,6);
    for(int i = 0; i < 6; ++i)
        cout << nums[i] << ' ';
    return 0;
}