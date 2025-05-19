#include <iostream>

class CParent
{
public:
	CParent()
	{
		printf("Cparent 持失切\n");
	}

	~CParent()
	{
		printf("Cparent 社瑚切\n");
	}
};

class CChild :
	CParent
{
public:
	CChild()
	{
		printf("CChild 持失切\n");
	}

	~CChild()
	{
		printf("CChild 社瑚切\n");
	}
};

class CChild1 :
	public CParent
{
public:
	CChild1()
	{
		printf("CChild1 持失切\n");
	}

	~CChild1()
	{
		printf("CChild1 社瑚切\n");
	}

};


int main()
{
	//CParent cparent1;

	//CChild cchild1;

	CChild1 cchild11;


	return 0;
}