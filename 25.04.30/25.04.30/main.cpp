#include <iostream>
#include <time.h>

#define LINECOUNT 5
#define ARRAYCOUNT  (LINECOUNT * LINECOUNT)

// �Լ� ����
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
		// 0 ~ 24 ������ ������ ���� ���´�.
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

	printf("�ϼ��� �� : %d\n", LineCount);
}

int ChangeNumber(int Number[ARRAYCOUNT], int Input)
{
	for (int i = 0; i < ARRAYCOUNT; ++i)
	{
		// �Է��� ���ڰ� ���� �迭�� ���� ���
		if (Number[i] == Input)
		{
		
			// ���� -1�� ��� *�� ����Ѵ�.
			Number[i] = -1;
			// ���̻� ���� ���ڰ� ���� ������ �ݺ��� �����Ѵ�.
			return i;
		}
	}
	// ���� for������ ��ã�� ��� ����� �ͼ� -1�� ��ȯ�Ѵ�.
	// �� ��� ��ã�� ���� �ȴ�. (�̹� *�� �ٲ� ���ڸ� �Է��� ���)
	return -1;
}

int ComputeLineCount(int Number[ARRAYCOUNT], int Index)
{
	int LineCount = 0;
	// �Է��� ���ڰ� ������ �� ��  �ִ� ���� ���Ѵ�.
	// ����, ���δ� ������ üũ�ϰ� �밢�� 2�ٿ� ������ �� �� �ִ���
	// üũ

	// ����, ���� üũ.
	// �����ε��� : �ε��� / ���ΰ���
	// �����ε��� : �ε��� % ���ΰ���
	int IndexX = Index % LINECOUNT;
	int IndexY = Index / LINECOUNT;

	int StarCount = 0, StarCount1 = 0;
	// �� ���� ����ŭ �ݺ��Ѵ�.
	for (int i = 0; i < LINECOUNT; ++i)
	{
		// �������� üũ�Ѵ�.
		if (Number[IndexY * LINECOUNT + i] = -1)
			++StarCount;
		// �������� üũ�Ѵ�.
		if (Number[i * LINECOUNT + IndexX] = -1)
			++StarCount1;
	}
	return 0;
}

int SelectAI(int Number[ARRAYCOUNT])
{
	return 0;
}
