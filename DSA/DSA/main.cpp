#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include <general\Assert.h>
#include <data structure\linked list\linked list.h>

int main(int argc, const char *argv[])
{
	printf("Hello World\n");

//	int a = -10;
//	DEBUG_PRINT("a is %d", a);
//	ASSERT(a > 0);

	List_UnitTest();
	/*
	LinkedList list;

	list.inseret_node(1);
	list.inseret_node(1);
	list.inseret_node(4);
	list.inseret_node(5);
	list.inseret_node(3);
	list.inseret_node(1);
	list.inseret_node(2);

	list.display();

	list.reverse();
	list.display();
	list.destroy();
	list.display();


	list.display();
	list.delete_node(1);
	list.delete_node(2);
	list.delete_node(1);
	list.delete_node(1);
	list.delete_node(3);
	list.delete_node(4);
	list.delete_node(5);
	list.display();
	*/

	printf("Memory Leak? %d\n", _CrtDumpMemoryLeaks());

	system("pause");
	return 0;
}