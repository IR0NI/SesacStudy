
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
	void OutputTest()
	{
		printf("CTest::OutputTest Function\n");
	}

	void OutputTest1()
	{
		printf("CTest::OutputTest1 Function\n");
	}

	static void OutputTestStatic()
	{
		printf("CTest::OutputTestStatic Function\n");
	}
};

void Output()
{
	printf("Output Function\n");
}

struct FTestFunc
{
	void(CTest::* Func1)();
	CTest* Object;
};

void OutputNumber(int Number)
{
	printf("Number = %d\n", Number);
}

void OutputNumber(float Number)
{
	printf("Number = %d\n", Number);
}

/*
템플릿 : 가변적인 타입을 대응할 때 사용한다.
컴파일 시간에 타입이 결정되며 결정된 타입으로 코드를 만들어준다.
template <typename 원하는이름>
template <class 원하는이름> 의 형태로 만든다.
template <typename T, typename T1>  이런 형태가 된다.
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

template <typename T, typename F>
void OutputObject(T* Obj, F Func)
{
	(Obj->*Func)();
}

void OutputFunctional(int Number, float Number2)
{
	std::cout << Number << ", " << Number2 << std::endl;
	//printf("Number = %d, Number2 = %.f\n", Number, Number2);
}

int main()
{
	Output();
	CTest::OutputTestStatic();

	CTest	test, test1, test2;

	test.OutputTest();
	test.OutputTestStatic();

	void (*Func)();

	Func = Output;

	Func();

	Func = CTest::OutputTestStatic;

	Func();

	//Func = CTest::OutputTest;
	// 일반 멤버함수 포인터는 &클래스명::함수명 으로 해야 한다.
	void(CTest::*Func1)() = &CTest::OutputTest;

	// 멤버함수 포인터 호출 방법
	// (객체.*멤버함수포인터)(인장); 의 형태로 호출한다.
	(test.*Func1)();

	(test1.*Func1)();

	//std::function
	OutputTemplate<int>(10);
	OutputTemplate<float>(3.14f);

	OutputTemplateFunc<void(*)()>(Output);

	OutputObject<CTest, void(CTest::*)()>(&test,
		&CTest::OutputTest);

	std::function<void(int, float)>	func3;
	// 1번인자 : 함수 주소
	// 2번인자 부터는 주소를 넣어주는 함수의 인자를 어떤 순서로
	// 호출해줄지를 결정한다.
	func3 = std::bind(OutputFunctional, std::placeholders::_1,
		std::placeholders::_2);

	func3(10, 3.14f);

	func3 = std::bind(OutputFunctional, std::placeholders::_2,
		std::placeholders::_1);

	func3(10, 3.14f);

	std::function<void()>	func2;
	// 1번인자 : 함수 주소
	// 2번인자 : 객체
	// 3번인자부터는 같다.
	func2 = std::bind(&CTest::OutputTest, test);
	func2();

	func2 = std::bind(&CTest::OutputTest1, test);
	func2();

	// 람다 : 익명함수.
	// auto : 대입받는 값의 타입으로 자동으로 타입이 결정된다.
	auto	Num = 10;
	auto	Num1 = 3.14f;

	auto	func4 = []()
		{
			printf("Func4 람다\n");
		};

	func4();

	auto	func5 = [](int Num)
		{
			printf("Func5 람다 : %d\n", Num);
		};

	func5(500);

	auto	func6 = [](int Num1, int Num2) -> int
		{
			return Num1 + Num2;
		};

	printf("%d\n", func6(30, 40));

	int	Num3 = 10, Num4 = 20;

	// 외부 변수 캡처 방식.
	auto	func7 = [Num3, Num4]()
		{
			return Num3 + Num4;
		};

	printf("Func7 = %d\n", func7());

	auto	func8 = [&Num3, &Num4]()
		{
			++Num3;
			++Num4;
			return Num3 + Num4;
		};

	printf("Num3 = %d, Num4 = %d\n", Num3, Num4);
	printf("Func8 = %d\n", func8());

	std::function<void()>	func9 = []()
		{
			printf("Test Func9\n");
		};

	func9();

	return 0;
}
