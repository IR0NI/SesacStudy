
#include <iostream>
#include <time.h>

/*
������ : ����� �̸��� �ο����ִ� ����̴�.
�������� ��������� ���� Ÿ�����ε� ����� �����ϴ�.
�������� �̸��� ��������� ���� Ÿ���� �ȴ�.
������ ���� ����� ����� �ȴ�.
������ ���� ����� �⺻���� 0���� 1�� ���ʷ� �����ϰ� �ȴ�.
������ ���� ����� ���Ѵٸ� �⺻ ���� ������ ���� �ִ�.
*/
enum ESRP : char
{
	Scissor = 1,
	Rock,
	Paper
};

enum class ESRP2 : unsigned char
{
	Scissor2 = 1,
	Rock2,
	Paper2
};

namespace ESRP3
{
	enum Type
	{
		Scissor,
		Rock,
		Paper
	};
}

void main()
{
	srand(time(0));
	rand();

	// �÷��̾��� ����, ����, �� ���� �����ϱ� ���� ������
	// �����Ѵ�.
	// ���� : 1 ���� : 2 �� : 3
	int	Player = 0;
	
	printf("1. ����\n2. ����\n3. ��\n");
	printf("���� : ");
	scanf_s("%d", &Player);

	// ������ ���� 1 ~ 3 ������ ���� �ƴ� ��� ������ �����Ѵ�.
	// return�� �ҼӵǾ� �ִ� �Լ��� ���������� ����̴�.
	// main�� ���������� �Ǹ� ���α׷��� ����ȴ�.
	if (Player < 1 || Player > 3)
		return;

	// AI�� ����(1), ����(2), ��(3) �� �ϳ��� �����ϰ� �Ѵ�.
	int	AI = rand() % 3 + 1;

	/*
	switch�� : �б�ó���� �� �����̴�.
	switch (��)
	{
	case ���:
		������ �ڵ�
		break;	switch���� ���������� ������ �Ѵ�.
	case ���:
		������ �ڵ�
		break;
	case ���:
		������ �ڵ�
		break;
	default:	if���� else�� ���� ������ �Ѵ�.
		������ �ڵ�
		break;
	}
	*/

	//ESRP2	Srp2 = ESRP2::Scissor2;

	switch (AI)
	{
	case Scissor:
		int Number3;
		Number3 = 300;
		printf("AI : ����\n");
		break;
	case Rock:
	{
		int	Number4 = 500;
		printf("AI : ����\n");
	}
		break;
	case Paper:
		/*int	Number3;
		Number3 = 200;*/
		printf("AI : ��\n");
		break;
	}

	if (AI == 1)
		printf("AI : ����\n");

	else if (AI == 2)
		printf("AI : ����\n");

	else
		printf("AI : ��\n");

	// �÷��̾�� AI�� ���� �̿��Ͽ� ����� ����Ѵ�.
	// �÷��̾ �¸����� ���
	if (Player == ESRP3::Scissor && AI == ESRP3::Paper ||
		Player == Rock && AI == Scissor ||
		Player == Paper && AI == Rock)
		printf("Player �¸�\n");

	// AI�� �¸����� ���
	else if (AI == Scissor && Player == Paper ||
		AI == Rock && Player == Scissor ||
		AI == Paper && Player == Rock)
		printf("AI �¸�\n");

	else
		printf("���\n");

	int	Result = Player - AI;

	if (Result == 1 || Result == -2)
		printf("Player �¸�\n");

	else if (Result == 0)
		printf("���\n");

	else
		printf("AI �¸�\n");

	/*Scissor1;

	enum ESRP1
	{
		Scissor1 = 1,
		Rock1,
		Paper1
	};*/

	printf("%d\n", Scissor);
	printf("%d\n", Rock);
	printf("%d\n", Paper);

	int	SRPNumber = Scissor;
	//SRPNumber = ESRP2::Scissor2;
	//SRPNumber = 2 - ESRP2::Scissor2;

	printf("%d\n", ESRP2::Scissor2);
	printf("%d\n", ESRP2::Rock2);
	printf("%d\n", ESRP2::Paper2);
}