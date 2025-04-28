#include <iostream>
#include "time.h"

void main()
{
	srand(time(0));
	rand();

	// 1- 45 ������ ���ڸ� ��Ƴ��� ���� ������ �����.
	int Number[45] = {};

	// 1-45 ������ ���� �����Ѵ�.

	for (int i = 0; i < 45; ++i)
	{
		Number[i] = i + 1;
	}
	// ���� ���� �Է¹޾Ƽ� ���� ����ŭ 6���� ������ ��ȣ�� �����.

	// 6���� ��÷��ȣ�� ���ʽ���ȣ 1���� �̸� �����д�
	int GameCount = 0;
	scanf_s("%d", &GameCount);
	
	for (int a = 0; a < GameCount; a++)
	{
		// ���ڸ� �����ش�.
		for (int i = 0; i < 100; ++i)
		{
			// ������ �ε��� 2���� �����ش�.
			int Index1 = rand() % 45;
			int Index2 = rand() % 45;

			// Temp�� Index1���� ���� �����Ѵ�.
			// Index1���� ���� Index2���� ������ �����Ѵ�.
			// �̸� �����ص� Index1���� ���� Index2 ���� ������ �����غд�.
			int Temp = Number[Index1];
			Number[Index1] = Number[Index2];
			Number[Index2] = Temp;
		}

		// 6���� ���ڸ� �����Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = i + 1; j < 6; ++j)
			{
				if (Number[i] > Number[j])
				{
					int Temp = Number[i];
					Number[i] = Number[j];
					Number[j] = Temp;
				}
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			// \t : Tab 1 ���ִ� ���̴�.
			printf("%d\t", Number[i]);
		}

		printf("\n");
	}
	
}