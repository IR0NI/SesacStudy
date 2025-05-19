#include <iostream>

class CStatic
{
public:
	CStatic()
	{

	}

	~CStatic()
	{

	}

private :
	// �Ϲ� ��������� �����ϴ� ��ü���� �޸𸮸� �Ҵ��Ѵ�.
	int		mNumber = 0;
public :
	// �� Ŭ������ �̿��ؼ� ������ ��� ��ü�� �����ϴ� �޸��̴�.
	// static ��������� Ŭ���� �ܺο� ����κ��� �ʿ��ϴ�.
	static int mNumberStatic;
public:
	void SetNumber(int Number)
	{
		mNumber = Number;
	}
		
	// ����Լ� �ڿ� const�� �ٿ��ְ� �Ǹ� �� �Լ������� Ŭ���� ���������
	// ���� ������ �� ����.
	// const ��ü�� ȣ���� �� �ִ� �Լ��� �ȴ�.
	// const ��ü�� �Ϲ� �Լ��� ȣ���� �� ����.
	int GetNumber() const
	{
		return mNumber;
	}

public:
	static void OutputStatic()
	{
		// static ����Լ������� this�� ����.
		// printf("Number = %d\n", mNumber);
		// static ����� �ٷ� ������ �����ϴ�.
		printf("NumberStatic = %d\n", mNumberStatic);
	}

	static void OutputObject(CStatic* obj)
	{
		printf("Number = %d\n", obj->mNumber);
	}
};

class CSingleton
{
private:
	CSingleton()
	{

	}
	~CSingleton()
	{

	}

private:
	static CSingleton* mInst;

public:
	static CSingleton* GetInst()
	{
		if (mInst == nullptr)
			mInst = new CSingleton;
		return mInst;
	}

	static void DestroyInst()
	{
		if (mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}
};



// Ŭ���� ������� ����
// ����Ÿ�� Ŭ������::������; ���� �����Ѵ�.
int CStatic::mNumberStatic;
CSingleton* CSingleton::mInst = nullptr;

int main()
{
	CStatic Static1, Static3;
	const CStatic Static2;

	CStatic::OutputObject(&Static1);

	printf("Inst = %p\n", CSingleton::GetInst());

	CSingleton::DestroyInst();
	return 0;

}