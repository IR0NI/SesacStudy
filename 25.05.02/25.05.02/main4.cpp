#include <iostream>
#include "GameInfo.h"
#include "GameManager.h"

int main()
{
	//GameInit();
	if (GameInit() == false)
	{
		GameDestroy();
		return 0;
	}

	Run();

	GameDestroy();
	/*int* Num = new int;
	if (Num) { delete Num; Num = nullptr; }
	SAFE_DELETE(Num);

	if (Num) { delete Num; Num = nullptr; }
	SAFE_DELETE(Num);*/

	return 0;
}