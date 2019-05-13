#include <algorithm>
#include "decla.h"

void heap_sort(int nums[], int len) {
    for(int i = len/2-1; i >= 0; --i)
        heapify(nums,len,i);

    for(int i = len-1; i >= 0; --i) {
        std::swap(nums[0],nums[i]);
        heapify(nums,i,0);
    }
}

void heapify(int nums[], int len, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < len && nums[l] > nums[largest])
        largest = l;
    
    if(r < len && nums[r] > nums[largest])
        largest = r;

    if(largest != i) {
        std::swap(nums[i],nums[largest]);
        heapify(nums,len,largest);
    }
}