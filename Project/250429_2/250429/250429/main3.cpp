
#include <iostream>
#include <time.h>

/*
함수 : 코드를 모아서 원하는 부분에서 호출하여 동작시킬 수 있게 해주는 기능이다.

반환타입 함수이름(인자)
{
	동작할 코드
}

반환타입 : 이 함수가 코드를 동작시키고 결과를 만들어야 할 경우 지정하는 타입이다.
변수 타입을 작성하며 void를 작성하면 반환타입이 없다는 의미이다.

인자 : 이 함수를 사용(호출)할 때 함수에서 코드를 동작시키기 위해 필요한 데이터가 있을
경우 데이터를 전달해주기 위한 변수이다. 없을 수도 있고 여러개 혹은 1개일 수도 있다.

*/
void OutputFunction()
{
	printf("Output Function\n");
}

int Sum(int Number, int Number1)
{
	// return : 함수를 빠져나갈 때 사용한다. 반환타입이 있는 함수라면 return 뒤에
	// 이 함수가 반환할 결과를 넣어준다.
	// 반환타입이 void라면 return; 을 해줄 경우 함수의 어느 부분에서든 함수를 호출
	// 한 위치로 되돌아갈 수 있다.
	return Number + Number1;
}

// 함수안의 코드가 모두 실행되고 함수의 끝에 가거나 return을 만나게 되면 함수가 끝나며
// 함수에서 사용한 메모리는 모두 정리된다.
void ChangeNumber(int Number)
{
	int	Number1 = 200;
	Number = 500;
}

void SetNumber(int Num[25])
{
	for (int i = 0; i < 25; ++i)
	{
		Num[i] = i + 1;
	}
}

void OutputNumber(int Num[25])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d\t", Num[i * 5 + j]);
		}

		printf("\n");
	}
}

void main()
{
	srand(time(0));
	rand();

	int	Number[25] = {};

	// 배열 전체를 전달하는 경우 배열 이름만 작성한다.
	SetNumber(Number);

	OutputNumber(Number);
	OutputNumber(Number);
	OutputNumber(Number);

	// 함수호출 : 함수이름(인자에 전달해줄 값); 의 형태로 호출한다.
	OutputFunction();
	OutputFunction();
	OutputFunction();

	int	Num = Sum(10, 20);

	printf("Num = %d\n", Num);

	ChangeNumber(Num);

	printf("Num = %d\n", Num);
}
