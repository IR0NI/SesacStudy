#include <iostream>
#include <time.h>


/*
������ : ����� �̸��� �ο����ִ� ����̴�.
�������� ��������� ���� Ÿ�����ε� ����� �����ϴ�.
�������� �̸��� ����� ���� ���� Ÿ���� �ȴ�.
������ ���� ����� ����� �ȴ�.
������ ���� ����� �⺻������ 0���� 1�� ���ʷ� �����ϰ� �ȴ�.
������ ���� ����� ���Ѵٸ� �⺻ ���� ������ ���� �ִ�.
*/
enum ESRP
{
	Scissor = 1,
	Rock,
	Paper
};

enum class ESRP2
{
	Scissor2 = 1,
	Rock2,
	Paper2
};
namespace ESRP3
{

}
void main()
{
	srand(time(0));
	rand();

	// �÷��̾��� ����, ����, �� ���� �����ϱ� ���� ������ �����Ѵ�.
	// ���� : 1 ���� : 2 �� : 3
	int Player = 0;
	printf("1. ����\n2. ����\n3. ��\n");
	printf("���� : ");
	scanf_s("%d", &Player);

	// ������ ���� 1 ~ 3 ������ ���� �ƴ� ��� ������ �����Ѵ�.
	// return�� �ҼӵǾ� �ִ� �Լ��� ���������� ����̴�.
	// main�� ���������� �Ǹ� ���α׷��� ����ȴ�.
	if (Player < 1 || Player > 3)
		return;

	// AI�� ����(1), ����(2), ��(3) �� �ϳ��� �����ϰ� �Ѵ�.
	int AI = rand() % 3 + 1;

	/*
	switch�� : �б�ó���� �� �����̴�.
	switch (��)
	{
	case ���:
		������ �ڵ�
		break;  switch���� ���������� ������ �Ѵ�.
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

	switch ()
	{
	default:
		break;
	}

	if (AI == 1)
		printf("AI : ����\n");
	if (AI == 2)
		printf("AI : ����\n");
	if (AI == 3)
		printf("AI : ��\n");
	// �÷��̾�� AI�� ���� �̿��Ͽ� ����� ����Ѵ�.
	// �÷��̾ �¸����� ���
	if (Player == 1 && AI == 3 ||
		Player == 2 && AI == 1 ||
		Player == 3 && AI == 2)
		printf("Player �¸�\n");

	// AI�� �¸����� ���
	else if (Player == 3 && AI == 1 ||
		Player == 1 && AI == 2 ||
		Player == 2 && AI == 3)
		printf("AI �¸�\n");

	else
		printf("���\n");

	int Result = Player - AI;
	if (Result == 1 || Result == -2)
		printf("�÷��̾� �¸�\n");

	else if (Result == 0)
		printf("���\n");
	else
	{
		printf("AI �¸�\n");
	}

	printf("%d\n", Scissor);
	printf("%d\n", Rock);
	printf("%d\n", Paper);

	printf("%d\n", ESRP2::Scissor2);
	printf("%d\n", ESRP2::Rock2);
	printf("%d\n", ESRP2::Paper2);
}