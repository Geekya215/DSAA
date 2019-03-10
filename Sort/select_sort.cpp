#include <algorithm>
#include "decla.h"

void select_sort(int nums[], int len) {
    int min_index;
    for(int i = 0; i < len-1; ++i) {
        min_index = i;
        for(int j = i+1; j < len; ++j) {
            if(nums[min_index] > nums[j]) {
                min_index = j;
            }
        }
        std::swap(nums[min_index],nums[i]);
    }
}
