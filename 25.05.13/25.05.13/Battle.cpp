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
	///*printf("�̸� : %s\t���� : ", gPlayer->Name);

	//switch (gPlayer->Job)
	//{
	//case EPlayerJob::Knight:
	//	printf("���\n");
	//	break;
	//case EPlayerJob::Archer:
	//	printf("�ü�\n");
	//	break;
	//case EPlayerJob::Magicion:
	//	printf("������\n");
	//	break;
	//}*/

	printf("���� : %d\t����ġ : %d\n", gPlayer->Level,
		gPlayer->Exp);
	printf("���ݷ� : %d\t���� : %d\n", gPlayer->Attack,
		gPlayer->Defense);
	printf("ü�� : %d / %d\t���� : %d / %d\n",
		gPlayer->HP, gPlayer->HPMax,
		gPlayer->MP, gPlayer->MPMax);
	printf("��� : %d\n", gPlayer->Gold);

	//printf("�������� : ");
	//if (gPlayer->EquipItem[EEquip::Weapon])
	//	printf("%s\t", gPlayer->EquipItem[EEquip::Weapon]->Name);
	//else
	//	printf("����\t");

	//printf("������ : ");
	//if (gPlayer->EquipItem[EEquip::Armor])
	//	printf("%s\t", gPlayer->EquipItem[EEquip::Armor]->Name);
	//else
	//	printf("����\t");
	//	
}

void OutputMonsterBattle(FMonsterInfo* Monster)
{
	printf("�̸� : %s\t���� : %d\n", Monster->Name,
		Monster->Level);

	printf("ȹ�����ġ : %d\tȹ���� : %d\n", Monster->Exp,
		Monster->Gold);
	printf("���ݷ� : %d\t���� : %d\n", Monster->Attack,
		Monster->Defense);
	printf("ü�� : %d / %d\t���� : %d / %d\n",
		Monster->HP, Monster->HPMax,
		Monster->MP, Monster->MPMax);
}
EBattleResult RunBattle(FMonsterInfo* Monster)
{
	int Damage = gPlayer->Attack - Monster->Defense;

	Damage = Damage > 0 ? Damage : 0;

	Monster->HP -= Damage;
	printf("Player�� Monster���� %d �������� �־����ϴ�.\n", Damage);
	if (Monster->HP <= 0)
	{
		printf("Monster�� �׾����ϴ�.\n");

		system("pause");
		return EBattleResult::MonsterDeath;
	}

	Damage = Monster->Attack - gPlayer->Defense;

	Damage = Damage > 0 ? Damage : 0;

	gPlayer->HP -= Damage;
	printf("Monster�� Player���� %d �������� �־����ϴ�.\n", Damage);
	if (gPlayer->HP <= 0)
	{
		printf("Player�� �׾����ϴ�.\n");

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

		// ���� �޴�
		printf("1. ����\n");
		printf("2. ��������\n");
		printf("�޴��� �����ϼ��� : ");
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
