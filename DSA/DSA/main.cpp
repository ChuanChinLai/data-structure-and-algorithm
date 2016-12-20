#include<stdio.h>
#include<stdlib.h>
#include<general\Assert.h>

int main(int argc, const char *argv[])
{
	printf("Hello World\n");

	int a = -10;

	DEBUG_PRINT("a is %d", a);
	ASSERT(a > 0);

	system("pause");
	return 0;
}