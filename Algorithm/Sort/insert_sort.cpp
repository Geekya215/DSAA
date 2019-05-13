#include "decla.h"

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