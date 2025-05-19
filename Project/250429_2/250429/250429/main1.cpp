
#include <iostream>
#include <time.h>

void main()
{
	srand(time(0));
	rand();

	int	Number[25] = {};

	// AI�� ����� ���� �迭�� �����.
	int	AINumber[25] = {};

	// ���� �迭�� 1 ~ 25 ���� ���ʴ�� �����Ѵ�.
	for (int i = 0; i < 25; ++i)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
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

		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = AINumber[Index1];
		AINumber[Index1] = AINumber[Index2];
		AINumber[Index2] = Temp;
	}

	int	Input = 0;
	int	LineCount = 0, AILineCount = 0;

	while (true)
	{
		// �ܼ� ȭ���� �ؽ�Ʈ�� ��� �����ش�.
		system("cls");

		// �÷��̾� ���� ���
		printf("================== Player ==================\n");
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

		// AI ���
		printf("================== AI ==================\n");
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (AINumber[i * 5 + j] == -1)
					printf("*\t");

				else
					printf("%d\t", AINumber[i * 5 + j]);
			}

			printf("\n");
		}

		printf("�ϼ��� �� : %d\n", AILineCount);

		// 5�� �̻��� �ϼ��ߴٸ� ������ �����Ѵ�.
		if (LineCount >= 5)
		{
			printf("�÷��̾� �¸�\n");
			break;
		}

		else if (AILineCount >= 5)
		{
			printf("AI �¸�\n");
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
		int	FindIndex = -1, AIFindIndex = -1;

		// �Է��� ���ڰ� �迭�� �ִ��� ã�´�.
		for (int i = 0; i < 25; ++i)
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

		// AI�� ���ڿ��� �Է��� ���ڸ� ã�� *�� �����.
		for (int i = 0; i < 25; ++i)
		{
			if (AINumber[i] == Input)
			{
				AIFindIndex = i;
				AINumber[i] = -1;
				break;
			}
		}



		// �Է��� ���ڰ� ������ �� �� �ִ� ���� ���Ѵ�.
		// ����, ���δ� ������ üũ�ϰ� �밢�� 2�ٿ� ������ �� �� �ִ���
		// üũ.

		// ����, ���� üũ.
		// �����ε��� : �ε��� / ���ΰ���
		// �����ε��� : �ε��� % ���ΰ���
		int	IndexX = FindIndex % 5;
		int	IndexY = FindIndex / 5;
		int	AIIndexX = AIFindIndex % 5;
		int	AIIndexY = AIFindIndex / 5;

		int	StarCount = 0, StarCount1 = 0;
		int	AIStarCount = 0, AIStarCount1 = 0;

		// �� ���� ����ŭ �ݺ��Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			// �������� üũ�Ѵ�.
			if (Number[IndexY * 5 + i] == -1)
				++StarCount;

			// �������� üũ�Ѵ�.
			if (Number[i * 5 + IndexX] == -1)
				++StarCount1;

			// AI�� �������� üũ�Ѵ�.
			if (AINumber[AIIndexY * 5 + i] == -1)
				++AIStarCount;

			// AI�� �������� üũ�Ѵ�.
			if (AINumber[i * 5 + AIIndexX] == -1)
				++AIStarCount1;
		}

		if (StarCount == 5)
			++LineCount;

		if (StarCount1 == 5)
			++LineCount;

		if (AIStarCount == 5)
			++AILineCount;

		if (AIStarCount1 == 5)
			++AILineCount;


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

		if (AIFindIndex % 6 == 0)
		{
			AIStarCount = 0;

			for (int i = 0; i <= 24; i += 6)
			{
				if (AINumber[i] == -1)
					++AIStarCount;
			}

			if (AIStarCount == 5)
				++AILineCount;
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

		if (AIFindIndex % 4 == 0 && AIFindIndex != 0 && AIFindIndex != 24)
		{
			AIStarCount = 0;

			for (int i = 4; i <= 20; i += 4)
			{
				if (AINumber[i] == -1)
					++AIStarCount;
			}

			if (AIStarCount == 5)
				++AILineCount;
		}

		// �ϼ��� ���� ���� ���� �ε����� ���� ���� ���� �ε����� ������ ���� 2�� ����.
		int	AICheckIndex = -1, AICheckStarIndex = -1;
		int	AIPrevStarCount = -1;

		// ���ð����� ���� �� ���� ���� ���� �ϼ��� �� �ִ� ���ڸ� ����.
		for (int i = 0; i < 25; ++i)
		{
			// ���� �ƴ� ��쿡�� üũ�Ѵ�.
			if (AINumber[i] != -1)
			{
				AIIndexX = i % 5;
				AIIndexY = i / 5;
				AIStarCount = 0;
				AIStarCount1 = 0;

				for (int j = 0; j < 5; ++j)
				{
					// AI�� �������� üũ�Ѵ�.
					if (AINumber[AIIndexY * 5 + j] == -1)
						++AIStarCount;

					// AI�� �������� üũ�Ѵ�.
					if (AINumber[j * 5 + AIIndexX] == -1)
						++AIStarCount1;
				}

				// ������ ���� �ε����� �ش��ϴ� ����, �����ٿ� ���� *�� �����
				// ������ �صξ���. ������ �����ص� *�� ������ ���� ������ *��
				// ������ ���Ͽ� *�� �� ���� ���� �����ش�.
				if (AIPrevStarCount < AIStarCount)
				{
					AICheckStarIndex = i;
					AIPrevStarCount = AIStarCount;
				}

				else if (AIPrevStarCount < AIStarCount1)
				{
					AICheckStarIndex = i;
					AIPrevStarCount = AIStarCount1;
				}

				// �밢�� 2�ٿ� ���ؼ� üũ�Ѵ�.
				if (AIFindIndex % 6 == 0)
				{
					AIStarCount = 0;

					for (int i = 0; i <= 24; i += 6)
					{
						if (AINumber[i] == -1)
							++AIStarCount;
					}

					if (AIPrevStarCount < AIStarCount)
					{
						AICheckStarIndex = i;
						AIPrevStarCount = AIStarCount;
					}
				}

				if (AIFindIndex % 4 == 0 && AIFindIndex != 0 && AIFindIndex != 24)
				{
					AIStarCount = 0;

					for (int i = 4; i <= 20; i += 4)
					{
						if (AINumber[i] == -1)
							++AIStarCount;
					}

					if (AIPrevStarCount < AIStarCount)
					{
						AICheckStarIndex = i;
						AIPrevStarCount = AIStarCount;
					}
				}
			}
		}

		Input = AINumber[AICheckStarIndex];


		// ���ð����� ���ڸ� ��Ƽ� ���� �����ϰ� �ϳ��� �����ϴ� ���.
		// AI�� �Է��Ѵ�.
		// ������ �� �ִ� ���� ����� �����.
		//int	SelectNumber[25] = {};
		// ������ �� �ִ� ���� ����� ����.
		//int	SelectCount = 0;

		//for (int i = 0; i < 25; ++i)
		//{
		//	// ���� �ƴ� ���
		//	if (AINumber[i] != -1)
		//	{
		//		SelectNumber[SelectCount] = AINumber[i];
		//		++SelectCount;
		//	}
		//}

		//Input = SelectNumber[rand() % SelectCount];

		// �÷��̾��� ������ AI�� ������ ���ڸ� ã�Ƽ� *�� �ٲ۴�.
		for (int i = 0; i < 25; ++i)
		{
			if (Number[i] == Input)
			{
				FindIndex = i;
				Number[i] = -1;
				break;
			}
		}

		for (int i = 0; i < 25; ++i)
		{
			if (AINumber[i] == Input)
			{
				AIFindIndex = i;
				AINumber[i] = -1;
				break;
			}
		}



		IndexX = FindIndex % 5;
		IndexY = FindIndex / 5;
		AIIndexX = AIFindIndex % 5;
		AIIndexY = AIFindIndex / 5;

		StarCount = 0;
		StarCount1 = 0;
		AIStarCount = 0;
		AIStarCount1 = 0;

		// �� ���� ����ŭ �ݺ��Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			// �������� üũ�Ѵ�.
			if (Number[IndexY * 5 + i] == -1)
				++StarCount;

			// �������� üũ�Ѵ�.
			if (Number[i * 5 + IndexX] == -1)
				++StarCount1;

			// AI�� �������� üũ�Ѵ�.
			if (AINumber[AIIndexY * 5 + i] == -1)
				++AIStarCount;

			// AI�� �������� üũ�Ѵ�.
			if (AINumber[i * 5 + AIIndexX] == -1)
				++AIStarCount1;
		}

		if (StarCount == 5)
			++LineCount;

		if (StarCount1 == 5)
			++LineCount;

		if (AIStarCount == 5)
			++AILineCount;

		if (AIStarCount1 == 5)
			++AILineCount;


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

		if (AIFindIndex % 6 == 0)
		{
			AIStarCount = 0;

			for (int i = 0; i <= 24; i += 6)
			{
				if (AINumber[i] == -1)
					++AIStarCount;
			}

			if (AIStarCount == 5)
				++AILineCount;
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

		if (AIFindIndex % 4 == 0 && AIFindIndex != 0 && AIFindIndex != 24)
		{
			AIStarCount = 0;

			for (int i = 4; i <= 20; i += 4)
			{
				if (AINumber[i] == -1)
					++AIStarCount;
			}

			if (AIStarCount == 5)
				++AILineCount;
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