#include <iostream>

struct FPlayer
{
	char Name[32] = {};
	int  Attack = 0;
};
class CPlayer
{
public:
	CPlayer() :
	mAttack(20),
	mDefense(10)
	{

	}
	CPlayer(const char* Name) :
		mAttack(30),
		mDefense(40)
	{

	}
	~CPlayer()
	{

	}
public:
	// �� �Ʒ��� �ٸ� �������� Ű���带 ������ ������ ��� public�� �ȴ�.
	char	mName[32] = {};
	int		mAttack = 0;

private:
	int		mDefense = 0;
public:
	void Output()
	{
		printf("Name = %s\n", mName);
		printf("this = %p\n", this);
		printf("���ݷ� : %d\n", mAttack);
		printf("���� : %d\n", this->mDefense);
	}
	void OutputTest()
	{
		printf("outputtest\n");
	}
};

int main()
{
	CPlayer player;
	player.OutputTest();
	return 0;
}