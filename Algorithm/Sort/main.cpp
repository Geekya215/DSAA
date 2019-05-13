#include <iostream>
#include "decla.h"
#include "util.h"

int main() {
    int arr[10];
    gen_random(arr,10);
    display(arr,10);
    heap_sort(arr,10);
    display(arr,10);
    return 0;
}