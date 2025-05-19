#include <iostream>
#include <functional>

class CTest
{
public:
	CTest()
	{

	}

	~CTest()
	{

	}

public:
	void Output()
	{
		printf("Output\n");
	}

	static void OutputTestStatic()
	{
		printf("CTest::OutputTestStatic\n");
	}

};

void Output()
{
	printf("Output1\n");
}

/*
템플릿 : 가변적인 타입을 대응할 때 사용한다.
컴파일 시간에 타입이 결정되며 결정된 타입으로 코드를 만들어준다.
templete <typename 원하는이름>
templete <class 원하는 이름> 의 형태로 만든다.
templete <typename T, typename T1> 이런 형태가 된다.
T와 T1은 타입이 된다.


*/

template <typename T>
void OutputTemplate(T Num)
{
	std::cout << Num << std::endl;
}

template <typename T>
void OutputTemplateFunc(T Func)
{
	Func();
}

template<typename T, typename F>
void OutputObject(T* Obj, F Func)
{
	(Obj->*Func)();
}

void OutputFunctional(int Number, float Number2)
{
	std::cout << Number << "," << Number2 << std::endl;
}

int main()
{
	CTest ctest,ctest1;
	CTest::OutputTestStatic();

	Output();
	ctest.Output();

	void (*Func)();

	Func = Output;

	Func();

	Func = CTest::OutputTestStatic;

	Func();

	//Func = CTest::OutputTest;
	// 일반 멤버함수 포인터는 &클래스명::함수명 으로 해야 한다.
	void(CTest:: * Func1)() = &CTest::Output;

	//멤버함수 포인터 호출방법
	// (객체.*멤버함수포인터)(인자); 의 형태로 호출한다.
	(ctest.*Func1)();

	OutputTemplate<int>(10);
	OutputTemplate<float>(1.1f);
	OutputTemplateFunc<void(*)()>(Output);

	std::function<void(int, float)> func3;
	//1번인자 : 함수 주소
	//2번인자 부터는 주소를 넣어주는 함수의 인자를 어떤 순서로
	// 호출해줄지를 결정한다.
	func3 = std::bind(OutputFunctional, std::placeholders::_1, std::placeholders::_2);
	func3(10, 3.14f);

	std::function<void()> func2;
	// 1번인자 : 함수 주소
	// 2번인자 : 객체
	// 3번인자부터는 같다.
	func2 = std::bind(&CTest::Output, ctest);

	return 0;
}