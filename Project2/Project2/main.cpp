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
	// 이 아래로 다른 접근제어 키워드를 만나기 전까지 모두 public이 된다.
	char	mName[32] = {};
	int		mAttack = 0;

private:
	int		mDefense = 0;
public:
	void Output()
	{
		printf("Name = %s\n", mName);
		printf("this = %p\n", this);
		printf("공격력 : %d\n", mAttack);
		printf("방어력 : %d\n", this->mDefense);
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