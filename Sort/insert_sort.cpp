/*
 * @Author: geekya215 
 * @Date: 2019-03-09 18:17:43 
 * @Last Modified by:   geekya215 
 * @Last Modified time: 2019-03-09 18:17:43 
 */
#include <bits/stdc++.h>

using namespace std;

void insert_sort(int nums[],int len) {

    for(int i = 0; i < len; ++i) {
        int temp = nums[i];
        int pos = i;

        while(pos>0 && nums[pos-1]>temp) {
            nums[pos] = nums[pos-1];
            pos--;
        }
        
        nums[pos] = temp;
    }
}

int main() {
    int nums[6] = {2,9,1,7,4,3};
    insert_sort(nums,6);
    for(int i = 0; i < 6; ++i)
        cout << nums[i] << ' ';
    return 0;
}