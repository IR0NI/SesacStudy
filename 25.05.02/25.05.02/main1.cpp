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
	바이너리파일 : 특정 메모리의 데이터를 그대로 파일에 옮겨서 저장할 때
	사용한다.
	*/
	FILE* FileSteram = nullptr;
	fopen_s(&FileSteram, "Test1.tbf", "wb");

	if (FileSteram)
	{
		int Number = 100;

		// 1번인자의 주소로부터 번인자의 크기 * 3번인자의 개수 만큼의 바이트를 
		// 파일에 복사한다.
		fwrite(&Number, sizeof(int), 1, FileSteram);

		int Array[10] = {};

		for (int i = 0; i < 10; ++i)
		{
			Array[i] = i + 1;

		}

		fwrite(Array, sizeof(int), 10, FileSteram);

		FPlayerInfo Player;

		strcpy_s(Player.Name, "기사");
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

		printf("이름 : %s\n", Player.Name);

		switch (Player.Job)
		{
		case EPlayerJob::Knight :
			printf("기사\n");
			break;
		default:
			break;
		}

		

		fclose(FileSteram);
	}

	return 0;
}