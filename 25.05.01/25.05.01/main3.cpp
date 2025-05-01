#include <iostream>

int StringCount(const char* Text)
{
	int Index = 0;

	while (Text[Index] != 0)
	{

		++Index;
	}

	return Index;
}

void StringCopy(char* Buffer, const char* Text)
{
	int Index = 0;

	while (Buffer[Index] != Text[Index])
	{
		++Index;
	}

	Buffer[Index] = 0;
	
}

void StringCat(char* Buffer, const char* Text)
{
	int Index = 0;

	while (Text[Index] != 0)
	{
		++Index;
	}
	
	int Index1 = 0;

	while (Text[Index1] != 0)
	{
		Buffer[Index] = Text[Index1];
		++Index;
		++Index1;
	}
	Buffer[Index] = 0;
	
}

bool StringCmp(const char* Text1, const char* Text2)
{
	// 문자열의 길이를 비교하여 같은지 다른지를 판단한다
	int Index1 = 0;
	int Index2 = 0;
	while (Text1[Index1] != 0 || Text1[Index2] != 0)
	{
		if(Text1[Index1] != 0)
		++Index1;
		if(Text1[Index2] != 0)
		++Index2;
	}
	if (Index1 != Index2)
		return false;
	// 문자열이 같은지 판단한다.
	for (int i = 0; i < Index1; ++i)
	{
		if (Text1[i] != Text2[i])
			return false;
	}

	return true;


}


int main() 
{
	// ""안에 문자열을 쓰면 문자열 리터럴이라고 한다.
	// utf-8 문자열은 한글 1개당 3바이트로 표현된다.
	// "sss" 이렇게 하면 const char 배열이 되고 해당 배열의 시작주소를
	// 반환하게 된다. 그런데 반환된 타입은 배열이 const char 배열이기 때문에
	// const char* 로 인식된다.
	//char* Text = "문자열 테스트";
	const char* Text = "문자열 테스트";

	// 아래처럼 문자열배열 초기화가 가능하다.
	char	Text1[20] = "문자열 테스트";

	//Text1 = "Test";

	// 문자열 복사 함수
	// 2번 인자의 문자열을 1번인자의 배열에 복사해준다.
	strcpy_s(Text1, "문자열이다");
	strcpy_s(Text1, "aa");

	printf("Text1 = %s\n", Text1);

	// 아래에서는 동적배열을 만들고 그 배열의 시작 주소를 반환해주고 있다.
	// 반환된 배열의 시작 주소는 Text2 포인터 변수에 담아두었다.
	char* Text2 = new char[20];
	char* TextA = new char[30];
	// 아레에서 Text2를 사용하면 이 변수는 포인터 변수이기 때문에 배열로
	// 동적할당을 했더라도 함수에서는 단순 포인터 변수로 인식이 된다.
	// 그렇기 때문에 strcpy_s함수의 오버로딩된 함수중
	// char*, rsize_t, const char* 타입으로 오버로딩된 함수가 호출되게
	// 된다.
	//strcpy_s(Text2, 20,"복사함수테스트입니다.......");

	printf("Text2 = %s\n", Text2);

	// size_t는 unsigned __int64 타입이다.
	int Count = strlen("복사할대상");

	Count = StringCount("복사할대상");

	printf("Count = %d\n", Count);

	StringCopy(Text1, "복사할대상");

	printf("Text1 = %s\n", Text1);

	char	Text3[128] = {};

	strcpy_s(Text3, "문자열테스트");

	strcat_s(Text3, " 문자열붙이기");

	printf("Text3 = %s\n", Text3);

	StringCopy(Text3, "문자열");
	StringCat(Text3, " 붙이기");

	printf("Text3 = %s\n", Text3);

	// 문자열 비교
	// 반환값이 0이면 두 문자열은 같다.
	// 음수가 나오면 왼쪽 문자열이 오른쪽문자열보다 사전순으로 앞에 있다.
	// 양수가 나오면 오른쪽 문자열이 왼쪽문자열보다 사전순으로 앞에 있다.
	int Result = strcmp("문자열", "문자열");

	printf("Result = %d\n", Result);

	Result = strcmp("문자열2", "문자열1");

	printf("Result = %d\n", Result);

	Result = strcmp("문자열111", "문자열22");

	printf("Result = %d\n", Result);

	printf("StringCmp = %d\n", StringCmp("문자열", "문자열"));

	char	Text4[128] = "공격력, 방어력, 체력";

	char* Context = nullptr;
	char* TokResult = strtok_s(Text4, ",", &Context);

	printf("Context = %s\n", Context);
	printf("TokResult = %s\n", TokResult);

	//Context = nullptr;
	TokResult = strtok_s(nullptr, ",", &Context);

	printf("Context = %s\n", Context);
	printf("TokResult = %s\n", TokResult);

	char	Text5[128] = "공격력 : 120";

	Context = nullptr;
	TokResult = strtok_s(Text5, ":", &Context);

	printf("Context = %s\n", Context);
	printf("TokResult = %s\n", TokResult);

	// Context에 들어온 120 문자열을 정수 120으로 변환시킨다.
	int	Attack = atoi(Context);

	printf("Attack = %d\n", Attack);

	char	Text6[64] = {};
	//itoa(Attack, Text6, 10);
	_itoa_s(Attack, Text6, 10);

	printf("Text6 = %s\n", Text6);

	char	Text7[128] = {};

	// 2, 3번 인자를 이용하여 printf처럼 문자열을 만들어준 후에
	// 1번인자의 문자열 배열에 채워준다.
	sprintf_s(Text7, "Attack = %d", Attack);

	printf("Text7 = %s\n", Text7);


	return 0;
}