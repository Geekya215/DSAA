#ifndef UTIL_H
#define UTIL_H

#define RANDOM_RANGE 100

#include <iostream>
#include <random>


void display(int nums[], int len) {
    for(int i = 0; i < len; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
}


void gen_random(int nums[], int len) {
    std::random_device rd;
    std::mt19937 mt_gen_random(rd());
    std::uniform_int_distribution<> r_dis(1,RANDOM_RANGE);
    for(int i = 0; i < len; ++i) {
        nums[i] = r_dis(mt_gen_random);
    }
}

#endif