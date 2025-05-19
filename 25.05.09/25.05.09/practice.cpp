#include <iostream>



class CPlayer 
{
private:
public:
	CPlayer()
	{
		printf("생성자 호출\n");
	}
	~CPlayer()
	{
		printf("소멸자 호출\n");
	}
};

class CCopyTest
{
private:

public:
	CCopyTest()
	{
		mArray = new int[10];
	}


public:
	int mNumber = 0;
	int* mArray = nullptr;
};

int main()
{
	CPlayer cplayer1;
	return 0;

}