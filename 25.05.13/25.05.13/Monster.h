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

	// �Ʒ� ������ �÷��̾ ���͸� ����� �� ȹ���� �� �ִ� ����ġ��
	// ���̴�.
	int		Exp = 0;
	int		Gold = 0;
};