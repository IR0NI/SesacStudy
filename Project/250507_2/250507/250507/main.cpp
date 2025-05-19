
#include "GameInfo.h"
#include "GameManager.h"

int main()
{
	if (GameInit() == false)
	{
		GameDestroy();
		return 0;
	}

	Run();

	GameDestroy();
}
