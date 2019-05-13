#include <algorithm>
#include "decla.h"

int partition(int nums[], int low, int high) {
	int pivot = nums[high];
	int temp = low-1;

	for(int i = low; i <= high-1; ++i) {
		if(nums[i] <= pivot) {
			temp++;
			std::swap(nums[temp],nums[i]);
		}
	}
	std::swap(nums[temp+1],nums[high]);
	return temp+1;
}

void quick_sort(int nums[], int low, int high) {
	if(low < high) {
		int pi = partition(nums,low,high);

		quick_sort(nums,low,pi-1);
		quick_sort(nums,pi+1,high);
	}
}