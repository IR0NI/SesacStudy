
#include <iostream>
#include <time.h>

void main()
{
	srand(time(0));
	rand();

	int	Number[25] = {};

	// ���� �迭�� 1 ~ 25 ���� ���ʴ�� �����Ѵ�.
	for (int i = 0; i < 25; ++i)
	{
		Number[i] = i + 1;
	}

	// 1 ~ 25 ������ ���ڸ� �����ش�.
	for (int i = 0; i < 100; ++i)
	{
		// 0 ~ 24 ������ ������ ���� ���´�.
		int	Index1 = rand() % 25;
		int	Index2 = rand() % 25;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	int	Input = 0;
	int	LineCount = 0;

	while (true)
	{
		// �ܼ� ȭ���� �ؽ�Ʈ�� ��� �����ش�.
		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (Number[i * 5 + j] == -1)
					printf("*\t");

				else
					printf("%d\t", Number[i * 5 + j]);
			}

			printf("\n");
		}

		printf("�ϼ��� �� : %d\n", LineCount);

		// 5�� �̻��� �ϼ��ߴٸ� ������ �����Ѵ�.
		if (LineCount >= 5)
		{
			break;
		}


		// ���ڸ� �Է¹޴´�.
		printf("���ڸ� �Է��ϼ���(0 : ����) : ");
		scanf_s("%d", &Input);

		if (Input == 0)
			break;

		else if (Input < 0 || Input > 25)
		{
			printf("�߸��� ���ڸ� �Է��Ͽ����ϴ�.\n");
			// pause�� �ܼ�ȭ���� �Ͻ����� �����ش�.
			system("pause");
			continue;
		}

		// �Է��� ���ڰ� �迭�� �ִ��� �Ǵ��ϱ� ���� ����.
		// �⺻���� ��ã�Ҵٴ� �ǹ̷� false�� �־�ΰ� ã���� ��� true�� �ٲ۴�.
		bool	Find = false;

		// ã���� ������ �ε����� �����ϱ� ���� ����.
		int	FindIndex = -1;

		// �Է��� ���ڰ� �迭�� �ִ��� ã�´�.
		for(int i = 0; i < 25; ++i)
		{
			// �Է��� ���ڰ� ���� �迭�� ���� ���
			if (Number[i] == Input)
			{
				// �ε����� �����Ѵ�.
				FindIndex = i;

				Find = true;
				// ���� -1�� ��� *�� ����Ѵ�.
				Number[i] = -1;
				// ���̻� ���� ���ڰ� ���� ������ �ݺ��� �����Ѵ�.
				break;
			}
		}

		// Find������ ���� true��� �迭���� ���� ã�Ҵٴ� �ǹ��̰� false���
		// �迭���� ���� ��ã�Ҵٴ� �ǹ̰� �ȴ�. ��ã���� ��� ó������ ���ư�
		// �ٽ� ����ϰ� �Է��� �ް� �Ѵ�.
		if (!Find) // Find == false
			continue;

		// �Է��� ���ڰ� ������ �� �� �ִ� ���� ���Ѵ�.
		// ����, ���δ� ������ üũ�ϰ� �밢�� 2�ٿ� ������ �� �� �ִ���
		// üũ.

		// ����, ���� üũ.
		// �����ε��� : �ε��� / ���ΰ���
		// �����ε��� : �ε��� % ���ΰ���
		int	IndexX = FindIndex % 5;
		int	IndexY = FindIndex / 5;

		int	StarCount = 0, StarCount1 = 0;

		// �� ���� ����ŭ �ݺ��Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			// �������� üũ�Ѵ�.
			if (Number[IndexY * 5 + i] == -1)
				++StarCount;

			// �������� üũ�Ѵ�.
			if (Number[i * 5 + IndexX] == -1)
				++StarCount1;
		}

		if (StarCount == 5)
			++LineCount;

		if (StarCount1 == 5)
			++LineCount;


		// �밢�� �ε��� : 0, 6, 12, 18, 24
		if (FindIndex % 6 == 0)
		{
			StarCount = 0;

			for (int i = 0; i <= 24; i += 6)
			{
				if (Number[i] == -1)
					++StarCount;
			}

			if (StarCount == 5)
				++LineCount;
		}

		// �밢�� �ε��� : 4, 8, 12, 16, 20
		if (FindIndex % 4 == 0 && FindIndex != 0 && FindIndex != 24)
		{
			StarCount = 0;

			for (int i = 4; i <= 20; i += 4)
			{
				if (Number[i] == -1)
					++StarCount;
			}

			if (StarCount == 5)
				++LineCount;
		}


		// 12���� ��� üũ�Ͽ� �ϼ��� ���� ���� ���Ѵ�.
		//LineCount = 0;

		//// *�� �ٲ� ���� �����ϱ� ���� ����.
		//int	StarCount = 0, StarCount1 = 0;

		//for (int i = 0; i < 5; ++i)
		//{
		//	// *�� �ٲ�� üũ�ϱ� ���� *�� ���� �����ϱ� ���� ������ 0����
		//	// �ʱ�ȭ�Ѵ�.
		//	StarCount = 0;
		//	StarCount1 = 0;

		//	// j for���� 5�� ���� ���� ���ڰ� ������� ���Ѵ�.
		//	for (int j = 0; j < 5; ++j)
		//	{
		//		// ���ڰ� *�� ��� StarCount�� ������Ų��.
		//		if (Number[i * 5 + j] == -1)
		//			++StarCount;

		//		// �������� üũ�Ѵ�.
		//		if (Number[j * 5 + i] == -1)
		//			++StarCount1;
		//	}

		//	// ������ ��� *�� �ٲ���� ��� �� ���� ���������ش�.
		//	if (StarCount == 5)
		//		++LineCount;

		//	if (StarCount1 == 5)
		//		++LineCount;
		//}

		//StarCount = 0;

		//// ���� ��� -> ������ �ϴ� �밢�� üũ
		//for (int i = 0; i <= 24; i += 6)
		//{
		//	if (Number[i] == -1)
		//		++StarCount;
		//}

		//if (StarCount == 5)
		//	++LineCount;

		//StarCount = 0;

		//// ������ ��� -> ���� �ϴ� �밢�� üũ
		//for (int i = 4; i <= 20; i += 4)
		//{
		//	if (Number[i] == -1)
		//		++StarCount;
		//}

		//if (StarCount == 5)
		//	++LineCount;
	}
}