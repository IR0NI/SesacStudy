
#include <iostream>
#include <time.h>

/*
구조체 : 다양한 타입의 변수를 하나로 묶어서 사용할 수 있게 해주는 사용자정의 
변수 타입이다.

struct 구조체명
{
	변수 선언.
};
*/
enum class EPlayerJob : unsigned char
{
	None,
	Knight,
	Archer,
	Magicion
};

struct FPlayerInfo
{
	char		Name[32] = {};
	EPlayerJob	Job = EPlayerJob::None;
	int			Attack = 0;
	int			Defense = 0;
	int			HP = 0;
	int			HPMax = 0;
	int			MP = 0;
	int			MPMax = 0;
	int			Level = 1;
	int			Exp = 0;
	int			Gold = 0;
};

struct FTest
{
	char		Test1;
};

struct FTest1
{
	int			Test1;
};

struct FTest2
{
	__int64		Test1;
};

struct FTest3
{
	char		Test1;
	char		Test3;
	int			Test2;
};

struct FTest4
{

};

enum class EItemType : unsigned char
{
	Weapon,
	Armor
};

struct FItem
{
	char	Name[32] = {};
	EItemType	Type = EItemType::Weapon;
	int		Option = 0;
	int		Price = 0;
	int		Sell = 0;
};


void main()
{
	// 구조체 선언 뒤에 = {} 을 해주면 구조체 전체를 0으로 초기화한다.
	FPlayerInfo	Info = {};

	FPlayerInfo	Info1 = { "Player" };
	
	FPlayerInfo	InfoArray[10] = {};

	FItem	Inventory[20] = {};

	InfoArray[0].Attack = 300;

	// 구조체타입의 변수에 . 을 붙여 멤버변수에 접근할 수 있다.
	Info.Attack = 500;

	// sizeof(변수타입 혹은 변수) 를 해주면 해당 타입의 바이트 수를 반환한다.
	// (int) 를 해주어 int타입으로 형변환 해준다.
	printf("Ftest Size : %d\n", (int)sizeof(FTest));
	printf("Ftest1 Size : %d\n", (int)sizeof(FTest1));





	// 문자열의 끝은 항상 0으로 되어 있어야 한다.
	// 배열이 32개짜리면 실제로 31개만 저장이 가능하다.
	//char	Name[32] = {};
	//Name[0] = 'a';
	//Name[1] = 'b';
	//Name[2] = 'c';
	////Name[3] = 0;

	//// %s : 문자열을 받아온다.
	//printf("%s", Name);
}