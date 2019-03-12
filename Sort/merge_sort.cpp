#include <algorithm>
#include "decla.h"

void merge(int nums[], int left, int mid, int right) {
    int* temp = new int[right-left+1];
    int i = left;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j <= right) {
        if(nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while(i <= mid) 
        temp[k++] = nums[i++];
    while(j <= right)
        temp[k++] = nums[j++];
    
    for(i = left, k = 0; i<=right; ++i,++k)
        nums[i] = temp[k];
    
    delete[] temp;
}


void merge_sort(int nums[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left+right) >> 1;
        merge_sort(nums,left,mid);
        merge_sort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}