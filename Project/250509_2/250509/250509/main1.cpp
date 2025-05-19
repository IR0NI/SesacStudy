
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

private:
	// 일반 멤버변수는 생성하는 객체마다 메모리를 할당한다.
	int		mNumber = 0;

public:
	// 이 클래스를 이용해서 생성한 모든 객체가 공유하는 메모리이다.
	// static 멤버변수는 클래스 외부에 선언부분이 필요하다.
	static int	mNumberStatic;

public:
	void SetNumber(int Number)
	{
		mNumber = Number;
	}

	// 멤버함수 뒤에 const를 붙여주게 되면 이 함수에서는 클래스 멤버변수의
	// 값을 변경할 수 없다.
	// const 객체가 호출할 수 있는 함수가 된다.
	// const 객체는 일반 함수를 호출할 수 없다.
	int GetNumber()	const
	{
		return mNumber;
	}

public:
	static void OutputStatic()
	{
		// static 멤버함수에서는 this가 없다.
		//printf("Number = %d\n", mNumber);
		// static 멤버는 바로 접근이 가능하다.
		printf("NumberStatic = %d\n", mNumberStatic);
	}

	static void OutputObject(CStatic* Obj)
	{
		printf("Number = %d\n", Obj->mNumber);
	}
};

// 클래스 멤버변수 선언
// 변수타입 클래스명::변수명; 으로 선언한다.
int CStatic::mNumberStatic;

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
	//static CSingleton	mInst1;

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

CSingleton* CSingleton::mInst = nullptr;

int main()
{
	CStatic	Static1, Static3;
	const CStatic	Static2;

	Static1.SetNumber(100);
	Static1.GetNumber();

	Static2.GetNumber();
	//Static2.SetNumber(200);

	Static1.mNumberStatic = 200;
	Static3.mNumberStatic = 300;
	CStatic::mNumberStatic = 500;

	printf("NumberStatic = %d\n", Static1.mNumberStatic);
	printf("NumberStatic = %d\n", Static3.mNumberStatic);

	Static1.OutputStatic();
	Static3.OutputStatic();
	CStatic::OutputStatic();

	CStatic::OutputObject(&Static1);
	CStatic::OutputObject(&Static3);

	//CSingleton	single;

	printf("Inst = %p\n", CSingleton::GetInst());
	printf("Inst = %p\n", CSingleton::GetInst());
	printf("Inst = %p\n", CSingleton::GetInst());
	printf("Inst = %p\n", CSingleton::GetInst());


	CSingleton::DestroyInst();

	return 0;
}
