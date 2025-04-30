#include <iostream>

struct FPlayerInfo
{
	char	Name[32] = {};
	int		Attack = 0;
};

void ChangeNumber(float* Number)
{
	*Number = 5.01f;
}

void main()
{

	///*
	//포인터 : 메모리 주소를 저장하기 위한 변수 타입이다.
	//모든 변수 타입은 포인터 타입 변수를 선언할 수 있다.
	//변수타입* 포인터변수이름;
	//
	//위의 형태로 포인터 변수를 선언할 수 있다.

	//포인터타입의 메모리 크기는 x64일 때 8바이트 x86일 때 4바이트이다.

	//역참조 : 포인터 변수가 가지고 있는 메모리 주소에 접근하여 해당 주소에 있는 값을 변경하거나 가져와서
	//사용할 수 있게 해준다.
	//*포인터변수명 = 100;
	//
	//위와 같이 포인터변수명 앞에 * 을 붙여 역참조를 한다.


	//변수타입에 영향을 받아 해당 타입 변수의 메모리 주소를 저장할 수 있게 된다.
	//단, void는 타입이 없다는 의미인데 일반 void 타입 변수는 선언이 불가능하지만
	//void* 타입 변수는 선언이 가능하여 모든 변수 타입의 메모리 주소를 저장할 수 있다.
	//단, void*는 역참조가 불가능하다
	//*/
	//float Number = 100.1f;
	//float* Address = nullptr;

	//printf("Number : %5f\n", Number);
	//Address = &Number;
	//*Address = 10.1f;
	//printf("Number : %f\n", Number);
	//ChangeNumber(&Number);
	//printf("Number : %f\n", Number);

	//bool Test = true;
	//bool* Address1 = &Test;
	//void* VoidAddress = &Number;
	//VoidAddress = &Number;
	//VoidAddress = &Test;
	//*((bool*)VoidAddress) = true;

	//printf("Test : %d\n", Test);

	//printf("&Number : %p\n", &Number);
	//printf("*Address : %f\n", *Address);

	//int Array[100] = {};
	///*printf("%p\n", Array);*/
	//int* ArrayAddress = Array;
	//Array[3] = 500;
	///*printf("Array[3] : %d\n", Array[3]);*/
	//ArrayAddress[3] = 1000;
	///*printf("Array[3] : %d\n", Array[3]);*/
	///*printf("ArrayAddress[3] : %d\n", ArrayAddress[3]);*/
	//printf("Array = %p\n", Array);
	//printf("&Array[0] = %p\n", &Array[0]);
	//printf("ArrayAddress = %p\n", ArrayAddress);
	//printf("ArrayAddress + 1 = %p\n", ArrayAddress + 1);
	//printf("ArrayAddress + 3 = %p\n", ArrayAddress + 3);
	//printf("&Array[3] = %p\n", &Array[3]);

	//printf("*(ArrayAddress + 3) = %d\n", *(ArrayAddress + 3));
	//printf("*ArrayAddress + 3 = %d\n", *ArrayAddress + 3);
	//printf("Array[3] = %d\n", Array[3]);

	//printf("%p\n", ArrayAddress);

	//*++ArrayAddress = 500;

	//printf("Array[0] = %d\n", Array[0]);
	//printf("Array[1] = %d\n", Array[1]);

	//printf("%p\n", ArrayAddress);

	//printf("%p\n", ArrayAddress);
	//printf("++ %p\n", ++ArrayAddress);
	//printf("++ %p\n", ArrayAddress--);
	//printf("%p\n", ArrayAddress);

	//int a = 10;
	//printf("a : %d\n", a);
	//printf("++a : %d\n", ++a);
	//printf("a+10 : %d\n", a+10);
	//printf("a : %d\n", a);

	//double	Test2 = 0.13;
	//double* Test2Addr = &Test2;
	//printf("Test2Addr = %p\n", Test2Addr);
	//printf("Test2Addr + 1 = %p\n", Test2Addr + 1);
	/*
	포인터 변수도 const 키워드를 이용하여 상수로 만들 수 있다.
	const int* Addr : 참조하는 메모리 주소는 변경이 가능하지만 역참조를
	하여 값을 바꾸는 것은 불가능하다.
	int* const Addr : 처음 선언과 동시에 메모리 주소의 대입만 가능하고
	그 이후에는 다른 메모리 주소를 저장할 수 없다.
	const int* const Addr : 참조하는 대상도 변경할 수 없고 참조하는 대상의
	값도 변경할 수 없다.
	*/
	int Number = 500;

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