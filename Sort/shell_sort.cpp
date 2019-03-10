#include <algorithm>
#include "decla.h"

void shell_sort(int nums[], int len) {
     for(int gap = len/2; gap > 0; gap /= 2) {
         for(int i = gap; i < len; i++) {
             for(int j = i-gap; j >= 0; j-=gap) {
                 if(nums[j] > nums[i]) {
                    std::swap(nums[i],nums[j]);
                }
            }
        }
    }
}