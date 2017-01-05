#include <algorithm>
#include <algorithm\sorting\sorting.h>
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
	const size_t times = 1024 * 128;
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
		int key = rand() % 50;

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
	printf("C++ Sorting...\n");
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
