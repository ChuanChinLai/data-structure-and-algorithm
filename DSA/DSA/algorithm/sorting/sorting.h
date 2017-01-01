#pragma once

extern void printf_array(const int* i_pArray, const size_t i_size);

extern void bubble_sort(int* i_pArray, const size_t i_size);

extern void selection_sort(int* i_pArray, const size_t i_size);

extern void insertion_sort(int* i_pArray, const size_t i_size);

extern void merge_sort(int* i_pArray, const size_t lower_index, const size_t upper_index);
extern void merge(int* i_pArray, int lower_index, int mid_index, int upper_index);

extern void heap_sort(int* i_pArray, const size_t i_size);

extern void quick_sort(int* i_pArray, int index_L, int index_R);
extern int partition(int* i_pArray, int index_L, int index_R, int i_pivot);

extern void Sort_UnitTest();
