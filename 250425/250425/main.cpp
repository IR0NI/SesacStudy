
#include <iostream>

// �ð��� ���õ� ����� �����Ѵ�.
#include <time.h>

void main()
{
	srand(time(0));
	rand();
	///*
	//�б⹮ : ���� ���� �� �ϳ��� �����ؼ� ���۽�Ű�� ����̴�.
	//if���� switch���� �����ȴ�.
	//if (���ǽ�)
	//{
	//	������ �ڵ�
	//}
	//���ǽ��� true�� ��� {}(�ڵ���)�ȿ� �ִ� �ڵ尡 �����ϰ�
	//false�� ��쿡�� �ǳʶڴ�.

	//else : �ݵ�� if�� �Ʒ��� ����ؾ� �Ѵ�.
	//ȥ�� ����� �Ұ����ϴ�.
	//else if �Ʒ��� �־�� �Ѵ�.
	//if�� 1���� 1���� else�� �����ϴ�.
	//if���� ���ǽ��� false�� ��� else�� ������ �ȴ�.

	//else
	//{
	//	������ �ڵ�
	//}

	//else if : �ݵ�� if�� �Ʒ��� ����ؾ� �Ѵ�.
	//else���ٴ� ���� �־�� �Ѵ�.
	//ȥ�� ����� �Ұ����ϴ�.
	//if�� 1���� �������� else if ����� �����ϴ�.

	//else if (���ǽ�)
	//{
	//	������ �ڵ�
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
	//	printf("if�� ���ǽ��� true �Դϴ�.\n");
	//}

	//else
	//{
	//	printf("if�� ���ǽ��� false �Դϴ�.\n");
	//}

	//int	BossHP = 57;

	//// ���� ü���� 20���� ���� ���
	//// ���� ü���� 21 ~ 50 ������ ���
	//// ���� ü���� 51 ~ 70 ������ ���
	//// 71 �̻��� ���
	//if (BossHP >= 71)
	//{
	//	printf("���� ü���� 71 �̻��Դϴ�.\n");
	//}

	//else if (BossHP >= 51 && BossHP <= 70)
	//{
	//	printf("���� ü���� 51 ~ 70 �����Դϴ�.\n");
	//}

	//else if (BossHP >= 21 && BossHP <= 50)
	//{
	//	printf("���� ü���� 21 ~ 50 �����Դϴ�.\n");
	//}

	//else
	//{
	//	printf("���� ü���� 20 �����Դϴ�.\n");
	//}


	//if (BossHP >= 71)
	//{
	//	printf("���� ü���� 71 �̻��Դϴ�.\n");
	//}

	//else if (BossHP >= 51)
	//{
	//	printf("���� ü���� 51 ~ 70 �����Դϴ�.\n");
	//}

	//else if (BossHP >= 21)
	//{
	//	printf("���� ü���� 21 ~ 50 �����Դϴ�.\n");
	//}

	//else
	//{
	//	printf("���� ü���� 20 �����Դϴ�.\n");
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

	//// rand() : ������ ������ش�.
	//printf("Rand : %d\n", rand());
	//printf("Rand : %d\n", rand());
	//printf("Rand : %d\n", rand());
	//printf("Rand : %d\n", rand());

	//// ������ 0 ~ 100 ������ ������ ���;� �Ѵ�.
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);
	//printf("Rand : %d\n", rand() % 101);

	//// 100 ~ 400 ������ ����
	//// �ּҰ� : 100 �ִ밪 : 400 ������ : 300
	//// ���� % (������ + 1) + �ּҰ�
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);
	//printf("Rand : %d\n", rand() % 301 + 100);

	//int RandomNumber = rand() % 301 + 100;

	//// 200 ~ 400 ������ ����
	//// ���� % 201 + 200

	//// 0 ~ 100 ������ �Ҽ��� ��°�ڸ����� Ȯ���� ���Ѵ�.
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);
	//printf("Rand : %.2f\n", rand() % 10001 / 100.f);

	//// 0 ~ 100 ������ �Ҽ��� �׹�° �ڸ����� Ȯ���� ���Ѵ�.
	//float Result = rand() % 101;

	//// rand() % 10001 : 0 ~ 10000 ������ ���� ���´�.
	//// 0 ~ 10000 ������ ���� 10000.f ���� ������ �Ǹ�
	//// 0 ~ 1 ������ �Ҽ��� 4��°�ڸ����� �����ְ� �ȴ�.
	//float Percent = rand() % 10001 / 10000.f;

	//Result += Percent;

	//printf("Rand : %.4f\n", Result);

	//int	Grade = 0;

	//// scanf_s : �ܼ�â���� �Է¹����� ����ϴ� �Լ��̴�.
	//// %d�� �ϸ� ������ �Է¹ްڴٴ� �ǹ��̴�.
	////printf("����� �Է��ϼ��� : ");
	////scanf_s("%d", &Grade);

	//////std::cin >> Grade;

	////// ����� 0 ~ 3 ���� 100% ����
	////// ����� 4 ~ 6 ���� 50% ����
	////// ����� 7 ~ 9 ���� 10% ����
	////// ����� 10 ~ 12 ���� 1% ����
	////// ����� 13 �̻��� ��� 0.05% ����
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
	////	printf("��ȭ ���� : %d\n", Grade);
	////}

	////else if (Grade <= 6)
	////{
	////	if (Percent <= 50.f)
	////	{
	////		if (Percent1 <= 20.f)
	////			Grade += 2;

	////		else
	////			Grade++;
	////		printf("��ȭ ���� : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("��ȭ ����\n");
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
	////		printf("��ȭ ���� : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("��ȭ ����\n");
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
	////		printf("��ȭ ���� : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("��ȭ ����\n");
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
	////		printf("��ȭ ���� : %d\n", Grade);
	////	}

	////	else
	////	{
	////		printf("��ȭ ����\n");
	////	}
	////}

	////else
	////{
	////	printf("�߸��� ����Դϴ�.\n");
	////}

	///*
	//ġ��Ÿ Ȯ���� ���Ѵ�.
	//�ۼ�Ʈ�� ���ϰ� ġ��ŸȮ�� �ȿ� ������
	//�ּҰ��ݷ� ~ �ִ���ݷ� ������ ���� ���ݷ��� ���ؼ� ġ��Ÿ �����
	//�����Ͽ� �������� ���Ѵ�.
	//*/
printf("----------------\n");
int Critical = 0;
printf("���ݷ� : 100 ~ 200\nġ��Ÿ Ȯ���� ���Ͻÿ� : ");

scanf_s("%d", &Critical);

for (int i = 0; i < 10; i++)
{
	int Percent3 = rand() % 101;
	int Attack = rand() % 101 + 100;
	printf("���ݷ� : %d\n", Attack);
	
	if (Critical >= Percent3)
	{
		printf("������ : %d\n", Attack * 2);
	}
	else
	{
		printf("������ : %d\n", Attack);
	}
	printf("----------------\n");
}

}