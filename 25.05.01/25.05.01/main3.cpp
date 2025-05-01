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
	// ���ڿ��� ���̸� ���Ͽ� ������ �ٸ����� �Ǵ��Ѵ�
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
	// ���ڿ��� ������ �Ǵ��Ѵ�.
	for (int i = 0; i < Index1; ++i)
	{
		if (Text1[i] != Text2[i])
			return false;
	}

	return true;


}


int main() 
{
	// ""�ȿ� ���ڿ��� ���� ���ڿ� ���ͷ��̶�� �Ѵ�.
	// utf-8 ���ڿ��� �ѱ� 1���� 3����Ʈ�� ǥ���ȴ�.
	// "sss" �̷��� �ϸ� const char �迭�� �ǰ� �ش� �迭�� �����ּҸ�
	// ��ȯ�ϰ� �ȴ�. �׷��� ��ȯ�� Ÿ���� �迭�� const char �迭�̱� ������
	// const char* �� �νĵȴ�.
	//char* Text = "���ڿ� �׽�Ʈ";
	const char* Text = "���ڿ� �׽�Ʈ";

	// �Ʒ�ó�� ���ڿ��迭 �ʱ�ȭ�� �����ϴ�.
	char	Text1[20] = "���ڿ� �׽�Ʈ";

	//Text1 = "Test";

	// ���ڿ� ���� �Լ�
	// 2�� ������ ���ڿ��� 1�������� �迭�� �������ش�.
	strcpy_s(Text1, "���ڿ��̴�");
	strcpy_s(Text1, "aa");

	printf("Text1 = %s\n", Text1);

	// �Ʒ������� �����迭�� ����� �� �迭�� ���� �ּҸ� ��ȯ���ְ� �ִ�.
	// ��ȯ�� �迭�� ���� �ּҴ� Text2 ������ ������ ��Ƶξ���.
	char* Text2 = new char[20];
	char* TextA = new char[30];
	// �Ʒ����� Text2�� ����ϸ� �� ������ ������ �����̱� ������ �迭��
	// �����Ҵ��� �ߴ��� �Լ������� �ܼ� ������ ������ �ν��� �ȴ�.
	// �׷��� ������ strcpy_s�Լ��� �����ε��� �Լ���
	// char*, rsize_t, const char* Ÿ������ �����ε��� �Լ��� ȣ��ǰ�
	// �ȴ�.
	//strcpy_s(Text2, 20,"�����Լ��׽�Ʈ�Դϴ�.......");

	printf("Text2 = %s\n", Text2);

	// size_t�� unsigned __int64 Ÿ���̴�.
	int Count = strlen("�����Ҵ��");

	Count = StringCount("�����Ҵ��");

	printf("Count = %d\n", Count);

	StringCopy(Text1, "�����Ҵ��");

	printf("Text1 = %s\n", Text1);

	char	Text3[128] = {};

	strcpy_s(Text3, "���ڿ��׽�Ʈ");

	strcat_s(Text3, " ���ڿ����̱�");

	printf("Text3 = %s\n", Text3);

	StringCopy(Text3, "���ڿ�");
	StringCat(Text3, " ���̱�");

	printf("Text3 = %s\n", Text3);

	// ���ڿ� ��
	// ��ȯ���� 0�̸� �� ���ڿ��� ����.
	// ������ ������ ���� ���ڿ��� �����ʹ��ڿ����� ���������� �տ� �ִ�.
	// ����� ������ ������ ���ڿ��� ���ʹ��ڿ����� ���������� �տ� �ִ�.
	int Result = strcmp("���ڿ�", "���ڿ�");

	printf("Result = %d\n", Result);

	Result = strcmp("���ڿ�2", "���ڿ�1");

	printf("Result = %d\n", Result);

	Result = strcmp("���ڿ�111", "���ڿ�22");

	printf("Result = %d\n", Result);

	printf("StringCmp = %d\n", StringCmp("���ڿ�", "���ڿ�"));

	char	Text4[128] = "���ݷ�, ����, ü��";

	char* Context = nullptr;
	char* TokResult = strtok_s(Text4, ",", &Context);

	printf("Context = %s\n", Context);
	printf("TokResult = %s\n", TokResult);

	//Context = nullptr;
	TokResult = strtok_s(nullptr, ",", &Context);

	printf("Context = %s\n", Context);
	printf("TokResult = %s\n", TokResult);

	char	Text5[128] = "���ݷ� : 120";

	Context = nullptr;
	TokResult = strtok_s(Text5, ":", &Context);

	printf("Context = %s\n", Context);
	printf("TokResult = %s\n", TokResult);

	// Context�� ���� 120 ���ڿ��� ���� 120���� ��ȯ��Ų��.
	int	Attack = atoi(Context);

	printf("Attack = %d\n", Attack);

	char	Text6[64] = {};
	//itoa(Attack, Text6, 10);
	_itoa_s(Attack, Text6, 10);

	printf("Text6 = %s\n", Text6);

	char	Text7[128] = {};

	// 2, 3�� ���ڸ� �̿��Ͽ� printfó�� ���ڿ��� ������� �Ŀ�
	// 1�������� ���ڿ� �迭�� ä���ش�.
	sprintf_s(Text7, "Attack = %d", Attack);

	printf("Text7 = %s\n", Text7);


	return 0;
}