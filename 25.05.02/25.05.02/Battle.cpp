#include "Battle.h"

bool BattleInit()
{
	return false;
}

void RunMap()
{
	while (true)
	{
		//���� �޴��� �����ְ� �����Ѵ�.
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
			break;
		case EMapMenu::Normal:
			break;
		case EMapMenu::Hard:
			break;
		case EMapMenu::Back:
			break;

		}
	}
}
