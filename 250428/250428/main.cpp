#include <iostream>




void main()
{

	/*
	for(�ʱⰪ; ���ǽ�; ������)
	{
		������ �ڵ�
	}
	*/
	// 1 - 100���� ������ 3�� 5�� ������� ����ϴ� for���� �����ÿ�
	for (int i = 0; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("%d\n", i);
		}
		
	}

	// ��øfor�� : for�� �ȿ� �� �ٸ� for���� ���� �����̴�.
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			
			// printf("i = %d j = %d\n", i, j);
			// i�� j�� ���� �̿��Ͽ� 0 - 49���� ��µǴ� printf�� �����ÿ�.
			// ���ι�ȣ * ���ΰ��� + ���ι�ȣ
			printf("%d\n", i*10+j);
		}

	}

	// ������ 2�� - 9�ܱ��� ����ϱ�
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			printf("%d X %d = %d\n", i, j, i * j);
		}
	}

	// ���ڸ� �Է¹޾� 2�ܺ��� �Է¹��� �ܱ��� ����ϴ� �ڵ带 �����ÿ�.
	int num = 0;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d", &num);
	for (int i = 2; i <= num; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			printf("%d X %d = %d\n", i, j, i * j);
		}
	}

	//printf("*");
	// �Ʒ���
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
	while��
	while (���ǽ�)
	{
		������ �ڵ�
	}
	���ǽ��� true�� ��� �ڵ尡 ���۵ǰ� false�� ��� while���� �������´�.
	*/
	
	// ���� �̿��Ͽ� �������¸� while���� �̿��ؼ� �����ÿ�.

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