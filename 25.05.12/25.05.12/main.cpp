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
���ø� : �������� Ÿ���� ������ �� ����Ѵ�.
������ �ð��� Ÿ���� �����Ǹ� ������ Ÿ������ �ڵ带 ������ش�.
templete <typename ���ϴ��̸�>
templete <class ���ϴ� �̸�> �� ���·� �����.
templete <typename T, typename T1> �̷� ���°� �ȴ�.
T�� T1�� Ÿ���� �ȴ�.


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
	// �Ϲ� ����Լ� �����ʹ� &Ŭ������::�Լ��� ���� �ؾ� �Ѵ�.
	void(CTest:: * Func1)() = &CTest::Output;

	//����Լ� ������ ȣ����
	// (��ü.*����Լ�������)(����); �� ���·� ȣ���Ѵ�.
	(ctest.*Func1)();

	OutputTemplate<int>(10);
	OutputTemplate<float>(1.1f);
	OutputTemplateFunc<void(*)()>(Output);

	std::function<void(int, float)> func3;
	//1������ : �Լ� �ּ�
	//2������ ���ʹ� �ּҸ� �־��ִ� �Լ��� ���ڸ� � ������
	// ȣ���������� �����Ѵ�.
	func3 = std::bind(OutputFunctional, std::placeholders::_1, std::placeholders::_2);
	func3(10, 3.14f);

	std::function<void()> func2;
	// 1������ : �Լ� �ּ�
	// 2������ : ��ü
	// 3�����ں��ʹ� ����.
	func2 = std::bind(&CTest::Output, ctest);

	return 0;
}