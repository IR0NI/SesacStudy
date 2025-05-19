#include <iostream>


template<typename T>
void Print(T a)
{
	printf("%d\n", a);
}



int main()
{
	Print(1);
	Print(2.1f);
}