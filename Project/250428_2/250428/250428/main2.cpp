
#include <iostream>
#include "time.h"

void main()
{
	srand(time(0));
	rand();

	// 1 ~ 45 까지의 숫자를 담아놓고 위한 변수를 만든다.
	int	Number[45] = {};

	// 1 ~ 45까지의 값을 대입한다.
	for (int i = 0; i < 45; ++i)
	{
		Number[i] = i + 1;
	}

	// 게임 수를 입력받아서 게임 수만큼 6개의 랜덤한 번호를 만든다.
	int	GameCount = 0;
	printf("게임수를 입력하세요 : ");
	scanf_s("%d", &GameCount);
	
	// 6개의 당첨번호와 보너스번호 1개를 미리 만들어둔다.
	for (int i = 0; i < 100; ++i)
	{
		// 랜덤한 인덱스 2개를 구해준다.
		int	Index1 = rand() % 45;
		int	Index2 = rand() % 45;

		// Temp에 Index1번의 값을 저장한다.
		// Index1번의 값을 Index2번의 값으로 변경한다.
		// 미리 저장해둔 Index1번의 값을 Index2번의 값으로 대입해준다.
		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 6; ++j)
		{
			if (Number[i] > Number[j])
			{
				int	Temp = Number[i];
				Number[i] = Number[j];
				Number[j] = Temp;
			}
		}
	}

	int	Result[7] = {};
	for (int i = 0; i < 7; ++i)
	{
		Result[i] = Number[i];
	}

	printf("당첨번호 : ");

	for (int i = 0; i < 6; ++i)
	{
		printf("%d\t", Result[i]);
	}

	printf("/\t%d\n", Result[6]);

	for (int Game = 0; Game < GameCount; ++Game)
	{
		// 숫자를 섞어준다.
		for (int i = 0; i < 100; ++i)
		{
			// 랜덤한 인덱스 2개를 구해준다.
			int	Index1 = rand() % 45;
			int	Index2 = rand() % 45;

			// Temp에 Index1번의 값을 저장한다.
			// Index1번의 값을 Index2번의 값으로 변경한다.
			// 미리 저장해둔 Index1번의 값을 Index2번의 값으로 대입해준다.
			int	Temp = Number[Index1];
			Number[Index1] = Number[Index2];
			Number[Index2] = Temp;
		}

		// 6개의 숫자를 정렬한다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = i + 1; j < 6; ++j)
			{
				if (Number[i] > Number[j])
				{
					int	Temp = Number[i];
					Number[i] = Number[j];
					Number[j] = Temp;
				}
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			// \t : Tab 1 해주는 것이다.
			printf("%d\t", Number[i]);
		}

		// 당첨번호와 숫자 3개가 같다면 5등, 4개가 같다면 4등, 5개가 같다면 3등,
		// 5개가 같고 보너스번호1개가 같다면 2등, 6개가 같다면 1등을 출력한다.
		// 몇개가 같은지 저장하는 변수를 만든다.
		int	Pair = 0;

		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				// 같은 숫자가 있을 경우 Pair를 1 증가하고
				// 다음 숫자를 검사한다.
				if (Result[i] == Number[j])
				{
					++Pair;
					break;
				}
			}
		}

		switch (Pair)
		{
		case 3:
			printf(" : 5등\n");
			break;
		case 4:
			printf(" : 4등\n");
			break;
		case 5:
			bool Second;
			Second = false;
			// 보너스 번호가 있는지 비교한다.
			for (int i = 0; i < 6; ++i)
			{
				if (Result[6] == Number[i])
				{
					Second = true;
					break;
				}
			}

			if (Second)
				printf(" : 2등\n");
			else
				printf(" : 3등\n");
			break;
		case 6:
			printf(" : 1등\n");
			break;
		default:
			printf(" : 꽝\n");
			break;
		}

		//printf("\n");
	}
}