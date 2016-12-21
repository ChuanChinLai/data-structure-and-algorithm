#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include <general\Assert.h>
#include <data structure\linked list\linked list.h>
#include <data structure\stack\stack.h>
#include <data structure\queue\queue.h>

int main(int argc, const char *argv[])
{

//	List_UnitTest();
//	stack_UnitTest();

	queue_UnitTest();


	printf("Memory Leak? %d\n", _CrtDumpMemoryLeaks());

	system("pause");
	return 0;
}