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

bool Binary_Search(const int i_data, int * i_pArray, int index_L, int index_R)
{
	ASSERT(i_pArray != nullptr)

	int index_M = (index_L + index_R) / 2;
	if (i_pArray[index_M] == i_data)
		return true;
	else if (index_L > index_R)
		return false;
	else
	{
		if (i_pArray[index_M] < i_data)
			Binary_Search(i_data, i_pArray, index_M + 1, index_R);
		else
			Binary_Search(i_data, i_pArray, index_L, index_M - 1);
	}
}
