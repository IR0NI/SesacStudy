
#include "Store.h"

namespace EStoreType
{
	enum Type
	{
		None,
		Weapon,
		Armor,
		Back,
		End
	};
}

FItem* gWeaponStore = nullptr;
int		gWeaponStoreCount = 0;
FItem* gArmorStore = nullptr;
int		gArmorStoreCount = 0;

bool StoreInit()
{
	FILE* File = nullptr;

	fopen_s(&File, "ItemList.itl", "rb");

	if (!File)
		return false;

	int	ItemListCount = 0;

	fread(&ItemListCount, sizeof(int), 1, File);

	FItem* ItemList = new FItem[ItemListCount];

	for (int i = 0; i < ItemListCount; ++i)
	{
		fread(&ItemList[i], sizeof(FItem), 1, File);

		// �о�� �������� �������� �������� ���� ������ �߰��س��´�.
		if (ItemList[i].ItemType == EItemType::Weapon)
			++gWeaponStoreCount;

		else if (ItemList[i].ItemType == EItemType::Armor)
			++gArmorStoreCount;
	}

	fclose(File);

	if (gWeaponStoreCount > 0)
	{
		gWeaponStore = new FItem[gWeaponStoreCount];

		int	Index = 0;

		// ��ü ������ ����ŭ �ݺ��ϸ� ���⸦ ã�Ƽ� ��������� �־��ش�.
		for (int i = 0; i < ItemListCount; ++i)
		{
			if (ItemList[i].ItemType == EItemType::Weapon)
			{
				gWeaponStore[Index] = ItemList[i];
				++Index;
			}
		}
	}

	if (gArmorStoreCount > 0)
	{
		gArmorStore = new FItem[gArmorStoreCount];

		int	Index = 0;

		// ��ü ������ ����ŭ �ݺ��ϸ� ���⸦ ã�Ƽ� ��������� �־��ش�.
		for (int i = 0; i < ItemListCount; ++i)
		{
			if (ItemList[i].ItemType == EItemType::Armor)
			{
				gArmorStore[Index] = ItemList[i];
				++Index;
			}
		}
	}

	SAFE_DELETE_ARRAY(ItemList);

	return true;
}

void StoreDestroy()
{
	SAFE_DELETE_ARRAY(gWeaponStore);
	SAFE_DELETE_ARRAY(gArmorStore);
}

void OutputStore(EStoreType::Type StoreType)
{
	switch (StoreType)
	{
	case EStoreType::Weapon:
		printf("============== ������� ==============\n");
		for (int i = 0; i < gWeaponStoreCount; ++i)
		{
			printf("%d. %s\n", i + 1, gWeaponStore[i].Name);
		}

		printf("%d. �ڷΰ���\n", gWeaponStoreCount + 1);
		break;
	case EStoreType::Armor:
		printf("============== ������ ==============\n");
		for (int i = 0; i < gArmorStoreCount; ++i)
		{
			printf("%d. %s\n", i + 1, gArmorStore[i].Name);
		}

		printf("%d. �ڷΰ���\n", gArmorStoreCount + 1);
		break;
	}
}

void RunStore(EStoreType::Type StoreType)
{
	FItem* StoreItemList = nullptr;
	int		StoreItemCount = 0;

	switch (StoreType)
	{
	case EStoreType::Weapon:
		StoreItemList = gWeaponStore;
		StoreItemCount = gWeaponStoreCount;
		break;
	case EStoreType::Armor:
		StoreItemList = gArmorStore;
		StoreItemCount = gArmorStoreCount;
		break;
	}

	while (true)
	{
		system("cls");

		OutputStore(StoreType);

		printf("������� : %d\n", gPlayer->Gold);
		printf("������ �������� �����ϼ��� : ");
		int	Input = 0;
		scanf_s("%d", &Input);

		if (Input <= 0 || Input > StoreItemCount + 1)
			continue;

		else if (Input == StoreItemCount + 1)
			return;

		// ������ ������ ��ȣ�� ������ �ε����� �����Ѵ�.
		int	StoreIndex = Input - 1;

		// �÷��̾ ������ �ݾ��� �������� üũ�Ѵ�.
		if (gPlayer->Gold < StoreItemList[StoreIndex].Price)
		{
			printf("�����ݾ��� �����մϴ�.\n");
			system("pause");
			continue;
		}

		// �κ��丮�� ������ �ִ��� üũ�Ѵ�.
	}
}

void RunStore()
{
	while (true)
	{
		system("cls");
		printf("1. �������\n");
		printf("2. ������\n");
		printf("3. �ڷΰ���\n");
		printf("������ �����ϼ��� : ");
		int	Input = 0;
		scanf_s("%d", &Input);

		if (Input <= EStoreType::None || Input >= EStoreType::End)
			continue;

		switch (Input)
		{
		case EStoreType::Weapon:
			RunStore(EStoreType::Weapon);
			break;
		case EStoreType::Armor:
			RunStore(EStoreType::Armor);
			break;
		case EStoreType::Back:
			return;
		}
	}
}
