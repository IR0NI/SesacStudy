
#include <iostream>
#include <time.h>

/*
�Լ� : �ڵ带 ��Ƽ� ���ϴ� �κп��� ȣ���Ͽ� ���۽�ų �� �ְ� ���ִ� ����̴�.

��ȯŸ�� �Լ��̸�(����)
{
	������ �ڵ�
}

��ȯŸ�� : �� �Լ��� �ڵ带 ���۽�Ű�� ����� ������ �� ��� �����ϴ� Ÿ���̴�.
���� Ÿ���� �ۼ��ϸ� void�� �ۼ��ϸ� ��ȯŸ���� ���ٴ� �ǹ��̴�.

���� : �� �Լ��� ���(ȣ��)�� �� �Լ����� �ڵ带 ���۽�Ű�� ���� �ʿ��� �����Ͱ� ����
��� �����͸� �������ֱ� ���� �����̴�. ���� ���� �ְ� ������ Ȥ�� 1���� ���� �ִ�.

*/
void OutputFunction()
{
	printf("Output Function\n");
}

int Sum(int Number, int Number1)
{
	// return : �Լ��� �������� �� ����Ѵ�. ��ȯŸ���� �ִ� �Լ���� return �ڿ�
	// �� �Լ��� ��ȯ�� ����� �־��ش�.
	// ��ȯŸ���� void��� return; �� ���� ��� �Լ��� ��� �κп����� �Լ��� ȣ��
	// �� ��ġ�� �ǵ��ư� �� �ִ�.
	return Number + Number1;
}

// �Լ����� �ڵ尡 ��� ����ǰ� �Լ��� ���� ���ų� return�� ������ �Ǹ� �Լ��� ������
// �Լ����� ����� �޸𸮴� ��� �����ȴ�.
void ChangeNumber(int Number)
{
	int	Number1 = 200;
	Number = 500;
}

void SetNumber(int Num[25])
{
	for (int i = 0; i < 25; ++i)
	{
		Num[i] = i + 1;
	}
}

void OutputNumber(int Num[25])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d\t", Num[i * 5 + j]);
		}

		printf("\n");
	}
}

void main()
{
	srand(time(0));
	rand();

	int	Number[25] = {};

	// �迭 ��ü�� �����ϴ� ��� �迭 �̸��� �ۼ��Ѵ�.
	SetNumber(Number);

	OutputNumber(Number);
	OutputNumber(Number);
	OutputNumber(Number);

	// �Լ�ȣ�� : �Լ��̸�(���ڿ� �������� ��); �� ���·� ȣ���Ѵ�.
	OutputFunction();
	OutputFunction();
	OutputFunction();

	int	Num = Sum(10, 20);

	printf("Num = %d\n", Num);

	ChangeNumber(Num);

	printf("Num = %d\n", Num);
}
