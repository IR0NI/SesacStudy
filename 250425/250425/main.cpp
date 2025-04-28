
#include <iostream>

// 시간에 관련된 기능을 제공한다.
#include <time.h>

void main()
{
	srand(time(0));
	rand();
	///*
	//분기문 : 여러 조건 중 하나를 선택해서 동작시키는 방식이다.
	//if문과 switch문이 지원된다.
	//if (조건식)
	//{
	//	동작할 코드
	//}
	//조건식이 true일 경우 {}(코드블록)안에 있는 코드가 동작하고
	//false일 경우에는 건너뛴다.

	//else : 반드시 if문 아래에 사용해야 한다.
	//혼자 사용이 불가능하다.
	//else if 아래에 있어야 한다.
	//if문 1개에 1개의 else만 가능하다.
	//if문의 조건식이 false일 경우 else가 동작이 된다.

	//else
	//{
	//	동작할 코드
	//}

	//else if : 반드시 if문 아래에 사용해야 한다.
	//else보다는 위에 있어야 한다.
	//혼자 사용이 불가능하다.
	//if문 1개에 여러개의 else if 사용이 가능하다.

	//else if (조건식)
	//{
	//	동작할 코드
	//}
	//*/
	///*int	Number = 200;
	//{
	//	int	Number = 100;

	//	std::cout << Number;
	//}*/

	////std::cout << Number;
	//if (false)
	//{
	//	printf("if문 조건식이 true 입니다.\n");
	//}

	//else
	//{
	//	printf("if문 조건식이 false 입니다.\n");
	//}

	//int	BossHP = 57;

	//// 보스 체력이 20보다 작을 경우
	//// 보스 체력이 21 ~ 50 사이일 경우
	//// 보스 체력이 51 ~ 70 사이일 경우
	//// 71 이상일 경우
	//if (BossHP >= 71)
	//{
	//	printf("보스 체력이 71 이상입니다.\n");
	//}

	//else if (BossHP >= 51 && BossHP <= 70)
	//{
	//	printf("보스 체력이 51 ~ 70 사이입니다.\n");
	//}

	//else if (BossHP >= 21 && BossHP <= 50)
	//{
	//	printf("보스 체력이 21 ~ 50 사이입니다.\n");
	//}

	//else
	//{
	//	printf("보스 체력이 20 이하입니다.\n");
	//}


	//if (BossHP >= 71)
	//{
	//	printf("보스 체력이 71 이상입니다.\n");
	//}

	//else if (BossHP >= 51)
	//{
	//	printf("보스 체력이 51 ~ 70 사이입니다.\n");
	//}

	//else if (BossHP >= 21)
	//{
	//	printf("보스 체력이 21 ~ 50 사이입니다.\n");
	//}

	//else
	//{
	//	printf("보스 체력이 20 이하입니다.\n");
	//}

	///*if (true)
	//{
	//}

	//if (true) {

	//}

	//if (true) {}*/


	///*if (int Num1 = 500)
	//{
	//}*/

	//// rand() : 난수를 만들어준다.
	//printf("Rand : %d\n", rand());
	//printf("Rand : %d\n", rand());
	//printf("Rand : %d\n", rand());
	//printf("Rand : %d\n", rand());

	//// 난수가 0 ~ 100 사이의 난수가 나와야 한다.
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);

	//// 100 ~ 400 사이의 난수
	//// 최소값 : 100 최대값 : 400 구간값 : 300
	//// 난수 % (구간값 + 1) + 최소값
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);

	//int RandomNumber = rand() % 301 + 100;

	//// 200 ~ 400 사이의 난수
	//// 난수 % 201 + 200

	//// 0 ~ 100 사이의 소수점 둘째자리까지 확률을 구한다.
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);

	//// 0 ~ 100 사이의 소수점 네번째 자리까지 확률을 구한다.
	//float Result = rand() % 101;

	//// rand() % 10001 : 0 ~ 10000 사이의 값이 나온다.
	//// 0 ~ 10000 사이의 값을 10000.f 으로 나누게 되면
	//// 0 ~ 1 사이의 소수점 4번째자리까지 구해주게 된다.
	//float Percent = rand() % 10001 / 10000.f;

	//Result += Percent;

	//printf("Rand : %.4f\n", Result);

	//int	Grade = 0;

	//// scanf_s : 콘솔창에서 입력받을때 사용하는 함수이다.
	//// %d를 하면 정수를 입력받겠다는 의미이다.
	////printf("등급을 입력하세요 : ");
	////scanf_s("%d", &Grade);

	//////std::cin >> Grade;

	////// 등급이 0 ~ 3 사이 100% 성공
	////// 등급이 4 ~ 6 사이 50% 성공
	////// 등급이 7 ~ 9 사이 10% 성공
	////// 등급이 10 ~ 12 사이 1% 성공
	////// 등급이 13 이상일 경우 0.05% 성공
	////Percent = rand() % 10001 / 100.f;

	////float	Percent1 = rand() % 10001 / 100.f;

	////printf("Percent : %.2f\n", Percent);
	////printf("Percent1 : %.2f\n", Percent1);

	////if (0 <= Grade && Grade <= 3)
	////{
	////	//++Grade;
	////	if (Percent1 <= 20.f)
	////		Grade += 2;

	////	else
	////		Grade++;
	////	printf("강화 성공 : %d\n", Grade);
	////}

	////else if (Grade <= 6)
	////{
	////	if (Percent <= 50.f)
	////	{
	////		if (Percent1 <= 20.f)
	////			Grade += 2;

	////		else
	////			Grade++;
	////		printf("강화 성공 : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("강화 실패\n");
	////	}
	////}

	////else if (Grade <= 9)
	////{
	////	if (Percent <= 10.f)
	////	{
	////		if (Percent1 <= 20.f)
	////			Grade += 2;

	////		else
	////			Grade++;
	////		printf("강화 성공 : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("강화 실패\n");
	////	}
	////}

	////else if (Grade <= 12)
	////{
	////	if (Percent <= 1.f)
	////	{
	////		if (Percent1 <= 20.f)
	////			Grade += 2;

	////		else
	////			Grade++;
	////		printf("강화 성공 : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("강화 실패\n");
	////	}
	////}

	////else if (Grade >= 13)
	////{
	////	if (Percent <= 0.05f)
	////	{
	////		if (Percent1 <= 20.f)
	////			Grade += 2;

	////		else
	////			Grade++;
	////		printf("강화 성공 : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("강화 실패\n");
	////	}
	////}

	////else
	////{
	////	printf("잘못된 등급입니다.\n");
	////}

	///*
	//치명타 확률을 정한다.
	//퍼센트를 구하고 치명타확률 안에 들어오면
	//최소공격력 ~ 최대공격력 사이의 최종 공격력을 구해서 치명타 계수를
	//적용하여 데미지를 구한다.
	//*/
printf("----------------\n");
int Critical = 0;
printf("공격력 : 100 ~ 200\n치명타 확률을 정하시오 : ");

scanf_s("%d", &Critical);

for (int i = 0; i < 10; i++)
{
	int Percent3 = rand() % 101;
	int Attack = rand() % 101 + 100;
	printf("공격력 : %d\n", Attack);
	
	if (Critical >= Percent3)
	{
		printf("데미지 : %d\n", Attack * 2);
	}
	else
	{
		printf("데미지 : %d\n", Attack);
	}
	printf("----------------\n");
}

}