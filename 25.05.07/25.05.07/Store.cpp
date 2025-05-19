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
		printf("1. 무기상점\n");
		printf("2. 방어구상점\n");
		printf("3. 뒤로가기\n");
		printf("상점을 선택하세요 :	");
		int Input = 0;
		scanf_s("%d", &Input);

		if (Input <= EStoreType::None)
	}
}
