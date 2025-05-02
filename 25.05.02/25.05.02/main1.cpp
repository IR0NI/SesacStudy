#include <iostream>	


enum class EPlayerJob : unsigned char
{
	None,
	Knight,
};

struct FPlayerInfo
{
	char Name[32] = {};
	EPlayerJob Job = EPlayerJob::Knight;
	int Attack = 100;
};

int main()
{
	/*
	���̳ʸ����� : Ư�� �޸��� �����͸� �״�� ���Ͽ� �Űܼ� ������ ��
	����Ѵ�.
	*/
	FILE* FileSteram = nullptr;
	fopen_s(&FileSteram, "Test1.tbf", "wb");

	if (FileSteram)
	{
		int Number = 100;

		// 1�������� �ּҷκ��� �������� ũ�� * 3�������� ���� ��ŭ�� ����Ʈ�� 
		// ���Ͽ� �����Ѵ�.
		fwrite(&Number, sizeof(int), 1, FileSteram);

		int Array[10] = {};

		for (int i = 0; i < 10; ++i)
		{
			Array[i] = i + 1;

		}

		fwrite(Array, sizeof(int), 10, FileSteram);

		FPlayerInfo Player;

		strcpy_s(Player.Name, "���");
		Player.Attack = 100;


		fwrite(&Player, sizeof(FPlayerInfo),1,FileSteram );

		fclose(FileSteram);
	}

	fopen_s(&FileSteram, "Test1.tbf", "rb");

	if (FileSteram)
	{
		int Number = 0;

		fread(&Number, sizeof(int), 1, FileSteram);

		printf("Number = %d\n", Number);

		int Array[10] = {};

		for (int i = 0; i < 10; ++i)
		{
			Array[i] = i;
			printf("Array[%d] = %d\n", i, Array[i]);
		}

		FPlayerInfo Player;

		fread(&Player, sizeof(FPlayerInfo), 1, FileSteram);

		printf("�̸� : %s\n", Player.Name);

		switch (Player.Job)
		{
		case EPlayerJob::Knight :
			printf("���\n");
			break;
		default:
			break;
		}

		

		fclose(FileSteram);
	}

	return 0;
}