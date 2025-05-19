
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
	printf("1. ���\n");
	printf("2. �ü�\n");
	printf("3. ������\n");
	printf("������ ������ �����ϼ��� : ");
	int		Input;
	scanf_s("%d", &Input);

	if (Input <= 0 || Input >= 4)
		return;

	int	Index = Input - 1;

	printf("���ݷ� : ");
	scanf_s("%d", &Info[Index].Attack);

	printf("���� : ");
	scanf_s("%d", &Info[Index].Defense);

	printf("ü�� : ");
	scanf_s("%d", &Info[Index].HP);

	printf("���� : ");
	scanf_s("%d", &Info[Index].MP);

	Save(Info);
}

void Create(FItem**& ItemArray, int& Capacity, int& Count)
{
	//�迭�� �� á���� Ȯ���ϰ� �迭�� �� á�ٸ� �迭 ������ �÷��ش�.
	if (Capacity == Count)
	{
		//�迭������ 2��� �÷��ش�.
		Capacity *= 2;

		// �÷��� ���� ����ŭ �迭�� ���Ӱ� �����Ѵ�.
		FItem** NewArray = new FItem* [Capacity];

		// ���� �迭�� �ִ� ������ ���ο� �迭�� �־��ش�.
		for (int i = 0; i < Count; ++i)
		{
			NewArray
		}
	}
}

int main()
{
	/*
	���۷��� : �ٸ� ������ �����Ͽ� ���� �����ͼ� ����ϰų� ���� ������ �� �ְ� ���ִ� ����̴�.
	���۷��� ���۷��� ������ �����ϴ� ���ÿ� �ݵ�� 
	�����ϴ� ����� �����ؾ��Ѵ�.

	����Ÿ��& ������ = �����Ҵ�󺯼�; �� ������� ����Ѵ�.
	*/
//	FPlayerEditorInfo	JobInfo[3] = {};
	FItem* ItemArray = new FItem[3];
	FItem** ItemArray = new FItem * [3];

	// ��ü�迭�� ũ���̴�.
	int ItemCapacity = 2;
	// �迭�� �߰��� ������ �����̴�.
	int ItemCount = 0;



	while (true)
	{
		system("cls");
		printf("1. �������߰�\n");
		printf("2. �����ۻ���\n");
		printf("3. �ҷ�����\n");
		printf("4. ���\n");
		printf("5. ����\n");
		printf("�޴��� �����ϼ��� : ");
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
				printf("���ݷ� : %d\n", JobInfo[i].Attack);
				printf("���� : %d\n", JobInfo[i].Defense);
				printf("ü�� : %d\n", JobInfo[i].HP);
				printf("���� : %d\n", JobInfo[i].MP);
			}

			system("pause");
			break;
		case EEditorItemMenu::Exit:
			Save(JobInfo);

			//�����迭�� �����ش�.
			SAFE_DELETE_ARRAY
			return 0;
		}
	}

	return 0;
}