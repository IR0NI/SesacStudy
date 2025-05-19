#include "Battle.h"
#include "Player.h"
#include "Monster.h"

FPlayerInfo* gPlayer = nullptr;
FMonsterInfo* gMonster = nullptr;

namespace EBattleMenu
{
	enum Type
	{
		None,
		Attack,
		Back,
		End
	};
}

enum class EBattleResult : unsigned char
{
	None,
	PlayerDeath,
	MonsterDeath,
};


CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

bool CBattle::Init(EMapMenu Map)
{
	return true;
}

void OutputPlayerBattle()
{
	///*printf("이름 : %s\t직업 : ", gPlayer->Name);

	//switch (gPlayer->Job)
	//{
	//case EPlayerJob::Knight:
	//	printf("기사\n");
	//	break;
	//case EPlayerJob::Archer:
	//	printf("궁수\n");
	//	break;
	//case EPlayerJob::Magicion:
	//	printf("마법사\n");
	//	break;
	//}*/

	printf("레벨 : %d\t경험치 : %d\n", gPlayer->Level,
		gPlayer->Exp);
	printf("공격력 : %d\t방어력 : %d\n", gPlayer->Attack,
		gPlayer->Defense);
	printf("체력 : %d / %d\t마나 : %d / %d\n",
		gPlayer->HP, gPlayer->HPMax,
		gPlayer->MP, gPlayer->MPMax);
	printf("골드 : %d\n", gPlayer->Gold);

	//printf("장착무기 : ");
	//if (gPlayer->EquipItem[EEquip::Weapon])
	//	printf("%s\t", gPlayer->EquipItem[EEquip::Weapon]->Name);
	//else
	//	printf("없음\t");

	//printf("장착방어구 : ");
	//if (gPlayer->EquipItem[EEquip::Armor])
	//	printf("%s\t", gPlayer->EquipItem[EEquip::Armor]->Name);
	//else
	//	printf("없음\t");
	//	
}

void OutputMonsterBattle(FMonsterInfo* Monster)
{
	printf("이름 : %s\t레벨 : %d\n", Monster->Name,
		Monster->Level);

	printf("획득경험치 : %d\t획득골드 : %d\n", Monster->Exp,
		Monster->Gold);
	printf("공격력 : %d\t방어력 : %d\n", Monster->Attack,
		Monster->Defense);
	printf("체력 : %d / %d\t마나 : %d / %d\n",
		Monster->HP, Monster->HPMax,
		Monster->MP, Monster->MPMax);
}
EBattleResult RunBattle(FMonsterInfo* Monster)
{
	int Damage = gPlayer->Attack - Monster->Defense;

	Damage = Damage > 0 ? Damage : 0;

	Monster->HP -= Damage;
	printf("Player가 Monster에게 %d 데미지를 주었습니다.\n", Damage);
	if (Monster->HP <= 0)
	{
		printf("Monster가 죽었습니다.\n");

		system("pause");
		return EBattleResult::MonsterDeath;
	}

	Damage = Monster->Attack - gPlayer->Defense;

	Damage = Damage > 0 ? Damage : 0;

	gPlayer->HP -= Damage;
	printf("Monster가 Player에게 %d 데미지를 주었습니다.\n", Damage);
	if (gPlayer->HP <= 0)
	{
		printf("Player가 죽었습니다.\n");

		system("pause");
		return EBattleResult::PlayerDeath;
	}

	return EBattleResult::None;
	
}

void CBattle::Run()
{
	gPlayer = new FPlayerInfo;
	gMonster = new FMonsterInfo;
	while (true)
	{
		system("cls");
		printf("================ Player ================\n");
		OutputPlayerBattle();

		printf("================ Monster ================\n");
		OutputMonsterBattle(gMonster);

		// 전투 메뉴
		printf("1. 공격\n");
		printf("2. 도망가기\n");
		printf("메뉴를 선택하세요 : ");
		int	Input;
		scanf_s("%d", &Input);

		if (Input < EBattleMenu::Attack || Input>EBattleMenu::Back)
			continue;
		switch (Input)
		{
		case EBattleMenu::Attack:
			RunBattle(gMonster);
			break;
		case EBattleMenu::Back:
			return;
		}
	}
}
