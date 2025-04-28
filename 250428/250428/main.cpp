#include <iostream>




void main()
{

	/*
	for(초기값; 조건식; 증감값)
	{
		동작할 코드
	}
	*/
	// 1 - 100까지 숫자중 3과 5의 공배수만 출력하는 for문을 만들어보시오
	for (int i = 0; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("%d\n", i);
		}
		
	}

	// 중첩for문 : for문 안에 또 다른 for문이 들어가는 형태이다.
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			
			// printf("i = %d j = %d\n", i, j);
			// i와 j의 값을 이용하여 0 - 49까지 출력되는 printf를 만들어보시오.
			// 세로번호 * 가로개수 + 가로번호
			printf("%d\n", i*10+j);
		}

	}

	// 구구단 2단 - 9단까지 출력하기
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			printf("%d X %d = %d\n", i, j, i * j);
		}
	}

	// 숫자를 입력받아 2단부터 입력받은 단까지 출력하는 코드를 만들어보시오.
	int num = 0;
	printf("숫자를 입력하시오 : ");
	scanf_s("%d", &num);
	for (int i = 2; i <= num; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			printf("%d X %d = %d\n", i, j, i * j);
		}
	}

	//printf("*");
	// 아래의
	/*
*
**
***
****
*****
*/

/*
*****
****
***
**
*
*/

/*
	*
   ***
  *****
 *******
*********
*/
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	printf("\n");
	printf("\n");
	printf("\n");

	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		for (int a = 5; a > i ; a--)
		{
			printf(" ");
		}
		
		for (int j = 0; j < 2*i-1; j++)
		{
			printf("*");
		}

		
		printf("\n");
	}
	/*
	while문
	while (조건식)
	{
		동작할 코드
	}
	조건식이 true일 경우 코드가 동작되고 false일 경우 while문을 빠져나온다.
	*/
	
	// 별을 이용하여 만든형태를 while문을 이용해서 만들어보시오.

	int i = 0;
	while (i < 5)
	{
		i++;
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");

	}
	printf("------------------\n");
	i = 6;
	while (i > 0)
	{
		i--;
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("------------------\n");
	i = 0;
	while (i < 5)
	{
		i++;
		for (int a = 6; a>i ;a--)
		{
			printf(" ");
		}
		for (int j = 0; j < 2*i-1; j++)
		{
			printf("*");
		}
		printf("\n");

	}
}