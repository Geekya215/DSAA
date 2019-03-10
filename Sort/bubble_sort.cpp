#include <algorithm>
#include "decla.h"

void bubble_sort(int nums[], int len) {
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len-i-1; ++j) {
	        if(nums[j] > nums[j+1]) {
		        std::swap(nums[j],nums[j+1]);
	        }
        }
    }
}