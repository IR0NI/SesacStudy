#include <iostream>
#include "Array.h"

struct FTest
{
	char Arr[1024];
};

int main()
{
	CArray<int> Arr1;

	for (int i = 0; i < 10; ++i)
	{
		Arr1.push_back(i + 1);
	}

	
	Arr1.push_back(10);
	return 0;
}