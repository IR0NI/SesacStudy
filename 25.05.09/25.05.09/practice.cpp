#include <iostream>



class CPlayer 
{
private:
public:
	CPlayer()
	{
		printf("������ ȣ��\n");
	}
	~CPlayer()
	{
		printf("�Ҹ��� ȣ��\n");
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