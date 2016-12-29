#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include <general\Assert.h>
#include <data structure\linked list\linked list.h>
#include <data structure\stack\stack.h>
#include <data structure\queue\queue.h>
#include <data structure\hash table\hash_table.h>
#include <data structure\tree\binary_tree.h>

#include <algorithm\recursion\recursion.h>
#include <algorithm\sorting\sorting.h>
#include <general\math\math.h>

int main(int argc, const char *argv[])
{

//	List_UnitTest();
//	stack_UnitTest();
//	queue_UnitTest();

//	HashTable<int> hashTable(20);
//	binarytree_UnitTest();

	int array[10] = {80, 64, 99, 76, 5, 5, 28, 80, 1, 3};

//	bubble_sort(array, 10);
//	selection_sort(array, 10);
//	insertion_sort(array, 10);
//	printf_array(array, 10);
//	merge_sort(array, 0, 10-1);

	heap_sort(array, 10);


	printf("Memory Leak? %d\n", _CrtDumpMemoryLeaks());

	system("pause");
	return 0;
}