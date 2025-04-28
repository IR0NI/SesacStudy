#include <iostream>
#include "time.h"

void main()
{
	srand(time(0));
	rand();

	// 1- 45 까지의 숫자를 담아놓기 위한 변수를 만든다.
	int Number[45] = {};

	// 1-45 까지의 값을 대입한다.

	for (int i = 0; i < 45; ++i)
	{
		Number[i] = i + 1;
	}
	// 게임 수를 입력받아서 게임 수만큼 6개의 랜덤한 번호를 만든다.

	// 6개의 당첨번호와 보너스번호 1개를 미리 만들어둔다
	int GameCount = 0;
	scanf_s("%d", &GameCount);
	
	for (int a = 0; a < GameCount; a++)
	{
		// 숫자를 섞어준다.
		for (int i = 0; i < 100; ++i)
		{
			// 랜덤한 인덱스 2개를 구해준다.
			int Index1 = rand() % 45;
			int Index2 = rand() % 45;

			// Temp에 Index1번의 값을 저장한다.
			// Index1번의 값을 Index2번의 값으로 변경한다.
			// 미리 저장해둔 Index1번의 값을 Index2 번의 값으로 대입해분다.
			int Temp = Number[Index1];
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
					int Temp = Number[i];
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

		printf("\n");
	}
	
}