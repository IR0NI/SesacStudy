#pragma once
class Monster
{
};

struct FMonsterInfo
{
	char	Name[32] = {};
	int		Attack = 0;
	int		Defense = 0;
	int		HP = 0;
	int		HPMax = 0;
	int		MP = 0;
	int		MPMax = 0;
	int		Level = 1;

	// 아래 정보는 플레이어가 몬스터를 잡았을 때 획득할 수 있는 경험치와
	// 돈이다.
	int		Exp = 0;
	int		Gold = 0;
};