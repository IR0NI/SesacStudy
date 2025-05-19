
#include <iostream>

struct FPlayer
{
	char	Name[32] = {};
	int		Attack = 0;
};

/*
�ν��Ͻ�, �������̽���� �� ���� ����Ѵ�.
�ν��Ͻ� : ���� �޸𸮿� �Ҵ�Ǵ� ����.

��ü : ��� ��ü�� ��ü��� �� �� �ִ�. ���α׷��ֿ����� Ŭ����, ����ü ����
�̿��Ͽ� ������ ������ ���Ѵ�.

��ü���� ���α׷��� : ��ü�� �����Ͽ� �ϳ��� �ϼ��� ���α׷��� ����� �����
���Ѵ�.

������Ʈ : ��ü�� �ٸ��ֱ� ���� ��ǰ.

Ŭ���� : ��ü���� ���α׷����� �������ֱ� ���� �����̴�. ��ü�� ����� ����
�����ϻ� Ŭ������ ��ü�� �ƴϴ�.

class Ŭ�����̸�
{
	�������
	����Լ�
};

�𸮾������� Ŭ���� �̸� �տ� A, U 2������ �ٴ´�.
A : Actor
U : UObject
�Ϲ�Ŭ������ ������ C�� �ٿ� ������ش�.

ĸ��ȭ : ���� ��������� ����Լ��� ����ִ� ����� �����Ѵ�.
����ȭ : ����� ���� ������ ������ �� �ִ�.
Ŭ�������� : Ŭ������ ����Լ� ��
Ŭ�����ܺ� : Ŭ������ ����Լ� ���� �ƴ� ����
- public : Ŭ���� ���ο� �ܺο� ��� �����Ѵ�. ����ü�� �ƹ��͵� �ٿ�����
���� ��� �⺻���� public�̴�.
- private : Ŭ���� ���ο����� ������ ���������� �ܺο����� ������ �Ұ����ϴ�.
Ŭ������ �ƹ��͵� �ٿ����� ���� ��� �⺻���� private�̴�.
- protected : ��� �� �� �ٽ� ����.
��Ӽ� : ��� �� �� �ٽ� ����.
������ : ��� �� �� �ٽ� ����.

Ŭ������ �޸� ũ��� ��������� ũ��� �����ϴ�. ��, ����� ����ϸ鼭
�����Լ��� ����� ��� �ٸ��� ���´�.
����Լ��� Ŭ������ �̿��Ͽ� ������ ��ü�� �޸� ũ�⿡ ������ ���� �ʴ´�.
*/
class CPlayer
{
	/*
	�����ڿ� �Ҹ��ڴ� Ŭ���� �̸��� ���� �̸��� �Լ��̴�.
	��ȯ Ÿ�� ���� �̸��� ���ڸ����� �����Ѵ�.
	�����ڴ� �����ε��� ���������� �Ҹ��ڴ� ���� ���� ���¸� �����Ѵ�.
	������ : �� Ŭ������ �̿��ؼ� ��ü�� ������ �� �ڵ����� ȣ���� �Ǵ�
	�Լ��̴�.
	�Ҹ��� : �� Ŭ������ �̿��ؼ� ������ ��ü�� �޸𸮿��� ���ŵ� �� �ڵ�����
	ȣ���� �Ǵ� �Լ��̴�.
	*/
public:
	// ������
	// �̴ϼȶ������� �̿��ؼ� ��������� ���� ����� ���ÿ� �ʱ�ȭ�� �� �ִ�.
	CPlayer()	:
		mAttack(20),
		mDefense(10),
		mName("apple")
	{
		// �Ʒ��� mAttack ������ ������ �� �Ŀ� 50�� �����Ѵ�.
		mAttack = 50;
		printf("CPlayer ������\n");
	}

	CPlayer(const char* Name)	:
		mAttack(30),
		mDefense(40)
		//mName(Name)
	{
		printf("CPlayer const char* ������\n");
	}

	/*
	��������� : �ٸ� ��ü�� ������ ���ο� ��ü�� ���� �� ����Ѵ�.
	�������� ���ڷ� const Ŭ����Ÿ��& Ÿ���� ����Ѵ�.

	�������� ��������, �������� 2������ �ִ�.
	�������� : Ŭ������ �����͸� �״�� �����Ѵ�.
	�������� : Ŭ������ �����Ҵ�� �����Ͱ� ���� ��� �Ȱ��� ũ���� ������
	������ְ� �����͸� �����ϴ� ����̴�. �Ϲ� �����ʹ� ��������� ����
	�״�� �����Ѵ�.

	�̵������� : �ٸ� ��ü�� ������ �ִ� ������ ���ο� ��ü�� �Ű��ָ鼭
	��ü�� ���� �� ����Ѵ�.
	Ŭ����Ÿ��&&

	&& : ���� Ÿ�Կ� && �� ������ rvalue reference(������ ����)��� �Ѵ�.
	�ӽð��� ������ �� �ְ� ���ִ� Ÿ���̴�.
	*/
	CPlayer(const CPlayer& Ref)// :
		//mAttack(Ref.mAttack),
		//mDefense(Ref.mDefense)
		//mName(Ref.mName)
	{
		// ��� ��������� ���� �״�� �����Ѵ�.
		// �������簡 �Ͼ��.
		*this = Ref;
	}

