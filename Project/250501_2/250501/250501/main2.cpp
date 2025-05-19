
#include <iostream>

/*
함수포인터 : 함수는 코드영역에 저장된다.
함수주소는 코드 영역에 저장된 메모리 주소를 의미한다.
함수포인터는 이런 함수 주소를 저장할 수 있는 변수 타입이다.
함수 타입은 반환타입, 인자에 영향을 받는다.
반환타입이나 인자가 다르면 다른 타입으로 인식한다.
*/
int Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}

int Minus(int Num1, int Num2)
{
	return Num1 - Num2;
}

void TestOutput()
{
	printf("TestOutput Function\n");
}
void TestOutput1()
{
	printf("TestOutput1 Function\n");
}

void OutputNumber(int Num1)
{
	printf("Num1 = %d\n", Num1);
}


int main()
{
	/*
	함수포인터 선언방법
	반환타입 (*포인터변수명)(인자타입들); 의 형태로 선언한다.

	함수 이름은 함수 주소이다.
	*/
	int (*Func1)(int, int) = nullptr;
	void (*Func2)() = nullptr;
	void (*Func3)(int) = nullptr;
	// 함수포인터도 배열 선언이 가능하다.
	int (*Func1Array[10])(int, int) = {};

	Func1 = Sum;
	Func1 = Minus;

	Func1Array[0] = Sum;
	Func1Array[1] = Minus;

	for (int i = 0; i < 2; ++i)
	{
		printf("Func1 Result = %d\n", Func1Array[i](10, 20));
	}

	// 함수의 호출은 함수주소(인자 전달) 의 형태로 호출된다는 것이다.
	//printf("Func1 Result = %d\n", Func1(10, 20));

	printf("Size = %d\n", sizeof(Func1));
	// 함수포인터 변수 이름만 빼면 타입이 된다.
	printf("Size = %d\n", sizeof(int(*)(int, int)));

	printf("Addr = %p\n", Sum);
	printf("Addr = %p\n", Minus);
	printf("Addr = %p\n", TestOutput);
	printf("Addr = %p\n", TestOutput1);
	printf("Addr = %p\n", OutputNumber);

	return 0;
}