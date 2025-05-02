#include <iostream>


int main()
{
	/*
	FILE Stream�� ���� FILE Ÿ���� ������ ������ �ְ� ���ش�.
	File Stream�� ������ ����ų� �о�� �� �ش� ���ϰ� ����� �����̴�.
	������ : ����̺���� ��ü ��θ� ǥ���ϴ� ����̴�.
	����� : ���� ������ �������� ������ ��α����� ������� ��θ� ǥ���ϴ� ����̴�.
	*/
	FILE* FileStream = nullptr;
	FILE* FileStream2 = nullptr;

	// 1�������� FileStream�� ������ش�.
	// 2�����ڴ� ������ ��ΰ� ���µ� ������, ����� ���
	// �־ �������. ����θ� ����� ��� ���� ������Ʈ�� �ִ�
	// ��θ� �������� ����θ� �����Ѵ�. ����δ� ������Ʈ ������
	// �ִ� ��θ� �������� �����Ѵ�.
	// 3�������� Mode�� ������ ����ų� ���� �� � ������ ����ų� ������
	// �ɼ��� �����ϴ� ����̴�.
	// ù��° : r, w, a ���� �ϳ��� ����.
	// r : �б� w: ���� a : �߰�
	// �ι�° : t, b, + 
	// t : �ؽ�Ʈ���� b : ���̳ʸ�����
	/*
	���|	�ǹ�			|	����X		|	����O		|  �б�	|	����	|  �߰�
	r	|	�б�			|	�����߻�	|	���Ͽ���	|	O	|	  X		|	X
	w	|	����			|	����		|	�����	|	X	|	  O		|	X
	a	|	�߰�			|	����		|	�����߰�	|	X	|	  O		|	O
	r+	|	�б�/����		|	�����߻�	|	���Ͽ���	|	O	|	  O		|	X
	w+	|	�б�/����		|	���λ���	|	�����	|	O	|	  O		|	X
	a+	|	�б�/�߰�		|	���λ���	|	����,�߰�	|	O	|	  O		|	O
	rt	|	�ؽ�Ʈ�б�		|	�����߻�	|	���Ͽ���	|	O	|	  X		|	X
	wt	|	�ؽ�Ʈ����
	*/
	fopen_s(&FileStream, "Test.txt","wt");
	fopen_s(&FileStream2, "TTest.txt", "wb");

	// ���� ��Ʈ���� ���� ��� ������ ���� �� �ִٴ� �ǹ��̴�.
	if (FileStream)
	{
		// ���Ͽ� �ؽ�Ʈ�� �������ִ� �Լ�.
		// fputc �� ���� �ϳ��� �����Ѵ�.
		fputc('A', FileStream);

		

		// fputs�� ���ڿ��� �����Ѵ�.
		fputs("AAA\n", FileStream);

		fclose(FileStream);
	}

	if (FileStream2)
	{
		fputs("HI\n", FileStream2);

		fclose(FileStream2);
	}

	fopen_s(&FileStream, "Test.txt", "rt");
	fopen_s(&FileStream2, "TTest.txt", "rt");

	if (FileStream)
	{
		char FirstText = fgetc(FileStream);

		printf("%c", FirstText);

		char	Text[256] = {};
		// ���๮�ڰ� �ִ°����� �о�´�.
		// ���� ���๮�� ���� ������ ���� �����ߴٸ� �ű������
		// �о���� �ȴ�.
		fgets(Text, 256, FileStream);

		printf("%s", Text);

		fgets(Text, 256, FileStream);

		printf("%s", Text);

		fclose(FileStream);
	}

	if (FileStream2)
	{
		char FirstText = fgetc(FileStream2);
	}

	return 0;
}