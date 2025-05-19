
#include <iostream>
#include <time.h>

void main()
{
	srand(time(0));
	rand();

	int	Number[25] = {};

	// AI가 사용할 숫자 배열을 만든다.
	int	AINumber[25] = {};

	// 위의 배열에 1 ~ 25 까지 차례대로 대입한다.
	for (int i = 0; i < 25; ++i)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}

	// 1 ~ 25 사이의 숫자를 섞어준다.
	for (int i = 0; i < 100; ++i)
	{
		// 0 ~ 24 사이의 랜덤한 수를 얻어온다.
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
		// 콘솔 화면의 텍스트를 모두 지워준다.
		system("cls");

		// 플레이어 정보 출력
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

		printf("완성된 줄 : %d\n", LineCount);

		// AI 출력
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

		printf("완성된 줄 : %d\n", AILineCount);

		// 5줄 이상을 완성했다면 게임을 종료한다.
		if (LineCount >= 5)
		{
			printf("플레이어 승리\n");
			break;
		}

		else if (AILineCount >= 5)
		{
			printf("AI 승리\n");
			break;
		}


		// 숫자를 입력받는다.
		printf("숫자를 입력하세요(0 : 종료) : ");
		scanf_s("%d", &Input);

		if (Input == 0)
			break;

		else if (Input < 0 || Input > 25)
		{
			printf("잘못된 숫자를 입력하였습니다.\n");
			// pause는 콘솔화면을 일시정지 시켜준다.
			system("pause");
			continue;
		}

		// 입력한 숫자가 배열에 있는지 판단하기 위한 변수.
		// 기본으로 못찾았다는 의미로 false를 넣어두고 찾았을 경우 true로 바꾼다.
		bool	Find = false;

		// 찾아준 숫자의 인덱스를 저장하기 위한 변수.
		int	FindIndex = -1, AIFindIndex = -1;

		// 입력한 숫자가 배열에 있는지 찾는다.
		for (int i = 0; i < 25; ++i)
		{
			// 입력한 숫자가 숫자 배열에 있을 경우
			if (Number[i] == Input)
			{
				// 인덱스를 저장한다.
				FindIndex = i;

				Find = true;
				// 값이 -1일 경우 *로 취급한다.
				Number[i] = -1;
				// 더이상 같은 숫자가 없기 때문에 반복을 종료한다.
				break;
			}
		}

		// Find변수가 만약 true라면 배열에서 값을 찾았다는 의미이고 false라면
		// 배열에서 값을 못찾았다는 의미가 된다. 못찾았을 경우 처음으로 돌아가
		// 다시 출력하고 입력을 받게 한다.
		if (!Find) // Find == false
			continue;

		// AI의 숫자에서 입력한 숫자를 찾아 *로 만든다.
		for (int i = 0; i < 25; ++i)
		{
			if (AINumber[i] == Input)
			{
				AIFindIndex = i;
				AINumber[i] = -1;
				break;
			}
		}



		// 입력한 숫자가 영향을 줄 수 있는 줄을 구한다.
		// 가로, 세로는 무조건 체크하고 대각선 2줄에 영향을 줄 수 있는지
		// 체크.

		// 가로, 세로 체크.
		// 세로인덱스 : 인덱스 / 가로개수
		// 가로인덱스 : 인덱스 % 가로개수
		int	IndexX = FindIndex % 5;
		int	IndexY = FindIndex / 5;
		int	AIIndexX = AIFindIndex % 5;
		int	AIIndexY = AIFindIndex / 5;

		int	StarCount = 0, StarCount1 = 0;
		int	AIStarCount = 0, AIStarCount1 = 0;

		// 한 줄의 수만큼 반복한다.
		for (int i = 0; i < 5; ++i)
		{
			// 가로줄을 체크한다.
			if (Number[IndexY * 5 + i] == -1)
				++StarCount;

			// 세로줄을 체크한다.
			if (Number[i * 5 + IndexX] == -1)
				++StarCount1;

			// AI의 가로줄을 체크한다.
			if (AINumber[AIIndexY * 5 + i] == -1)
				++AIStarCount;

			// AI의 세로줄을 체크한다.
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


		// 대각선 인덱스 : 0, 6, 12, 18, 24
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

		// 대각선 인덱스 : 4, 8, 12, 16, 20
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

		// 완성될 줄이 가장 많은 인덱스와 별이 가장 많은 인덱스를 저장할 변수 2개 선언.
		int	AICheckIndex = -1, AICheckStarIndex = -1;
		int	AIPrevStarCount = -1;

		// 선택가능한 숫자 중 가장 많은 줄을 완성할 수 있는 숫자를 선택.
		for (int i = 0; i < 25; ++i)
		{
			// 별이 아닐 경우에만 체크한다.
			if (AINumber[i] != -1)
			{
				AIIndexX = i % 5;
				AIIndexY = i / 5;
				AIStarCount = 0;
				AIStarCount1 = 0;

				for (int j = 0; j < 5; ++j)
				{
					// AI의 가로줄을 체크한다.
					if (AINumber[AIIndexY * 5 + j] == -1)
						++AIStarCount;

					// AI의 세로줄을 체크한다.
					if (AINumber[j * 5 + AIIndexX] == -1)
						++AIStarCount1;
				}

				// 위에서 현재 인덱스에 해당하는 가로, 세로줄에 대해 *이 몇개인지
				// 저장을 해두었다. 이전에 저장해둔 *의 개수와 현재 구해준 *의
				// 개수를 비교하여 *이 더 많은 줄을 구해준다.
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

				// 대각선 2줄에 대해서 체크한다.
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


		// 선택가능한 숫자를 모아서 그중 랜덤하게 하나를 선택하는 방식.
		// AI가 입력한다.
		// 선택할 수 있는 숫자 목록을 만든다.
		//int	SelectNumber[25] = {};
		// 선택할 수 있는 숫자 목록의 개수.
		//int	SelectCount = 0;

		//for (int i = 0; i < 25; ++i)
		//{
		//	// 별이 아닐 경우
		//	if (AINumber[i] != -1)
		//	{
		//		SelectNumber[SelectCount] = AINumber[i];
		//		++SelectCount;
		//	}
		//}

		//Input = SelectNumber[rand() % SelectCount];

		// 플레이어의 숫자중 AI가 선택한 숫자를 찾아서 *로 바꾼다.
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

		// 한 줄의 수만큼 반복한다.
		for (int i = 0; i < 5; ++i)
		{
			// 가로줄을 체크한다.
			if (Number[IndexY * 5 + i] == -1)
				++StarCount;

			// 세로줄을 체크한다.
			if (Number[i * 5 + IndexX] == -1)
				++StarCount1;

			// AI의 가로줄을 체크한다.
			if (AINumber[AIIndexY * 5 + i] == -1)
				++AIStarCount;

			// AI의 세로줄을 체크한다.
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


		// 대각선 인덱스 : 0, 6, 12, 18, 24
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

		// 대각선 인덱스 : 4, 8, 12, 16, 20
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


		// 12줄을 모두 체크하여 완성된 줄의 수를 구한다.
		//LineCount = 0;

		//// *로 바뀐 수를 저장하기 위한 변수.
		//int	StarCount = 0, StarCount1 = 0;

		//for (int i = 0; i < 5; ++i)
		//{
		//	// *로 바뀐걸 체크하기 전에 *의 수를 저장하기 위한 변수를 0으로
		//	// 초기화한다.
		//	StarCount = 0;
		//	StarCount1 = 0;

		//	// j for문을 5번 돌며 별의 숫자가 몇개인지를 구한다.
		//	for (int j = 0; j < 5; ++j)
		//	{
		//		// 숫자가 *일 경우 StarCount를 증가시킨다.
		//		if (Number[i * 5 + j] == -1)
		//			++StarCount;

		//		// 세로줄을 체크한다.
		//		if (Number[j * 5 + i] == -1)
		//			++StarCount1;
		//	}

		//	// 한줄이 모두 *로 바뀌었을 경우 줄 수를 증가시켜준다.
		//	if (StarCount == 5)
		//		++LineCount;

		//	if (StarCount1 == 5)
		//		++LineCount;
		//}

		//StarCount = 0;

		//// 왼쪽 상단 -> 오른쪽 하단 대각선 체크
		//for (int i = 0; i <= 24; i += 6)
		//{
		//	if (Number[i] == -1)
		//		++StarCount;
		//}

		//if (StarCount == 5)
		//	++LineCount;

		//StarCount = 0;

		//// 오른쪽 상단 -> 왼쪽 하단 대각선 체크
		//for (int i = 4; i <= 20; i += 4)
		//{
		//	if (Number[i] == -1)
		//		++StarCount;
		//}

		//if (StarCount == 5)
		//	++LineCount;
	}
}