	// �Ҹ���
	~CPlayer()
	{
		printf("CPlayer �Ҹ���\n");
	}

public:
	// �� �Ʒ��� �ٸ� �������� Ű���带 ������ ������ ��� public�� �ȴ�.
	char	mName[32] = {};
	int		mAttack = 0;

private:
	int		mDefense = 0;

public:
	// Ŭ������ �Ϲ� ����Լ�(�Ϲݸ���Լ�, ������, �Ҹ���) ���ο�����
	// this�� ����� �� �ִ�.
	// this�� �ڱ� �ڽ��� �޸� �ּ��̴�.
	// Player1.Output() �̷������� Ŭ������ ����Լ��� ȣ���� �� ��ü��
	// �̿��ؼ� ȣ���ϰ� �Ǵµ� Player1.Output() ���� ȣ���ϸ� ȣ���ϴ�
	// ���� this�� Player1�� �ּҸ� ������ �ǰ� Player2.Output() ����
	// ȣ���ϸ� ȣ���ϴ� ���� this�� Player2�� �ּҸ� ������ �ȴ�.
	// ����Լ� ���ο��� Ŭ���� ��������� ����ϰ� �Ǹ� �տ� this-> �� 
	// ������ ���̴�.
	void Output()
	{
		printf("Name = %s\n", mName);
		printf("this = %p\n", this);
		printf("���ݷ� : %d\n", mAttack);
		printf("���� : %d\n", this->mDefense);
		//printf("this Addr = %p\n", &this);
	}

	void OutputTest()
	{
		printf("OutputTest Function\n");
	}
};

class CCopyTest
{
public:
	CCopyTest()
	{
		mArray = new int[10];

		// �޸𸮸� ���ϴ� ������ ä���� �� ����Ѵ�.
		// ��, ä��� ������ ����Ʈ ������ ���� ä���ش�.
		// 1�������� �޸𸮸� 2�������� ������ 3�������� ũ�⸸ŭ
		// ä���ش�.
		memset(mArray, 0, sizeof(int) * 10);
		printf("CCopyTest ������\n");
	}

	CCopyTest(const CCopyTest& Ref)
	{
		//*this = Ref;
		mNumber = Ref.mNumber;
		printf("CCopyTest ���������\n");

		// �����Ҵ�� �����͸� �Ҹ��ڿ��� �����ϰ� �����Ƿ� ���� ���縦
		// �̿��ؼ� ó���Ѵ�.
		mArray = new int[10];

		// �޸𸮸� ������ �� ����Ѵ�.
		// 1�������� �ּҿ� 2�������� �ּҷκ��� 3�����ڿ� ����
		// ����Ʈ ����ŭ�� �������ش�.
		memcpy(mArray, Ref.mArray, sizeof(int) * 10);
		/*for (int i = 0; i < 10; ++i)
		{
			mArray[i] = Ref.mArray[i];
		}*/
	}

	// �̵� ������
	CCopyTest(CCopyTest&& Ref)
	{
		printf("CCopyTest �̵�������\n");
		mNumber = Ref.mNumber;
		mArray = Ref.mArray;
		Ref.mArray = nullptr;
	}

	~CCopyTest()
	{
		printf("CCopyTest �Ҹ���\n");
		if (mArray != nullptr)
			delete[] mArray;
	}

public:
	int	mNumber = 0;
	int* mArray = nullptr;
};

void OutputPlayer(FPlayer* Player)
{
	printf("���ݷ� : %d\n", Player->Attack);
}

void TestRValue(CCopyTest Copy)
{
}

int main()
{
	//FPlayer	Player;

	//Player.Attack = 10;

	//OutputPlayer(&Player);

	//CPlayer	Player1, Player2("�̸�");

	//printf("Player1 = %p\n", &Player1);
	//printf("Player2 = %p\n", &Player2);

	//// Output ����Լ��� Player1�� Player2 ��� ������ �ּ��� �Լ���
	//// ����ϰ� �ȴ�. �׷��� ����Լ����� ��Ȯ�ϰ� Player1�� Player2��
	//// ��������� ���� �ν��ϰ� ����� �� �ִ�.
	//Player1.mAttack = 100;
	//Player1.Output();

	//// ��������ڰ� ȣ��ȴ�.
	//CPlayer	PlayerCopy(Player1);

	//Player2.mAttack = 300;
	//Player2.Output();

	//CPlayer* Player3 = nullptr;

	////Player3->Output();
	//Player3->OutputTest();

	////printf("Player Size = %d\n", sizeof(CPlayer));

	//// Number�� lvalue
	//int	Number = 10;

	//// Number + 10 : rvalue
	//// Number + 10�� �� ����� �����ϱ� ���� �ӽ� ��������� �����
	//// �ű⿡ ����� ������ �Ŀ� lvalue�� �������ش�.
	//int	Result = Number + 10;

	////int& Ref = Number + 10;
	//int&& Ref = Number + 10;

	////CPlayer	Player4 = CPlayer();

	//system("cls");

	//CCopyTest	Test;
	//CCopyTest	TestCopy(Test);

	//// 1����Ʈ ������ ���� ä��� �ȴ�.
	//// int�� 4����Ʈ �̹Ƿ� 1����Ʈ ������ 1�� ä��� �Ǹ�
	//// 0000 0001 0000 0001 0000 0001 0000 0001
	//memset(&Number, 1, sizeof(int));

	//printf("Number = %d\n", Number);


	system("cls");

	//CCopyTest	Test1(CCopyTest());
	//TestRValue(CCopyTest());
	CCopyTest	Test1 = std::move(CCopyTest());
	//CCopyTest	Test2 = std::move(Test1);

	printf("-----------------\n");

	return 0;
}