
#include "Battle.h"

FMonsterEditorInfo gMonsterOriginInfo[EMapMenu::MapCount];

bool BattleInit()
{
	// 몬스터 파일로부터 몬스터 정보를 읽어서 메모리에 올려둔다.
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
	printf("이름 : %s ", Monster->Name);

	printf("레벨 : %d\t경험치 : %d\n", Monster->Level, Monster->Exp);
}


void OutputPlayerBattle()
{
	printf("이름 : %s\t직업 : ", gPlayer->Name);

	switch (gPlayer->Job)
	{
	case EPlayerJob::Knight:
		printf("기사\n");
		break;
	case EPlayerJob::Archer:
		printf("궁수\n");
		break;
	case EPlayerJob::Magicion:
		printf("마법사\n");
		break;
	}

	printf("레벨 : %d\t경험치 : %d\n", gPlayer->Level, gPlayer->Exp);
}

// 이 cpp에서만 사용할 함수는 헤더에 선언부분이 없어도 된다.
// 단, 이 함수는 이 함수보다 아래에 잇는 함수에서 사용할 수 있다.
void RunBattle(EMapMenu::Type BattleType)
{
	// 난이도에 맞는 몬스터를 생성한다.
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
		// 전투 메뉴를 보여주고 선택한다.
		system("cls");
		printf("1. 쉬움\n");
		printf("2. 보통\n");
		printf("3. 어려움\n");
		printf("4. 뒤로가기\n");
		printf("메뉴를 선택하세요 : ");
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
