#include "..\recursion.h"
#include <general\Assert.h>

int n_Factorial(const int i_data)
{
	ASSERT(i_data > 0);

	if (i_data > 1)
		return i_data * n_Factorial(i_data - 1);
	else
		return 1;
}

int n_Fibonacci(const int i_data)
{
	if (i_data == 0)
		return 0;
	else if (i_data == 1)
		return 1;
	else
		return n_Fibonacci(i_data - 1) + n_Fibonacci(i_data - 2);
}
