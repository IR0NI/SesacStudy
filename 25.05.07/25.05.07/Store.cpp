#include "Store.h"


namespace EStoreType
{
	enum Type
	{
		None,

	};
}

FItem* gWeaponStore = nullptr;
int		gWeaponStoreCount = 0;
FItem* gArmorStore = nullptr;
int		gArmorStoreCount = 0;

bool StoreInit()
{

	FItem* ItemList = nullptr;
	return true;
}

void RunStore()
{
	while (true)
	{
		system("cls");
		printf("1. �������\n");
		printf("2. ������\n");
		printf("3. �ڷΰ���\n");
		printf("������ �����ϼ��� :	");
		int Input = 0;
		scanf_s("%d", &Input);

		if (Input <= EStoreType::None)
	}
}
