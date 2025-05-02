#pragma once

#include "GameInfo.h"

namespace EMainMenu
{
	enum Type
	{
		None,
		Battle,
		Store,
		Inventory,
		Exit,
		End
	};
}

// ��ü ������ �ʱ�ȭ�ϴ� �Լ�.
bool GameInit();

// ��ü ������ �������ִ� �Լ�
void Run();

// ������ ����� �� ȣ��Ǵ� �Լ�.
void GameDestroy();
