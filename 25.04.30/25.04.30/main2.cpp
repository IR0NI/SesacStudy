#include <iostream>

struct FPlayerInfo
{
	char	Name[32] = {};
	int		Attack = 0;
};

void ChangeNumber(float* Number)
{
	*Number = 5.01f;
}

void main()
{

	///*
	//������ : �޸� �ּҸ� �����ϱ� ���� ���� Ÿ���̴�.
	//��� ���� Ÿ���� ������ Ÿ�� ������ ������ �� �ִ�.
	//����Ÿ��* �����ͺ����̸�;
	//
	//���� ���·� ������ ������ ������ �� �ִ�.

	//������Ÿ���� �޸� ũ��� x64�� �� 8����Ʈ x86�� �� 4����Ʈ�̴�.

	//������ : ������ ������ ������ �ִ� �޸� �ּҿ� �����Ͽ� �ش� �ּҿ� �ִ� ���� �����ϰų� �����ͼ�
	//����� �� �ְ� ���ش�.
	//*�����ͺ����� = 100;
	//
	//���� ���� �����ͺ����� �տ� * �� �ٿ� �������� �Ѵ�.


	//����Ÿ�Կ� ������ �޾� �ش� Ÿ�� ������ �޸� �ּҸ� ������ �� �ְ� �ȴ�.
	//��, void�� Ÿ���� ���ٴ� �ǹ��ε� �Ϲ� void Ÿ�� ������ ������ �Ұ���������
	//void* Ÿ�� ������ ������ �����Ͽ� ��� ���� Ÿ���� �޸� �ּҸ� ������ �� �ִ�.
	//��, void*�� �������� �Ұ����ϴ�
	//*/
	//float Number = 100.1f;
	//float* Address = nullptr;

	//printf("Number : %5f\n", Number);
	//Address = &Number;
	//*Address = 10.1f;
	//printf("Number : %f\n", Number);
	//ChangeNumber(&Number);
	//printf("Number : %f\n", Number);

	//bool Test = true;
	//bool* Address1 = &Test;
	//void* VoidAddress = &Number;
	//VoidAddress = &Number;
	//VoidAddress = &Test;
	//*((bool*)VoidAddress) = true;

	//printf("Test : %d\n", Test);

	//printf("&Number : %p\n", &Number);
	//printf("*Address : %f\n", *Address);

	//int Array[100] = {};
	///*printf("%p\n", Array);*/
	//int* ArrayAddress = Array;
	//Array[3] = 500;
	///*printf("Array[3] : %d\n", Array[3]);*/
	//ArrayAddress[3] = 1000;
	///*printf("Array[3] : %d\n", Array[3]);*/
	///*printf("ArrayAddress[3] : %d\n", ArrayAddress[3]);*/
	//printf("Array = %p\n", Array);
	//printf("&Array[0] = %p\n", &Array[0]);
	//printf("ArrayAddress = %p\n", ArrayAddress);
	//printf("ArrayAddress + 1 = %p\n", ArrayAddress + 1);
	//printf("ArrayAddress + 3 = %p\n", ArrayAddress + 3);
	//printf("&Array[3] = %p\n", &Array[3]);

	//printf("*(ArrayAddress + 3) = %d\n", *(ArrayAddress + 3));
	//printf("*ArrayAddress + 3 = %d\n", *ArrayAddress + 3);
	//printf("Array[3] = %d\n", Array[3]);

	//printf("%p\n", ArrayAddress);

	//*++ArrayAddress = 500;

	//printf("Array[0] = %d\n", Array[0]);
	//printf("Array[1] = %d\n", Array[1]);

	//printf("%p\n", ArrayAddress);

	//printf("%p\n", ArrayAddress);
	//printf("++ %p\n", ++ArrayAddress);
	//printf("++ %p\n", ArrayAddress--);
	//printf("%p\n", ArrayAddress);

	//int a = 10;
	//printf("a : %d\n", a);
	//printf("++a : %d\n", ++a);
	//printf("a+10 : %d\n", a+10);
	//printf("a : %d\n", a);

	//double	Test2 = 0.13;
	//double* Test2Addr = &Test2;
	//printf("Test2Addr = %p\n", Test2Addr);
	//printf("Test2Addr + 1 = %p\n", Test2Addr + 1);
	/*
	������ ������ const Ű���带 �̿��Ͽ� ����� ���� �� �ִ�.
	const int* Addr : �����ϴ� �޸� �ּҴ� ������ ���������� ��������
	�Ͽ� ���� �ٲٴ� ���� �Ұ����ϴ�.
	int* const Addr : ó�� ����� ���ÿ� �޸� �ּ��� ���Ը� �����ϰ�
	�� ���Ŀ��� �ٸ� �޸� �ּҸ� ������ �� ����.
	const int* const Addr : �����ϴ� ��� ������ �� ���� �����ϴ� �����
	���� ������ �� ����.
	*/
	int Number = 500;

	const int* cAddr = &Number;

	int		Number22 = 300;

	cAddr = &Number22;

	Number = *cAddr;

	//*cAddr = 2222;

	int* const	Addrc = &Number;

	//Addrc = &Number22;

	FPlayerInfo	Player;
	FPlayerInfo* PlayerAddr = &Player;

	Player.Attack = 500;

	//*PlayerAddr.Attack = 600;
	(*PlayerAddr).Attack = 600;

	// ���� ���� �����Ѵ�. -> �� ������ ������ ������ �ִ� �ּҿ� �����Ͽ�
	// ��������� ����� �� �ְ� ���ش�.
	PlayerAddr->Attack = 600;
}