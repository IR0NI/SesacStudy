
#include <iostream>
#include <time.h>

#define	LINECOUNT	7
#define	ARRAYCOUNT	(LINECOUNT * LINECOUNT)

// 함수 선언.
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

	int	Number[ARRAYCOUNT] = {};

	// AI가 사용할 숫자 배열을 만든다.
	int	AINumber[ARRAYCOUNT] = {};

	SetNumber(Number);
	SetNumber(AINumber);

	// 숫자를 섞어준다.
	Shuffle(Number);
	Shuffle(AINumber);

	int	Input = 0;
	int	LineCount = 0, AILineCount = 0;

	while (true)
	{
		// 콘솔 화면의 텍스트를 모두 지워준다.
		system("cls");

		// 플레이어 정보 출력
		printf("================== Player ==================\n");

		OutputInfo(Number, LineCount);

		// AI 출력
		printf("================== AI ==================\n");

		OutputInfo(AINumber, AILineCount);

		// 5줄 이상을 완성했다면 게임을 종료한다.
		if (LineCount >= LINECOUNT)
		{
			printf("플레이어 승리\n");
			break;
		}

		else if (AILineCount >= LINECOUNT)
		{
			printf("AI 승리\n");
			break;
		}

		// 숫자를 입력받는다.
		printf("숫자를 입력하세요(0 : 종료) : ");
		scanf_s("%d", &Input);

		if (Input == 0)
			break;

		else if (Input < 0 || Input > ARRAYCOUNT)
		{
			printf("잘못된 숫자를 입력하였습니다.\n");
			// pause는 콘솔화면을 일시정지 시켜준다.
			system("pause");
			continue;
		}

		// 입력한 숫자를 *로 바꿔준다.
		int FindIndex = ChangeNumber(Number, Input);

		// *로 바꾼 인덱스가 -1이라면 이미 *로 바꾼 숫자를 입력한
		// 것이므로 다시 입력받게 한다.
		if (FindIndex == -1)
			continue;

		int AIFindIndex = ChangeNumber(AINumber, Input);

		// 줄 수를 체크한다.
		// ComputeLineCount 함수에서 넘겨준 인덱스를 *로 바꾸었을 경우
		// 몇줄이 추가되어야 하는지를 반환한다.
		LineCount += ComputeLineCount(Number, FindIndex);
		AILineCount += ComputeLineCount(AINumber, AIFindIndex);

		// AI가 입력한다.
		Input = SelectAI(AINumber);

		// AI가 찾아준 숫자를 *로 바꿔준다.
		FindIndex = ChangeNumber(Number, Input);
		AIFindIndex = ChangeNumber(AINumber, Input);

		LineCount += ComputeLineCount(Number, FindIndex);
		AILineCount += ComputeLineCount(AINumber, AIFindIndex);
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

			// 찾아준 값의 배열 인덱스를 반환한다.
			return i;
		}
	}

	// 위의 for문에서 못찾을 경우 여기로 와서 -1을 반환한다.
	// 이 경우 못찾은 것이 된다.(이미 *로 바뀐 숫자를 입력한 경우)
	return -1;
}

