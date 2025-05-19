
#include <iostream>
#include "GameInfo.h"

namespace EEditorItemMenu
{
	enum Type
	{
		None,
		Create,
		Delete,
		Modify,
		Load,
		Output,
		Exit,
		End
	};
}

void Save(FPlayerEditorInfo* Info)
{
	FILE* File = nullptr;

	fopen_s(&File, "PlayerInfo.pli", "wb");

	if (!File)
		return;

	fwrite(Info, sizeof(FPlayerEditorInfo), 3, File);

	fclose(File);
}

void Load(FPlayerEditorInfo* Info)
{
	FILE* File = nullptr;

	fopen_s(&File, "PlayerInfo.pli", "rb");

	if (!File)
		return;

	fread(Info, sizeof(FPlayerEditorInfo), 3, File);

	fclose(File);
}

void Modify(FPlayerEditorInfo* Info)
{
	printf("1. 기사\n");
	printf("2. 궁수\n");
	printf("3. 마법사\n");
	printf("수정할 직업을 선택하세요 : ");
	int		Input;
	scanf_s("%d", &Input);

	if (Input <= 0 || Input >= 4)
		return;

	int	Index = Input - 1;

	printf("공격력 : ");
	scanf_s("%d", &Info[Index].Attack);

	printf("방어력 : ");
	scanf_s("%d", &Info[Index].Defense);

	printf("체력 : ");
	scanf_s("%d", &Info[Index].HP);

	printf("마나 : ");
	scanf_s("%d", &Info[Index].MP);

	Save(Info);
}

void Create(FItem**& ItemArray, int& Capacity, int& Count)
{
	//배열이 꽉 찼는지 확인하고 배열이 꽉 찼다면 배열 공간을 늘려준다.
	if (Capacity == Count)
	{
		//배열공간을 2배로 늘려준다.
		Capacity *= 2;

		// 늘려준 공간 수만큼 배열을 새롭게 생성한다.
		FItem** NewArray = new FItem* [Capacity];

		// 기존 배열에 있는 정보를 새로운 배열에 넣어준다.
		for (int i = 0; i < Count; ++i)
		{
			NewArray
		}
	}
}

int main()
{
	/*
	레퍼런스 : 다른 변수를 참조하여 값을 가져와서 사용하거나 값을 변경할 수 있게 해주는 기능이다.
	레퍼런스 레퍼런스 변수를 선언하는 동시에 반드시 
	참조하는 대상을 지정해야한다.

	변수타입& 변수명 = 참조할대상변수; 의 방식으로 사용한다.
	*/
//	FPlayerEditorInfo	JobInfo[3] = {};
	FItem* ItemArray = new FItem[3];
	FItem** ItemArray = new FItem * [3];

	// 전체배열의 크기이다.
	int ItemCapacity = 2;
	// 배열에 추가된 아이템 개수이다.
	int ItemCount = 0;



	while (true)
	{
		system("cls");
		printf("1. 아이템추가\n");
		printf("2. 아이템삭제\n");
		printf("3. 불러오기\n");
		printf("4. 출력\n");
		printf("5. 종료\n");
		printf("메뉴를 선택하세요 : ");
		int	Input = 0;
		scanf_s("%d", &Input);

		switch (Input)
		{
		case EEditorItemMenu::Create:
			Create(ItemArray, ItemCount, ItemCount)
			break;
		case EEditorItemMenu::Delete:
			break;
		case EEditorItemMenu::Modify:
			break;
		case EEditorItemMenu::Load:
			Load(JobInfo);
			break;
		case EEditorItemMenu::Output:
			for (int i = 0; i < 3; ++i)
			{
				printf("공격력 : %d\n", JobInfo[i].Attack);
				printf("방어력 : %d\n", JobInfo[i].Defense);
				printf("체력 : %d\n", JobInfo[i].HP);
				printf("마나 : %d\n", JobInfo[i].MP);
			}

			system("pause");
			break;
		case EEditorItemMenu::Exit:
			Save(JobInfo);

			//동적배열을 지워준다.
			SAFE_DELETE_ARRAY
			return 0;
		}
	}

	return 0;
}