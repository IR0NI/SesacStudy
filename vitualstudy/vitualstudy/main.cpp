#include <iostream>

class CParent
{
public:
	CParent()
	{
		printf("Cparent ������\n");
	}

	~CParent()
	{
		printf("Cparent �Ҹ���\n");
	}
};

class CChild :
	CParent
{
public:
	CChild()
	{
		printf("CChild ������\n");
	}

	~CChild()
	{
		printf("CChild �Ҹ���\n");
	}
};

class CChild1 :
	public CParent
{
public:
	CChild1()
	{
		printf("CChild1 ������\n");
	}

	~CChild1()
	{
		printf("CChild1 �Ҹ���\n");
	}

};


int main()
{
	//CParent cparent1;

	//CChild cchild1;

	CChild1 cchild11;


	return 0;
}