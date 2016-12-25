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
