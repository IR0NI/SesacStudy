
#include <iostream>

struct FPlayer
{
	char	Name[32] = {};
	int		Attack = 0;
};

/*
인스턴스, 인터페이스라는 용어를 많이 사용한다.
인스턴스 : 실제 메모리에 할당되는 변수.

객체 : 모든 물체를 객체라고 할 수 있다. 프로그래밍에서는 클래스, 구조체 등을
이용하여 생성한 변수를 말한다.

객체지향 프로그래밍 : 객체를 조립하여 하나의 완성된 프로그램을 만드는 방식을
말한다.

컴포넌트 : 객체를 꾸며주기 위한 부품.

클래스 : 객체지향 프로그래밍을 지원해주기 위한 수단이다. 객체를 만들기 위한
수단일뿐 클래스가 객체는 아니다.

class 클래스이름
{
	멤버변수
	멤버함수
};

언리얼엔진에서 클래스 이름 앞에 A, U 2가지가 붙는다.
A : Actor
U : UObject
일반클래스를 만들경우 C를 붙여 만들어준다.

캡슐화 : 여러 멤버변수나 멤버함수를 모아주는 기능을 제공한다.
은닉화 : 멤버의 공개 수준을 설정할 수 있다.
클래스내부 : 클래스의 멤버함수 안
클래스외부 : 클래스의 멤버함수 안이 아닌 모든곳
- public : 클래스 내부와 외부에 모두 공개한다. 구조체는 아무것도 붙여주지
않을 경우 기본으로 public이다.
- private : 클래스 내부에서는 접근이 가능하지만 외부에서는 접근이 불가능하다.
클래스는 아무것도 붙여주지 않을 경우 기본으로 private이다.
- protected : 상속 할 때 다시 설명.
상속성 : 상속 할 때 다시 설명.
다형성 : 상속 할 때 다시 설명.

클래스의 메모리 크기는 멤버변수의 크기와 동일하다. 단, 상속을 사용하면서
가상함수를 사용할 경우 다르게 나온다.
멤버함수는 클래스를 이용하여 생성한 객체의 메모리 크기에 영향을 주지 않는다.
*/
class CPlayer
{
	/*
	생성자와 소멸자는 클래스 이름과 같은 이름의 함수이다.
	반환 타입 없이 이름과 인자만으로 선언한다.
	생성자는 오버로딩이 가능하지만 소멸자는 인자 없는 형태만 존재한다.
	생성자 : 이 클래스를 이용해서 객체를 생성할 때 자동으로 호출이 되는
	함수이다.
	소멸자 : 이 클래스를 이용해서 생성한 객체가 메모리에서 제거될 때 자동으로
	호출이 되는 함수이다.
	*/
public:
	// 생성자
	// 이니셜라이저를 이용해서 멤버변수의 값을 선언과 동시에 초기화할 수 있다.
	CPlayer()	:
		mAttack(20),
		mDefense(10),
		mName("apple")
	{
		// 아래는 mAttack 변수가 선언이 된 후에 50을 대입한다.
		mAttack = 50;
		printf("CPlayer 생성자\n");
	}

	CPlayer(const char* Name)	:
		mAttack(30),
		mDefense(40)
		//mName(Name)
	{
		printf("CPlayer const char* 생성자\n");
	}

	/*
	복사생성자 : 다른 객체를 복사한 새로운 객체를 만들 때 사용한다.
	생성자의 인자로 const 클래스타입& 타입을 사용한다.

	복사방법은 얕은복사, 깊은복사 2가지가 있다.
	얕은복사 : 클래스의 데이터를 그대로 복사한다.
	깊은복사 : 클래스에 동적할당된 데이터가 있을 경우 똑같은 크기의 공간을
	만들어주고 데이터만 복사하는 방식이다. 일반 데이터는 얕은복사와 같이
	그대로 복사한다.

	이동생성자 : 다른 객체가 가지고 있는 내용을 새로운 객체로 옮겨주면서
	객체를 만들 때 사용한다.
	클래스타입&&

	&& : 변수 타입에 && 가 붙으면 rvalue reference(우측값 참조)라고 한다.
	임시값을 참조할 수 있게 해주는 타입이다.
	*/
	CPlayer(const CPlayer& Ref)// :
		//mAttack(Ref.mAttack),
		//mDefense(Ref.mDefense)
		//mName(Ref.mName)
	{
		// 모든 멤버변수의 값을 그대로 복사한다.
		// 얕은복사가 일어난다.
		*this = Ref;
	}

