#include <iostream>
#include <time.h>


/*
열거형 : 상수에 이름을 부여해주는 기능이다.
열거형은 사용자정의 변수 타입으로도 사용이 가능하다.
열거형의 이름은 사용자 정의 변수 타입이 된다.
열거형 안의 목록은 상수가 된다.
열거형 안의 목록은 기본값으로 0부터 1씩 차례로 증가하게 된다.
열거형 안의 목록은 원한다면 기본 값을 변경할 수도 있다.
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

	// 플레이어의 가위, 바위, 보 값을 저장하기 위한 변수를 선언한다.
	// 가위 : 1 바위 : 2 보 : 3
	int Player = 0;
	printf("1. 가위\n2. 바위\n3. 보\n");
	printf("선택 : ");
	scanf_s("%d", &Player);

	// 선택한 값이 1 ~ 3 사이의 값이 아닐 경우 게임을 종료한다.
	// return은 소속되어 있는 함수를 빠져나가는 기능이다.
	// main을 빠져나가게 되면 프로그램이 종료된다.
	if (Player < 1 || Player > 3)
		return;

	// AI가 가위(1), 바위(2), 보(3) 중 하나를 선택하게 한다.
	int AI = rand() % 3 + 1;

	/*
	switch문 : 분기처리의 한 종류이다.
	switch (값)
	{
	case 상수:
		동작할 코드
		break;  switch문을 빠져나가는 역할을 한다.
	case 상수:
		동작할 코드
		break;
	case 상수:
		동작할 코드
		break;
	default:	if문의 else와 같은 역할을 한다.
		동작할 코드
		break;
	}
	*/

	switch ()
	{
	default:
		break;
	}

	if (AI == 1)
		printf("AI : 가위\n");
	if (AI == 2)
		printf("AI : 바위\n");
	if (AI == 3)
		printf("AI : 보\n");
	// 플레이어와 AI의 값을 이용하여 결과를 출력한다.
	// 플레이어가 승리했을 경우
	if (Player == 1 && AI == 3 ||
		Player == 2 && AI == 1 ||
		Player == 3 && AI == 2)
		printf("Player 승리\n");

	// AI가 승리했을 경우
	else if (Player == 3 && AI == 1 ||
		Player == 1 && AI == 2 ||
		Player == 2 && AI == 3)
		printf("AI 승리\n");

	else
		printf("비김\n");

	int Result = Player - AI;
	if (Result == 1 || Result == -2)
		printf("플레이어 승리\n");

	else if (Result == 0)
		printf("비김\n");
	else
	{
		printf("AI 승리\n");
	}

	printf("%d\n", Scissor);
	printf("%d\n", Rock);
	printf("%d\n", Paper);

	printf("%d\n", ESRP2::Scissor2);
	printf("%d\n", ESRP2::Rock2);
	printf("%d\n", ESRP2::Paper2);
}