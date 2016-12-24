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
#include <general\math\math.h>

int main(int argc, const char *argv[])
{

//	List_UnitTest();
//	stack_UnitTest();
//	queue_UnitTest();

//	HashTable<int> hashTable(20);

	BinaryTree binaryTree;

	binaryTree._push(20);
	binaryTree._push(10);
	binaryTree._push(12);
	binaryTree._push(27);
	binaryTree._push(9);
	binaryTree._push(50);
	binaryTree._push(33);
	binaryTree._push(6);
	binaryTree._delete(27);

	binaryTree._display_PreOrder();

	printf("Memory Leak? %d\n", _CrtDumpMemoryLeaks());

	system("pause");
	return 0;
}