
#include <iostream>

void ChangeNumber(int Number)
{
	Number = 500;
}

void ChangeNumber(int* NumberAddr)
{
	*NumberAddr = 500;
}

struct FPlayerInfo
{
	char	Name[32] = {};
	int		Attack = 0;
};

void main()
{
	/*
	������ : �޸� �ּҸ� �����ϱ� ���� ���� Ÿ���̴�.
	��� ���� Ÿ���� ������ Ÿ�� ������ ������ �� �ִ�.

	����Ÿ��* �����ͺ����̸�;

	���� ���·� ������ ������ ������ �� �ִ�.

	������Ÿ���� �޸� ũ��� x64�� �� 8����Ʈ x86�� �� 4����Ʈ�̴�.

	������ : ������ ������ ������ �ִ� �޸� �ּҿ� �����Ͽ� �ش� �ּҿ� �ִ� ����
	�����ϰų� �����ͼ� ����� �� �ְ� ���ش�.
	*�����ͺ����� = 100;
	
	���� ���� �����ͺ����� �տ� * �� �ٿ� �������� �Ѵ�.

	����Ÿ�Կ� ������ �޾� �ش� Ÿ�� ������ �޸� �ּҸ� ������ �� �ְ� �ȴ�.
	��, void�� Ÿ���� ���ٴ� �ǹ��ε� �Ϲ� voidŸ�� ������ ������ �Ұ���������
	void* Ÿ�� ������ ������ �����Ͽ� ��� ���� Ÿ���� �޸� �ּҸ� ������ �� �ִ�.
	��, void*�� �������� �Ұ����ϴ�.
	*/
	float	Number1 = 3.14f;
	int		Number = 100;
	int* Address = nullptr;
	bool	Test1 = true;
	bool* Address1 = &Test1;

	//*Address = 200;

	Address = &Number;

	// Address�� Number������ �޸� �ּҸ� ������ �ֱ� ������ �� �ּҿ� �����Ͽ�
	// ���� 1234�� �����Ѵ�. ��, Number������ ���� 1234�� ����� ���̴�.
	*Address = 1234;

	ChangeNumber(Number);
	ChangeNumber(&Number);

	// float Ÿ�� ������ �ּҸ� int* Ÿ�Կ� �������ֱ� ������ ������ �߻��Ѵ�.
	//Address = &Number1;
	// �Ʒ��� ���� ����ȯ�� �ϸ� �����ϴ�.
	//Address = (int*)&Number1;

	void* VoidAddress = &Number;
	VoidAddress = &Number1;
	VoidAddress = &Test1;

	//*VoidAddress = true;
	// �Ʒ��� void*�� �ӽ÷� bool*�� ��ȯ���� �νĽ����ֱ� ������ �������� �����ϴ�.
	*((bool*)VoidAddress) = true;

	printf("Number = %d\n", Number);

	// ���� �տ� & �� �ٿ��ָ� �ش� ������ �޸� �ּҸ� �ǹ��Ѵ�.
	// %x : 16���� ���. %8x : 16���� 8�ڸ� ���
	// %p : �޸� �ּ� ���
	printf("&Number = %p\n", &Number);
	printf("Address = %p\n", Address);
	printf("Address1 = %p\n", Address1);
	printf("*Address = %d\n", *Address);

	/*
	�����Ϳ� �迭�� ����
	�迭 �̸��� �迭�� ���� �޸� �ּҸ� �ǹ��Ѵ�.
	*/
	int	Array[100] = {};

	printf("%p\n", Array);

	// �迭 �̸��� �迭�� ���� �޸� �ּ��̱� ������ ������ ������
	// �ش� �迭�� ���� �޸� �ּҸ� ������ ���� �ִ�.
	int* ArrayAddress = Array;

	// �迭�̸�[�ε���] �� �����ϴ°��� �迭�����ּ�[�ε���]�� ����.
	Array[3] = 500;

	// �����ͺ����� �迭�� ���� �޸� �ּҸ� ������ �ֱ� ������ �ε�����
	// �̿��Ͽ� �迭�� ������ �� �ִ�.
	ArrayAddress[3] = 1111;

	printf("Array[3] = %d\n", Array[3]);

	/*
	������ ���� : +, -, ++, -- 4������ �����ȴ�.
	������ ������ �Ϲ����� ����� �ٸ��� ����ȴ�.
	1�� ���ϸ� �ܼ��ϰ� �޸� �ּҿ� 1�� ���ϴ� ���� �ƴ϶� �����ͺ��� Ÿ����
	�޸� ũ�⸸ŭ�� �����ְ� �ȴ�.
	2�� ���ϸ� 2 * Ÿ��ũ�� ��ŭ�� �ּҿ� �����ְ� �Ǵ� ���̴�.
	*/
	printf("Array = %p\n", Array);
	printf("&Array[0] = %p\n", &Array[0]);
	printf("ArrayAddress = %p\n", ArrayAddress);
	printf("ArrayAddress + 1 = %p\n", ArrayAddress + 1);
	printf("ArrayAddress + 3 = %p\n", ArrayAddress + 3);
	printf("&Array[3] = %p\n", &Array[3]);

	printf("*(ArrayAddress + 3) = %d\n", *(ArrayAddress + 3));
	printf("*ArrayAddress + 3 = %d\n", *ArrayAddress + 3);
	printf("Array[3] = %d\n", Array[3]);

	printf("%p\n", ArrayAddress);

	*++ArrayAddress = 500;

	printf("Array[0] = %d\n", Array[0]);
	printf("Array[1] = %d\n", Array[1]);

	printf("%p\n", ArrayAddress);

	/*printf("%p\n", ArrayAddress);
	printf("++ %p\n", ++ArrayAddress);
	printf("++ %p\n", ArrayAddress++);
	printf("%p\n", ArrayAddress);*/

	double	Test2 = 0.13;
	double* Test2Addr = &Test2;
	printf("Test2Addr = %p\n", Test2Addr);
	printf("Test2Addr + 1 = %p\n", Test2Addr + 1);

	/*
	������ ������ const Ű���带 �̿��Ͽ� ����� ���� �� �ִ�.
	const int* Addr : �����ϴ� �޸� �ּҴ� ������ ���������� ��������
	�Ͽ� ���� �ٲٴ� ���� �Ұ����ϴ�.
	int* const Addr : ó�� ����� ���ÿ� �޸� �ּ��� ���Ը� �����ϰ�
	�� ���Ŀ��� �ٸ� �޸� �ּҸ� ������ �� ����.
	const int* const Addr : �����ϴ� ��� ������ �� ���� �����ϴ� �����
	���� ������ �� ����.
	*/
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