	// 소멸자
	~CPlayer()
	{
		printf("CPlayer 소멸자\n");
	}

public:
	// 이 아래로 다른 접근제어 키워드를 만나기 전까지 모두 public이 된다.
	char	mName[32] = {};
	int		mAttack = 0;

private:
	int		mDefense = 0;

public:
	// 클래스의 일반 멤버함수(일반멤버함수, 생성자, 소멸자) 내부에서는
	// this를 사용할 수 있다.
	// this는 자기 자신의 메모리 주소이다.
	// Player1.Output() 이런식으로 클래스의 멤버함수를 호출할 때 객체를
	// 이용해서 호출하게 되는데 Player1.Output() 으로 호출하면 호출하는
	// 순간 this는 Player1의 주소를 가지게 되고 Player2.Output() 으로
	// 호출하면 호출하는 순간 this는 Player2의 주소를 가지게 된다.
	// 멤버함수 내부에서 클래스 멤버변수를 사용하게 되면 앞에 this-> 가 
	// 생략된 것이다.
	void Output()
	{
		printf("Name = %s\n", mName);
		printf("this = %p\n", this);
		printf("공격력 : %d\n", mAttack);
		printf("방어력 : %d\n", this->mDefense);
		//printf("this Addr = %p\n", &this);
	}

	void OutputTest()
	{
		printf("OutputTest Function\n");
	}
};

class CCopyTest
{
public:
	CCopyTest()
	{
		mArray = new int[10];

		// 메모리를 원하는 값으로 채워줄 때 사용한다.
		// 단, 채우는 단위는 바이트 단위로 값을 채워준다.
		// 1번인자의 메모리를 2번인자의 값으로 3번인자의 크기만큼
		// 채워준다.
		memset(mArray, 0, sizeof(int) * 10);
		printf("CCopyTest 생성자\n");
	}

	CCopyTest(const CCopyTest& Ref)
	{
		//*this = Ref;
		mNumber = Ref.mNumber;
		printf("CCopyTest 복사생성자\n");

		// 동적할당된 데이터를 소멸자에서 제거하고 있으므로 깊은 복사를
		// 이용해서 처리한다.
		mArray = new int[10];

		// 메모리를 복사할 때 사용한다.
		// 1번인자의 주소에 2번인자의 주소로부터 3번인자에 들어가는
		// 바이트 수만큼을 복사해준다.
		memcpy(mArray, Ref.mArray, sizeof(int) * 10);
		/*for (int i = 0; i < 10; ++i)
		{
			mArray[i] = Ref.mArray[i];
		}*/
	}

	// 이동 생성자
	CCopyTest(CCopyTest&& Ref)
	{
		printf("CCopyTest 이동생성자\n");
		mNumber = Ref.mNumber;
		mArray = Ref.mArray;
		Ref.mArray = nullptr;
	}

	~CCopyTest()
	{
		printf("CCopyTest 소멸자\n");
		if (mArray != nullptr)
			delete[] mArray;
	}

public:
	int	mNumber = 0;
	int* mArray = nullptr;
};

void OutputPlayer(FPlayer* Player)
{
	printf("공격력 : %d\n", Player->Attack);
}

void TestRValue(CCopyTest Copy)
{
}

int main()
{
	//FPlayer	Player;

	//Player.Attack = 10;

	//OutputPlayer(&Player);

	//CPlayer	Player1, Player2("이름");

	//printf("Player1 = %p\n", &Player1);
	//printf("Player2 = %p\n", &Player2);

	//// Output 멤버함수는 Player1과 Player2 모두 동일한 주소의 함수를
	//// 사용하게 된다. 그런데 멤버함수에서 정확하게 Player1과 Player2의
	//// 멤버변수의 값을 인식하고 사용할 수 있다.
	//Player1.mAttack = 100;
	//Player1.Output();

	//// 복사생성자가 호출된다.
	//CPlayer	PlayerCopy(Player1);

	//Player2.mAttack = 300;
	//Player2.Output();

	//CPlayer* Player3 = nullptr;

	////Player3->Output();
	//Player3->OutputTest();

	////printf("Player Size = %d\n", sizeof(CPlayer));

	//// Number는 lvalue
	//int	Number = 10;

	//// Number + 10 : rvalue
	//// Number + 10을 한 결과를 저장하기 위한 임시 저장공간을 만들고
	//// 거기에 결과를 저장한 후에 lvalue에 대입해준다.
	//int	Result = Number + 10;

	////int& Ref = Number + 10;
	//int&& Ref = Number + 10;

	////CPlayer	Player4 = CPlayer();

	//system("cls");

	//CCopyTest	Test;
	//CCopyTest	TestCopy(Test);

	//// 1바이트 단위로 값을 채우게 된다.
	//// int는 4바이트 이므로 1바이트 단위로 1을 채우게 되면
	//// 0000 0001 0000 0001 0000 0001 0000 0001
	//memset(&Number, 1, sizeof(int));

	//printf("Number = %d\n", Number);


	system("cls");

	//CCopyTest	Test1(CCopyTest());
	//TestRValue(CCopyTest());
	CCopyTest	Test1 = std::move(CCopyTest());
	//CCopyTest	Test2 = std::move(Test1);

	printf("-----------------\n");

	return 0;
}