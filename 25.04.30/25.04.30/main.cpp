#include <iostream>
#include <time.h>

#define LINECOUNT 5
#define ARRAYCOUNT  (LINECOUNT * LINECOUNT)

// 함수 선언
void SetNumber(int Number[ARRAYCOUNT]);
void Shuffle(int Number[ARRAYCOUNT]);
void OutputInfo(int Number[ARRAYCOUNT], int LineCount);
int ChangeNumber(int Number[ARRAYCOUNT], int Input);
int ComputeLineCount(int Number[ARRAYCOUNT], int Index);
int SelectAI(int Number[ARRAYCOUNT]);

void main()
{
	srand(time(0));
	rand();

	int Number[ARRAYCOUNT] = {};

	int AINumber[ARRAYCOUNT] = {};

	SetNumber(Number);
	SetNumber(AINumber);

	Shuffle(Number);
	Shuffle(AINumber);

	int Input = 0;
	int LineCount = 0, AILineCount = 0;

	while (true)
	{
		int FindIndex = ChangeNumber(Number, Input);

		if (FindIndex == -1)
			continue;

		ChangeNumber(AINumber, Input);
	}
	
}

void SetNumber(int Number[ARRAYCOUNT])
{
	for (int i = 0; i < ARRAYCOUNT; ++i)
	{
		Number[i] = i + 1;
	}
}

void Shuffle(int Number[ARRAYCOUNT])
{

	for (int i = 0; i < 100; ++i)
	{
		// 0 ~ 24 사이의 랜덤한 수를 얻어온다.
		int	Index1 = rand() % ARRAYCOUNT;
		int	Index2 = rand() % ARRAYCOUNT;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}
}

void OutputInfo(int Number[ARRAYCOUNT], int LineCount)
{
	for (int i = 0; i < LINECOUNT; ++i)
	{
		for (int j = 0; j < LINECOUNT; ++j)
		{
			if (Number[i * LINECOUNT + j] == -1)
				printf("*\t");

			else
				printf("%d\t", Number[i * LINECOUNT + j]);
		}

		printf("\n");
	}

	printf("완성된 줄 : %d\n", LineCount);
}

int ChangeNumber(int Number[ARRAYCOUNT], int Input)
{
	for (int i = 0; i < ARRAYCOUNT; ++i)
	{
		// 입력한 숫자가 숫자 배열에 있을 경우
		if (Number[i] == Input)
		{
		
			// 값이 -1일 경우 *로 취급한다.
			Number[i] = -1;
			// 더이상 같은 숫자가 없기 때문에 반복을 종료한다.
			return i;
		}
	}
	// 위의 for문에서 못찾을 경우 여기로 와서 -1을 반환한다.
	// 이 경우 못찾은 것이 된다. (이미 *로 바뀐 숫자를 입력한 경우)
	return -1;
}

int ComputeLineCount(int Number[ARRAYCOUNT], int Index)
{
	int LineCount = 0;
	// 입력한 숫자가 영향을 줄 수  있는 줄을 구한다.
	// 가로, 세로는 무조건 체크하고 대각선 2줄에 영향을 줄 수 있는지
	// 체크

	// 가로, 세로 체크.
	// 세로인덱스 : 인덱스 / 가로개수
	// 가로인덱스 : 인덱스 % 가로개수
	int IndexX = Index % LINECOUNT;
	int IndexY = Index / LINECOUNT;

	int StarCount = 0, StarCount1 = 0;
	// 한 줄의 수만큼 반복한다.
	for (int i = 0; i < LINECOUNT; ++i)
	{
		// 가로줄을 체크한다.
		if (Number[IndexY * LINECOUNT + i] = -1)
			++StarCount;
		// 세로줄을 체크한다.
		if (Number[i * LINECOUNT + IndexX] = -1)
			++StarCount1;
	}
	return 0;
}

int SelectAI(int Number[ARRAYCOUNT])
{
	return 0;
}