int ComputeLineCount(int Number[ARRAYCOUNT], int Index)
{
	int	LineCount = 0;

	// 입력한 숫자가 영향을 줄 수 있는 줄을 구한다.
	// 가로, 세로는 무조건 체크하고 대각선 2줄에 영향을 줄 수 있는지
	// 체크.

	// 가로, 세로 체크.
	// 세로인덱스 : 인덱스 / 가로개수
	// 가로인덱스 : 인덱스 % 가로개수
	int	IndexX = Index % LINECOUNT;
	int	IndexY = Index / LINECOUNT;

	int	StarCount = 0, StarCount1 = 0;

	// 한 줄의 수만큼 반복한다.
	for (int i = 0; i < LINECOUNT; ++i)
	{
		// 가로줄을 체크한다.
		if (Number[IndexY * LINECOUNT + i] == -1)
			++StarCount;

		// 세로줄을 체크한다.
		if (Number[i * LINECOUNT + IndexX] == -1)
			++StarCount1;
	}

	if (StarCount == LINECOUNT)
		++LineCount;

	if (StarCount1 == LINECOUNT)
		++LineCount;


	// 대각선 인덱스 : 0, 6, 12, 18, 24
	if (Index % (LINECOUNT + 1) == 0)
	{
		StarCount = 0;

		for (int i = 0; i < ARRAYCOUNT; i += (LINECOUNT + 1))
		{
			if (Number[i] == -1)
				++StarCount;
		}

		if (StarCount == LINECOUNT)
			++LineCount;
	}

	// 대각선 인덱스 : 4, 8, 12, 16, 20
	if (Index % (LINECOUNT - 1) == 0 && Index != 0 && 
		Index != (ARRAYCOUNT - 1))
	{
		StarCount = 0;

		for (int i = LINECOUNT - 1; i <= (LINECOUNT * (LINECOUNT - 1)); 
			i += (LINECOUNT - 1))
		{
			if (Number[i] == -1)
				++StarCount;
		}

		if (StarCount == LINECOUNT)
			++LineCount;
	}

	return LineCount;
}

int SelectAI(int Number[ARRAYCOUNT])
{
	// 완성될 줄이 가장 많은 인덱스와 별이 가장 많은 인덱스를 저장할 변수 2개 선언.
	int	AICheckIndex = -1, AICheckStarIndex = -1;
	int	AIPrevStarCount = -1;
	int	StarCount = 0, StarCount1 = 0;

	// 선택가능한 숫자 중 가장 많은 줄을 완성할 수 있는 숫자를 선택.
	for (int i = 0; i < ARRAYCOUNT; ++i)
	{
		// 별이 아닐 경우에만 체크한다.
		if (Number[i] != -1)
		{
			int	IndexX = i % LINECOUNT;
			int	IndexY = i / LINECOUNT;

			StarCount = 0;
			StarCount1 = 0;

			for (int j = 0; j < LINECOUNT; ++j)
			{
				// AI의 가로줄을 체크한다.
				if (Number[IndexY * LINECOUNT + j] == -1)
					++StarCount;

				// AI의 세로줄을 체크한다.
				if (Number[j * LINECOUNT + IndexX] == -1)
					++StarCount1;
			}

			// 위에서 현재 인덱스에 해당하는 가로, 세로줄에 대해 *이 몇개인지
			// 저장을 해두었다. 이전에 저장해둔 *의 개수와 현재 구해준 *의
			// 개수를 비교하여 *이 더 많은 줄을 구해준다.
			if (AIPrevStarCount < StarCount)
			{
				AICheckStarIndex = i;
				AIPrevStarCount = StarCount;
			}

			else if (AIPrevStarCount < StarCount1)
			{
				AICheckStarIndex = i;
				AIPrevStarCount = StarCount1;
			}

			if (i % (LINECOUNT + 1) == 0)
			{
				StarCount = 0;

				for (int i = 0; i < ARRAYCOUNT; i += (LINECOUNT + 1))
				{
					if (Number[i] == -1)
						++StarCount;
				}

				if (AIPrevStarCount < StarCount)
				{
					AICheckStarIndex = i;
					AIPrevStarCount = StarCount;
				}
			}

			if (i % (LINECOUNT - 1) == 0 && i != 0 &&
				i != (ARRAYCOUNT - 1))
			{
				StarCount = 0;

				for (int i = LINECOUNT - 1; i <= (LINECOUNT * (LINECOUNT - 1));
					i += (LINECOUNT - 1))
				{
					if (Number[i] == -1)
						++StarCount;
				}

				if (AIPrevStarCount < StarCount)
				{
					AICheckStarIndex = i;
					AIPrevStarCount = StarCount;
				}
			}
		}
	}

	return Number[AICheckStarIndex];
}
