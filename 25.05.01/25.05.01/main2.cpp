
#include <iostream>

/*
�Լ������� : �Լ��� �ڵ念���� ����ȴ�.
�Լ��ּҴ� �ڵ� ������ ����� �޸� �ּҸ� �ǹ��Ѵ�.
�Լ������ʹ� �̷� �Լ� �ּҸ� ������ �� �ִ� ���� Ÿ���̴�.
�Լ� Ÿ���� ��ȯŸ��, ���ڿ� ������ �޴´�.
��ȯŸ���̳� ���ڰ� �ٸ��� �ٸ� Ÿ������ �ν��Ѵ�.
*/
int Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}

int Minus(int Num1, int Num2)
{
	return Num1 - Num2;
}

float ChangeNum(float Num)
{

	return 10.1f;
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
	�Լ������� ������
	��ȯŸ�� (*�����ͺ�����)(����Ÿ�Ե�); �� ���·� �����Ѵ�.

	�Լ� �̸��� �Լ� �ּ��̴�.
	*/
	int (*Func1)(int, int) = nullptr;
	void (*Func2)() = nullptr;
	void (*Func3)(int) = nullptr;
	float (*Func4)(float) = nullptr;
	// �Լ������͵� �迭 ������ �����ϴ�.
	int (*Func1Array[10])(int, int) = {};
	float (*Func2Array[5])(float) = {};

	Func1 = Sum;
	Func1 = Minus;
	Func4 = ChangeNum;

	Func1Array[0] = Sum;
	Func1Array[1] = Minus;
	Func2Array[0] = ChangeNum;
	Func2Array[1] = ChangeNum;
	for (int i = 0; i < 2; ++i)
	{
		printf("Func1 Result = %d\n", Func1Array[i](10, 20));
		printf("Func2 Result = %f\n", Func2Array[i](50.1f));
	}

	// �Լ��� ȣ���� �Լ��ּ�(���� ����) �� ���·� ȣ��ȴٴ� ���̴�.
	//printf("Func1 Result = %d\n", Func1(10, 20));

	printf("Size = %d\n", sizeof(Func1));
	// �Լ������� ���� �̸��� ���� Ÿ���� �ȴ�.
	printf("Size = %d\n", sizeof(int(*)(int, int)));

	printf("Addr = %p\n", Sum);
	printf("Addr = %p\n", Minus);
	printf("Addr = %p\n", TestOutput);
	printf("Addr = %p\n", TestOutput1);
	printf("Addr = %p\n", OutputNumber);

	return 0;
}