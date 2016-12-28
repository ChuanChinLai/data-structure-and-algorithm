#include "..\sorting.h"
#include "general\Assert.h"

void printf_array(const int * i_pArray, const size_t i_size)
{
	for (size_t i = 0; i < i_size; i++)
	{
		printf("%d", i_pArray[i]);

		if (i != i_size - 1)
			printf("->");
		else
			printf("\n");
	}
}

void bubble_sort(int * i_pArray, const size_t i_size)
{
	ASSERT(i_pArray);
	ASSERT(i_size > 0);

	for (size_t i = 0; i < i_size; i++)
	{
		for (size_t j = i + 1; j < i_size; j++)
		{
			if (i_pArray[i] > i_pArray[j])
			{
				int tmp = i_pArray[j];
				i_pArray[j] = i_pArray[i];
				i_pArray[i] = tmp;
			}
		}
	}
	printf_array(i_pArray, i_size);
	return;
}

void selection_sort(int * i_pArray, const size_t i_size)
{
	ASSERT(i_pArray);
	ASSERT(i_size > 0);

	for (size_t i = 0; i < i_size; i++)
	{
		int index_min = i;

		for (size_t j = i + 1; j < i_size; j++)
		{
			if (i_pArray[j] < i_pArray[index_min])
				index_min = j;
		}

		if (i_pArray[i] > i_pArray[index_min])
		{
			int tmp = i_pArray[i];
			i_pArray[i] = i_pArray[index_min];
			i_pArray[index_min] = tmp;
		}
	}

	printf_array(i_pArray, i_size);
	return;
}

void insertion_sort(int * i_pArray, const size_t i_size)
{
	ASSERT(i_pArray);
	ASSERT(i_size > 0);

	for (size_t i = 1; i < i_size; i++)
	{
		size_t index = i;

		int tmp = i_pArray[i];

		while (index > 0 && i_pArray[index - 1] > tmp)
		{
			i_pArray[index] = i_pArray[index - 1];
			index--;
		}

		i_pArray[index] = tmp;
	}
	printf_array(i_pArray, i_size);
	return;
}

void merge_sort(int * i_pArray, const size_t lower_index, const size_t upper_index)
{
	ASSERT(i_pArray);

	if (lower_index == upper_index)
		return;

	int mid_index = (lower_index + upper_index) / 2;

	merge_sort(i_pArray, lower_index, mid_index);
	merge_sort(i_pArray, mid_index + 1, upper_index);

	merge(i_pArray, lower_index, mid_index, upper_index);
}

void merge(int * i_pArray, int lower_index, int mid_index, int upper_index)
{
	const int size_L = mid_index - lower_index + 1;
	const int size_R = upper_index - mid_index;
	
	int* tmpArray_L = new int[size_L];
	int* tmpArray_R = new int[size_R];

	for (size_t i = 0; i < size_L; i++)
	{
		tmpArray_L[i] = i_pArray[lower_index + i];
	}

	for (size_t i = 0; i < size_R; i++)
	{
		tmpArray_R[i] = i_pArray[mid_index + 1 + i];
	}

	
	int index_L = 0;
	int index_R = 0;
	int index_merge = lower_index;

	while (index_L < size_L && index_R < size_R)
	{
		if (tmpArray_L[index_L] <= tmpArray_R[index_R])
		{
			i_pArray[index_merge] = tmpArray_L[index_L];
			index_L++;
		}
		else
		{
			i_pArray[index_merge] = tmpArray_R[index_R];
			index_R++;
		}
		index_merge++;
	}

	while (index_L < size_L)
	{
		i_pArray[index_merge] = tmpArray_L[index_L];
		index_L++;
		index_merge++;
	}

	while (index_R < size_R)
	{
		i_pArray[index_merge] = tmpArray_R[index_R];
		index_R++;
		index_merge++;
	}

	delete[] tmpArray_L;
	delete[] tmpArray_R;
}
