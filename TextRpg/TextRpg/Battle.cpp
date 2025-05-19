
#include "Battle.h"

FMonsterEditorInfo gMonsterOriginInfo[EMapMenu::MapCount];

bool BattleInit()
{
	// ���� ���Ϸκ��� ���� ������ �о �޸𸮿� �÷��д�.
	FILE* File = nullptr;

	fopen_s(&File, "MonsterInfo.mst", "rb");

	if (!File)
		return false;

	fread(gMonsterOriginInfo, sizeof(FMonsterEditorInfo), EMapMenu::MapCount, File);

	fclose(File);
	return true;
}

void OutputMonsterBattle(FMonsterInfo* Monster)
{
	printf("�̸� : %s ", Monster->Name);

	printf("���� : %d\t����ġ : %d\n", Monster->Level, Monster->Exp);
}


void OutputPlayerBattle()
{
	printf("�̸� : %s\t���� : ", gPlayer->Name);

	switch (gPlayer->Job)
	{
	case EPlayerJob::Knight:
		printf("���\n");
		break;
	case EPlayerJob::Archer:
		printf("�ü�\n");
		break;
	case EPlayerJob::Magicion:
		printf("������\n");
		break;
	}

	printf("���� : %d\t����ġ : %d\n", gPlayer->Level, gPlayer->Exp);
}

// �� cpp������ ����� �Լ��� ����� ����κ��� ��� �ȴ�.
// ��, �� �Լ��� �� �Լ����� �Ʒ��� �մ� �Լ����� ����� �� �ִ�.
void RunBattle(EMapMenu::Type BattleType)
{
	// ���̵��� �´� ���͸� �����Ѵ�.
	FMonsterInfo* Monster = new FMonsterInfo;

	int MenuIndex = BattleType - 1;

	strcpy_s(Monster->Name, gMonsterOriginInfo[MenuIndex].Name);
	Monster->Attack = gMonsterOriginInfo[MenuIndex].Attack;
	Monster->Defense = gMonsterOriginInfo[MenuIndex].Defense;
	Monster->HP = gMonsterOriginInfo[MenuIndex].HP;
	Monster->HPMax = gMonsterOriginInfo[MenuIndex].HP;
	Monster->MP = gMonsterOriginInfo[MenuIndex].MP;
	Monster->MPMax = gMonsterOriginInfo[MenuIndex].MP;
	Monster->Level = gMonsterOriginInfo[MenuIndex].Level;
	Monster->Exp = gMonsterOriginInfo[MenuIndex].Exp;
	Monster->Gold = gMonsterOriginInfo[MenuIndex].Gold;
	while (true)
	{
		system("cls");
		printf("=====================player=====================\n");
		OutputPlayerBattle();

		printf("=====================Monster=====================\n");
		OutputMonsterBattle(Monster);

	}
}


void RunMap()
{
	while (true)
	{
		// ���� �޴��� �����ְ� �����Ѵ�.
		system("cls");
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. �����\n");
		printf("4. �ڷΰ���\n");
		printf("�޴��� �����ϼ��� : ");
		int	Input = 0;
		scanf_s("%d", &Input);

		switch (Input)
		{
		case EMapMenu::Easy:
			RunBattle(EMapMenu::Easy);
			break;
		case EMapMenu::Normal:
			RunBattle(EMapMenu::Normal);
			break;
		case EMapMenu::Hard:
			RunBattle(EMapMenu::Hard);
			break;
		case EMapMenu::Back:
			return;
		}
	}
}
