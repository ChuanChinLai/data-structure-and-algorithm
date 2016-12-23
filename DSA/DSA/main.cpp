#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include <general\Assert.h>
#include <data structure\linked list\linked list.h>
#include <data structure\stack\stack.h>
#include <data structure\queue\queue.h>
#include <data structure\hash table\hash_table.h>

#include <algorithm\recursion\recursion.h>
#include <general\math\math.h>

int main(int argc, const char *argv[])
{

//	List_UnitTest();
//	stack_UnitTest();
//	queue_UnitTest();

	HashTable<int> hashTable(20);
	int item = 0;

	item = 348;
	hashTable._insert(112, item);
	item = 841; 
	hashTable._insert(87, item);

	
	if (hashTable._find(87, &item))
		std::cout << "Item: 87 has a value of " << item << "." << std::endl;
	else
		std::cout << "87 Not Found" << std::endl;

	if (hashTable._find(112, &item))
		std::cout << "Item: 112 has a value of " << item << "." << std::endl;
	else
		std::cout << "112 Not Found" << item << "." << std::endl;


	printf("Memory Leak? %d\n", _CrtDumpMemoryLeaks());

	system("pause");
	return 0;
}