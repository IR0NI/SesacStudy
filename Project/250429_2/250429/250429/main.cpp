
#include <iostream>
#include <time.h>

void main()
{
	srand(time(0));
	rand();

	int	Number[25] = {};

	// 위의 배열에 1 ~ 25 까지 차례대로 대입한다.
	for (int i = 0; i < 25; ++i)
	{
		Number[i] = i + 1;
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
	}

	int	Input = 0;
	int	LineCount = 0;

	while (true)
	{
		// 콘솔 화면의 텍스트를 모두 지워준다.
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

		printf("완성된 줄 : %d\n", LineCount);

		// 5줄 이상을 완성했다면 게임을 종료한다.
		if (LineCount >= 5)
		{
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
		int	FindIndex = -1;

		// 입력한 숫자가 배열에 있는지 찾는다.
		for(int i = 0; i < 25; ++i)
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

		// 입력한 숫자가 영향을 줄 수 있는 줄을 구한다.
		// 가로, 세로는 무조건 체크하고 대각선 2줄에 영향을 줄 수 있는지
		// 체크.

		// 가로, 세로 체크.
		// 세로인덱스 : 인덱스 / 가로개수
		// 가로인덱스 : 인덱스 % 가로개수
		int	IndexX = FindIndex % 5;
		int	IndexY = FindIndex / 5;

		int	StarCount = 0, StarCount1 = 0;

		// 한 줄의 수만큼 반복한다.
		for (int i = 0; i < 5; ++i)
		{
			// 가로줄을 체크한다.
			if (Number[IndexY * 5 + i] == -1)
				++StarCount;

			// 세로줄을 체크한다.
			if (Number[i * 5 + IndexX] == -1)
				++StarCount1;
		}

		if (StarCount == 5)
			++LineCount;

		if (StarCount1 == 5)
			++LineCount;


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