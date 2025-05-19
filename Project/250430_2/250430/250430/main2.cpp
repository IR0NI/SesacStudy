
#include <iostream>

void ChangeNumber(int Number)
{
	Number = 500;
}

void ChangeNumber(int* NumberAddr)
{
	*NumberAddr = 500;
}

struct FPlayerInfo
{
	char	Name[32] = {};
	int		Attack = 0;
};

void main()
{
	/*
	포인터 : 메모리 주소를 저장하기 위한 변수 타입이다.
	모든 변수 타입은 포인터 타입 변수를 선언할 수 있다.

	변수타입* 포인터변수이름;

	위의 형태로 포인터 변수를 선언할 수 있다.

	포인터타입의 메모리 크기는 x64일 때 8바이트 x86일 때 4바이트이다.

	역참조 : 포인터 변수가 가지고 있는 메모리 주소에 접근하여 해당 주소에 있는 값을
	변경하거나 가져와서 사용할 수 있게 해준다.
	*포인터변수명 = 100;
	
	위와 같이 포인터변수명 앞에 * 을 붙여 역참조를 한다.

	변수타입에 영향을 받아 해당 타입 변수의 메모리 주소를 저장할 수 있게 된다.
	단, void는 타입이 없다는 의미인데 일반 void타입 변수는 선언이 불가능하지만
	void* 타입 변수는 선언이 가능하여 모든 변수 타입의 메모리 주소를 저장할 수 있다.
	단, void*는 역참조가 불가능하다.
	*/
	float	Number1 = 3.14f;
	int		Number = 100;
	int* Address = nullptr;
	bool	Test1 = true;
	bool* Address1 = &Test1;

	//*Address = 200;

	Address = &Number;

	// Address는 Number변수의 메모리 주소를 가지고 있기 때문에 그 주소에 접근하여
	// 값을 1234로 변경한다. 즉, Number변수의 값이 1234로 변경된 것이다.
	*Address = 1234;

	ChangeNumber(Number);
	ChangeNumber(&Number);

	// float 타입 변수의 주소를 int* 타입에 대입해주기 때문에 에러가 발생한다.
	//Address = &Number1;
	// 아래와 같이 형변환을 하면 가능하다.
	//Address = (int*)&Number1;

	void* VoidAddress = &Number;
	VoidAddress = &Number1;
	VoidAddress = &Test1;

	//*VoidAddress = true;
	// 아래는 void*를 임시로 bool*로 변환시켜 인식시켜주기 때문에 역참조가 가능하다.
	*((bool*)VoidAddress) = true;

	printf("Number = %d\n", Number);

	// 변수 앞에 & 을 붙여주면 해당 변수의 메모리 주소를 의미한다.
	// %x : 16진수 출력. %8x : 16진수 8자리 출력
	// %p : 메모리 주소 출력
	printf("&Number = %p\n", &Number);
	printf("Address = %p\n", Address);
	printf("Address1 = %p\n", Address1);
	printf("*Address = %d\n", *Address);

	/*
	포인터와 배열의 관계
	배열 이름은 배열의 시작 메모리 주소를 의미한다.
	*/
	int	Array[100] = {};

	printf("%p\n", Array);

	// 배열 이름은 배열의 시작 메모리 주소이기 때문에 포인터 변수에
	// 해당 배열의 시작 메모리 주소를 저장할 수도 있다.
	int* ArrayAddress = Array;

	// 배열이름[인덱스] 로 접근하는것은 배열시작주소[인덱스]와 같다.
	Array[3] = 500;

	// 포인터변수도 배열의 시작 메모리 주소를 가지고 있기 때문에 인덱스를
	// 이용하여 배열에 접근할 수 있다.
	ArrayAddress[3] = 1111;

	printf("Array[3] = %d\n", Array[3]);

	/*
	포인터 연산 : +, -, ++, -- 4가지가 지원된다.
	포인터 연산은 일반적인 연산과 다르게 연산된다.
	1을 더하면 단순하게 메모리 주소에 1을 더하는 것이 아니라 포인터변수 타입의
	메모리 크기만큼을 더해주게 된다.
	2를 더하면 2 * 타입크기 만큼을 주소에 더해주게 되는 것이다.
	*/
	printf("Array = %p\n", Array);
	printf("&Array[0] = %p\n", &Array[0]);
	printf("ArrayAddress = %p\n", ArrayAddress);
	printf("ArrayAddress + 1 = %p\n", ArrayAddress + 1);
	printf("ArrayAddress + 3 = %p\n", ArrayAddress + 3);
	printf("&Array[3] = %p\n", &Array[3]);

	printf("*(ArrayAddress + 3) = %d\n", *(ArrayAddress + 3));
	printf("*ArrayAddress + 3 = %d\n", *ArrayAddress + 3);
	printf("Array[3] = %d\n", Array[3]);

	printf("%p\n", ArrayAddress);

	*++ArrayAddress = 500;

	printf("Array[0] = %d\n", Array[0]);
	printf("Array[1] = %d\n", Array[1]);

	printf("%p\n", ArrayAddress);

	/*printf("%p\n", ArrayAddress);
	printf("++ %p\n", ++ArrayAddress);
	printf("++ %p\n", ArrayAddress++);
	printf("%p\n", ArrayAddress);*/

	double	Test2 = 0.13;
	double* Test2Addr = &Test2;
	printf("Test2Addr = %p\n", Test2Addr);
	printf("Test2Addr + 1 = %p\n", Test2Addr + 1);

	/*
	포인터 변수도 const 키워드를 이용하여 상수로 만들 수 있다.
	const int* Addr : 참조하는 메모리 주소는 변경이 가능하지만 역참조를
	하여 값을 바꾸는 것은 불가능하다.
	int* const Addr : 처음 선언과 동시에 메모리 주소의 대입만 가능하고
	그 이후에는 다른 메모리 주소를 저장할 수 없다.
	const int* const Addr : 참조하는 대상도 변경할 수 없고 참조하는 대상의
	값도 변경할 수 없다.
	*/
	const int* cAddr = &Number;

	int		Number22 = 300;

	cAddr = &Number22;

	Number = *cAddr;

	//*cAddr = 2222;

	int* const	Addrc = &Number;

	//Addrc = &Number22;

	FPlayerInfo	Player;
	FPlayerInfo* PlayerAddr = &Player;

	Player.Attack = 500;

	//*PlayerAddr.Attack = 600;
	(*PlayerAddr).Attack = 600;

	// 위와 같이 동작한다. -> 는 포인터 변수가 가지고 있는 주소에 접근하여
	// 멤버변수를 사용할 수 있게 해준다.
	PlayerAddr->Attack = 600;
}