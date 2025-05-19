
#include <iostream>
#include <time.h>

/*
1 ~ 25 사이의 숫자를 저장하기 위한 배열 25개짜리를 만든다.
1 ~ 25 사이의 숫자를 골고루 섞어준다.
while문을 이용하여 무한루프를 돌며 5x5로 출력하고 숫자를 입력받는다.
입력받은 숫자가 0이라면 게임을 종료하고 1 ~ 25 사이의 숫자라면 해당 숫자를
찾아서 *로 출력한다.
한줄이 모두 *로 바뀌면 줄 카운트가 증가한다.
가로 5줄, 세로 5줄, 대각선 2줄에 대해 완성된 줄을 체크하여 5줄 이상이면
게임을 종료한다.
*/

void main()
{
	srand(time(0));
	rand();

	// 1 ~ 10 까지 숫자를 2개씩 가지고 있는 20개 짜리 배열을 만들고
	// 섞어준다.
	int	Number[20] = {};
	bool	Open[20] = {};

	for (int i = 0; i < 10; ++i)
	{
		Number[i] = i + 1;
		Number[i + 10] = i + 1;
	}

	// 숫자를 섞어준다.
	for (int i = 0; i < 100; ++i)
	{
		// 랜덤한 인덱스 2개를 구해준다.
		int	Index1 = rand() % 20;
		int	Index2 = rand() % 20;

		// Temp에 Index1번의 값을 저장한다.
		// Index1번의 값을 Index2번의 값으로 변경한다.
		// 미리 저장해둔 Index1번의 값을 Index2번의 값으로 대입해준다.
		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	int	PrevOpenIndex = -1;

	while (true)
	{
		// 배열의 숫자를 가로 10개, 세로 2줄로 출력한다.
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

		// 숫자를 0 ~ 20 사이의 숫자를 입력받는다.
		// 입력받은 숫자가 20일 경우 break를 이용해서 while문을 빠져나간다.
		int	Input = 0;
		printf("숫자를 입력하세요(20 : 종료) : ");
		scanf_s("%d", &Input);

		if (Input == 20)
			break;

		// 0 ~ 19 사이의 값이 아닐 경우 다시 출력하고 입력받게 한다.
		else if (Input < 0 || Input > 19)
			continue;

		// 이미 오픈되어 있는 카드라면 다시 입력받게 한다.
		if (Open[Input])
			continue;

		Open[Input] = true;
		// 카드 2개를 오픈하면 2개의 카드가 서로 같은 값인지 비교하여 같은 값이면
		// 계속 오픈된 상태를 유지하고 다른 값이면 두 카드를 클로즈 상태로
		// 만들어준다.
		// PrevOpenIndex 가 -1이라면 첫번째 카드를 오픈하는 것이다.
		if (PrevOpenIndex == -1)
		{
			PrevOpenIndex = Input;
			continue;
		}

		// 2번째 카드를 오픈하면 둘의 값을 비교한다.
		if (Number[PrevOpenIndex] != Number[Input])
		{
			Open[PrevOpenIndex] = false;
			Open[Input] = false;
		}

		PrevOpenIndex = -1;
	}
}