#ifndef DECLA_H
#define DECLA_H

void bubble_sort(int nums[], int len);

void insert_sort(int nums[], int len);

void select_sort(int nums[], int len);

void shell_sort(int nums[], int len);

void quick_sort(int nums[], int low, int higt);

void merge_sort(int nums[], int left, int right);

void merge(int nums[], int left, int mid, int right);

void heap_sort(int nums[], int len);

void heapify(int nums[], int len, int i);
#endif