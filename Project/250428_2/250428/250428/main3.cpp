
#include <iostream>
#include <time.h>

/*
1 ~ 25 ������ ���ڸ� �����ϱ� ���� �迭 25��¥���� �����.
1 ~ 25 ������ ���ڸ� ���� �����ش�.
while���� �̿��Ͽ� ���ѷ����� ���� 5x5�� ����ϰ� ���ڸ� �Է¹޴´�.
�Է¹��� ���ڰ� 0�̶�� ������ �����ϰ� 1 ~ 25 ������ ���ڶ�� �ش� ���ڸ�
ã�Ƽ� *�� ����Ѵ�.
������ ��� *�� �ٲ�� �� ī��Ʈ�� �����Ѵ�.
���� 5��, ���� 5��, �밢�� 2�ٿ� ���� �ϼ��� ���� üũ�Ͽ� 5�� �̻��̸�
������ �����Ѵ�.
*/

void main()
{
	srand(time(0));
	rand();

	// 1 ~ 10 ���� ���ڸ� 2���� ������ �ִ� 20�� ¥�� �迭�� �����
	// �����ش�.
	int	Number[20] = {};
	bool	Open[20] = {};

	for (int i = 0; i < 10; ++i)
	{
		Number[i] = i + 1;
		Number[i + 10] = i + 1;
	}

	// ���ڸ� �����ش�.
	for (int i = 0; i < 100; ++i)
	{
		// ������ �ε��� 2���� �����ش�.
		int	Index1 = rand() % 20;
		int	Index2 = rand() % 20;

		// Temp�� Index1���� ���� �����Ѵ�.
		// Index1���� ���� Index2���� ������ �����Ѵ�.
		// �̸� �����ص� Index1���� ���� Index2���� ������ �������ش�.
		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	int	PrevOpenIndex = -1;

	while (true)
	{
		// �迭�� ���ڸ� ���� 10��, ���� 2�ٷ� ����Ѵ�.
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (Open[i * 10 + j])
					printf("%d\t", Number[i * 10 + j]);

				else
					printf("*\t");
			}
			printf("\n");
		}

		// ���ڸ� 0 ~ 20 ������ ���ڸ� �Է¹޴´�.
		// �Է¹��� ���ڰ� 20�� ��� break�� �̿��ؼ� while���� ����������.
		int	Input = 0;
		printf("���ڸ� �Է��ϼ���(20 : ����) : ");
		scanf_s("%d", &Input);

		if (Input == 20)
			break;

		// 0 ~ 19 ������ ���� �ƴ� ��� �ٽ� ����ϰ� �Է¹ް� �Ѵ�.
		else if (Input < 0 || Input > 19)
			continue;

		// �̹� ���µǾ� �ִ� ī���� �ٽ� �Է¹ް� �Ѵ�.
		if (Open[Input])
			continue;

		Open[Input] = true;
		// ī�� 2���� �����ϸ� 2���� ī�尡 ���� ���� ������ ���Ͽ� ���� ���̸�
		// ��� ���µ� ���¸� �����ϰ� �ٸ� ���̸� �� ī�带 Ŭ���� ���·�
		// ������ش�.
		// PrevOpenIndex �� -1�̶�� ù��° ī�带 �����ϴ� ���̴�.
		if (PrevOpenIndex == -1)
		{
			PrevOpenIndex = Input;
			continue;
		}

		// 2��° ī�带 �����ϸ� ���� ���� ���Ѵ�.
		if (Number[PrevOpenIndex] != Number[Input])
		{
			Open[PrevOpenIndex] = false;
			Open[Input] = false;
		}

		PrevOpenIndex = -1;
	}
}