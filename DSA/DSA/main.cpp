#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <algorithm>

#include <general\Assert.h>
#include <data structure\linked list\linked list.h>
#include <data structure\stack\stack.h>
#include <data structure\queue\queue.h>
#include <data structure\graph\graph.h>

#include <data structure\hash table\hash_table.h>
#include <data structure\tree\binary_tree.h>

#include <algorithm\recursion\recursion.h>
#include <algorithm\sorting\sorting.h>
#include <general\math\math.h>

int main(int argc, const char *argv[])
{

//	List_UnitTest();
//	stack_UnitTest();
	queue_UnitTest();
//	Hash_Table_UnitTest();
//	HashTable<int> hashTable(20);
//	binarytree_UnitTest();

	int array[10] = {80, 64, 99, 76, 5, 5, 28, 80, 1, 3};
//	int array[10] = { 80, 3, 3, 3, 3, 3, 3, 3, 1, 3 };

//	bubble_sort(array, 10);
//	selection_sort(array, 10);
//	insertion_sort(array, 10);
//	printf_array(array, 10);
//	merge_sort(array, 0, 10-1);

//	heap_sort(array, 10);
//	printf_array(array, 10);

//	printf_array(array, 10);
//	quick_sort(array, 0, 10 - 1);
//	printf_array(array, 10);
//	Sort_UnitTest();

	/*
	Graph graph(5);

	graph.addEdge(1, 0);
	graph.addEdge(0, 2);
	graph.addEdge(2, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 4);
	graph.DFS(0);
	graph.destroy();
	*/

	printf("Memory Leak? %d\n", _CrtDumpMemoryLeaks());

	system("pause");
	return 0;
}