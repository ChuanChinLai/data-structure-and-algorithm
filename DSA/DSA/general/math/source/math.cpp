#include "..\math.h"

bool IsPrimeNumber(const int i_number)
{
	for (size_t i = 2; i * i <= i_number; i++)
	{
		if (i_number % i == 0)
			return false;
	}
	return true;
}

int GetNextPrimeNumber(const int i_number)
{
	for (size_t i = i_number + 1; ; i++)
	{
		if (IsPrimeNumber(i))
			return i;
	}
}
