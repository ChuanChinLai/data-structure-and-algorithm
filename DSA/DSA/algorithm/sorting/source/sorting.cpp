#include <algorithm>
#include <algorithm\sorting\sorting.h>
#include <algorithm\recursion\recursion.h>
#include <data structure\heap\heap.h>
#include <general\Assert.h>
#include <ctime>

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

void Sort_UnitTest()
{
	const size_t times = 1024 * 32;
	size_t index = 0;

	std::vector<int> keyBase;
	
	int* pArray_1 = new int[times];
	int* pArray_2 = new int[times];
	int* pArray_3 = new int[times];
	int* pArray_4 = new int[times];
	int* pArray_5 = new int[times];
	int* pArray_6 = new int[times];

	for (size_t i = 0; i < times; i++)
	{
		int key = rand() % times;

		pArray_1[i] = key;
		pArray_2[i] = key;
		pArray_3[i] = key;
		pArray_4[i] = key;
		pArray_5[i] = key;
		pArray_6[i] = key;

		keyBase.push_back(key);
	}

	std::clock_t start;

	start = std::clock();
	printf("C++ STL Sorting...\n");
	std::sort(keyBase.begin(), keyBase.end());
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
	
	start = std::clock();
	printf("Bubble Sorting...\n");
	bubble_sort(pArray_1, times);
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

	
	start = std::clock();
	printf("Selection Sorting...\n");
	selection_sort(pArray_2, times);
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

	start = std::clock();
	printf("Insertion Sorting...\n");
	insertion_sort(pArray_3, times);
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

	start = std::clock();
	printf("Merge Sorting...\n");
	merge_sort(pArray_4, 0, times -1);
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

	start = std::clock();
	printf("Heap Sorting...\n");
	heap_sort(pArray_5, times);
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
	
	start = std::clock();
	printf("Quick Sorting...\n");
	quick_sort(pArray_6, 0, times - 1);
	printf("Used Time: %2.f ms\n", (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
	
	for (size_t i = 0; i < times; i++)
	{
		int search_key = keyBase.at(static_cast<int>(rand() % keyBase.size()));
		bool success = Binary_Search(search_key, pArray_1, 0, times - 1);
		ASSERT(success == true);

		ASSERT(keyBase.at(i) == pArray_1[i]);
		ASSERT(keyBase.at(i) == pArray_2[i]);
		ASSERT(keyBase.at(i) == pArray_3[i]);
		ASSERT(keyBase.at(i) == pArray_4[i]);
		ASSERT(keyBase.at(i) == pArray_5[i]);
		ASSERT(keyBase.at(i) == pArray_6[i]);
	}

	
	delete[] pArray_1;
	delete[] pArray_2;
	delete[] pArray_3;
	delete[] pArray_4;
	delete[] pArray_5;
	delete[] pArray_6;
	return;
}

void bubble_sort(int * i_pArray, const size_t i_size)
{
	ASSERT(i_pArray);

	for (size_t i = 0; i < i_size; i++)
	{
		for (size_t j = i + 1; j < i_size; j++)
		{
			if (i_pArray[i] > i_pArray[j])
				std::swap(i_pArray[i], i_pArray[j]);
		}
	}

}

void selection_sort(int * i_pArray, const size_t i_size)
{
	ASSERT(i_pArray);

	for (size_t i = 0; i < i_size; i++)
	{
		int min_index = i;

		for (size_t j = i + 1; j < i_size; j++)
		{
			if (i_pArray[min_index] >= i_pArray[j])
				min_index = j;
		}
		if(i_pArray[i] > i_pArray[min_index])
			std::swap(i_pArray[i], i_pArray[min_index]);
	}
}

void insertion_sort(int * i_pArray, const size_t i_size)
{
	ASSERT(i_pArray);

	for (size_t i = 1; i < i_size; i++)
	{
		int tmp = i_pArray[i];
		int index = i;

		while (index > 0 && i_pArray[index - 1] > tmp)
		{
			i_pArray[index] = i_pArray[index - 1];
			index--;
		}
		i_pArray[index] = tmp;
	}
}

void heap_sort(int * i_pArray, const size_t i_size)
{
	Heap heap;

	for (size_t i = 0; i < i_size; i++)
	{
		heap._push(i_pArray[i]);
	}

	for (int i = i_size - 1; i >= 0; i--)
	{
		i_pArray[i] = heap._peek();
		heap._pop();
	}
	//	printf_array(i_pArray, i_size);
}

void merge_sort(int * i_pArray, const size_t lower_index, const size_t upper_index)
{
	ASSERT(i_pArray);

	if (lower_index >= upper_index)
		return;

	int mid = (lower_index + upper_index) / 2;

	merge_sort(i_pArray, lower_index, mid);
	merge_sort(i_pArray, mid + 1, upper_index);

	merge(i_pArray, lower_index, mid, upper_index);
}

void merge(int * i_pArray, int lower_index, int mid_index, int upper_index)
{
	int size_L = mid_index - lower_index + 1;
	int size_R = upper_index - mid_index;

	int* array_L = new int[size_L];
	int* array_R = new int[size_R];

	for (size_t i = 0; i < size_L; i++)
		array_L[i] = i_pArray[lower_index + i];

	for (size_t i = 0; i < size_R; i++)
		array_R[i] = i_pArray[mid_index + 1 + i];

	int index_L = 0;
	int index_R = 0;
	int current_index = lower_index;

	while (index_L < size_L && index_R < size_R)
	{
		if (array_L[index_L] <= array_R[index_R])
		{
			i_pArray[current_index] = array_L[index_L];
			index_L++;
		}
		else
		{
			i_pArray[current_index] = array_R[index_R];
			index_R++;
		}
		current_index++;
	}


	while (index_L < size_L)
	{
		i_pArray[current_index] = array_L[index_L];
		index_L++;
		current_index++;
	}

	while (index_R < size_R)
	{
		i_pArray[current_index] = array_R[index_R];
		index_R++;
		current_index++;
	}

	delete[] array_L;
	delete[] array_R;
}

void quick_sort(int * i_pArray, int index_L, int index_R)
{
	ASSERT(i_pArray);
	if (index_L >= index_R)
		return;
	
	int mid = partition(i_pArray, index_L, index_R, i_pArray[index_R]);

	quick_sort(i_pArray, index_L, mid - 1);
	quick_sort(i_pArray, mid + 1, index_R);
}

int partition(int * i_pArray, int index_L, int index_R, int i_pivot)
{
	int current_L = index_L;
	int current_R = index_R - 1;

	while (1)
	{
		while (i_pArray[current_L] < i_pivot)
		{
			current_L++;
		}

		while (current_R > 0 && i_pArray[current_R] >= i_pivot)
		{
			current_R--;
		}

		if (current_L >= current_R)
			break;


		if (i_pArray[current_L] > i_pArray[current_R])
			std::swap(i_pArray[current_L], i_pArray[current_R]);
	}

	std::swap(i_pArray[current_L], i_pArray[index_R]);
	return current_L;
}

