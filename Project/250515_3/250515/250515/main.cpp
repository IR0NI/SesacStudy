
#include <iostream>
#include <typeinfo>

/*
��� : Ŭ������ �θ�� �ڽ��� ���踦 ������ �� �ִ�. �ڽ�Ŭ������ �θ�Ŭ������ �����
�����Ͽ� �����ǰ� �ȴ�.

��� �������� �����ڿ� �Ҹ����� ȣ�����
������ : �θ� -> �ڽ�
�Ҹ��� : �ڽ� -> �θ�

private ����� �ް� �Ǹ� Ŭ���� �ܺο����� �θ��� ����� ������ �Ұ����ϰ�
���ο����� ������ �����ϴ�.

private : Ŭ���� �ܺο��� ������ �Ұ����ϰ� ���ο����� ������ �����ϴ�.
�ڽ�Ŭ���� ���ο����� ������ �Ұ����ϴ�.

protected : Ŭ���� �ܺο����� ������ �Ұ����ϰ� Ŭ���� ���� Ȥ�� �ڽ�Ŭ������
���ο����� ������ �����ϴ�.

RTTI(Run Time Type Information) : �ǽð����� Ÿ�������� ���� �� �ְ� 
���ִ� ����̴�.

������ : ��Ӱ��迡 �ִ� Ŭ���� ���̿� ���� ����ȯ�� ������ ������ ���Ѵ�.

��ĳ���� : �ڽ� -> �θ� ����ȯ
�ٿ�ĳ���� : �θ� -> �ڽ� ����ȯ

1. �������� ����� �θ� �ΰ� �� �ڽ��� Ư¡�� �ڽ�Ŭ������ ����� ���� Ŭ������
������ �� �ְ� ���ش�.
2. �������� �̿��Ͽ� �θ�Ÿ�������� ����ȯ�� �����ϱ� ������ �θ�Ÿ���� �����ϴ� �ϳ���
������� ���� �ڽ�Ŭ������ ��ü���� ������ �� �ִ�.
*/
class CParent
{
public:
	CParent()
	{
		printf("CParent ������\n");
	}

	/*
	�Ҹ��ڳ� �Ϲ� Ŭ���� ����Լ� �տ� virtual Ű���带 �ٿ��ָ� �ش� �Լ���
	�����Լ��� �ȴ�.
	�����Լ��� ������ �ִ� Ŭ������ �����Լ����̺��� ������ �ȴ�.
	�θ� �����Լ��� �ִ� �ڽ�Ŭ������ �����Լ����̺��� ������ �ȴ�.
	Ŭ���� �� �����Լ����̺��� �����ȴ�.
	�����Լ��� ������ �ִ� Ŭ������ �̿��ؼ� ��ü�� �����ϸ�
	__vfptr �̶�� ������ ������ �ڵ����� ������ �ȴ�.
	�� ������ ������ �ش� Ŭ������ �����Լ����̺��� �޸� �ּ�
	�� ������ �ȴ�.

	�����Լ� ���̺��� �����Լ��� �ּҸ� ��� �ִ�.
	�����Լ��� ȣ���ϰ� �Ǹ� ���� �ش� �Լ��� �ּҸ� �����Լ� ���̺��� �����Ͽ� ������
	�� �ּҸ� �̿��Ͽ� �Լ��� ȣ�����ִ� ����̴�.
	*/
	virtual ~CParent()
	{
		printf("CParent �Ҹ���\n");
	}

public:
	int		mA = 10;

private:
	int		mB = 20;

protected:
	int		mZ = 30;

public:
	virtual void Output()
	{
		mZ = 1123;
		printf("CParent Output Function\n");
	}

	virtual void OutputOverride()
	{
	}

	// �߻�Ŭ���� : ���������Լ��� ������ �ִ� Ŭ������ �߻�Ŭ���� ��� �Ѵ�.
	// �߻�Ŭ������ ��ü ������ �Ұ����ϴ�.
	// ���� ���������Լ��� ������ �ִ� Ŭ������ ��ӹ޴� �ڽ�Ŭ�������� ���������Լ���
	// �����ǰ� ���ٸ� �ڽ�Ŭ������ �߻�Ŭ������ �ȴ�.
	// ���������Լ��� �ڽ�Ŭ�������� ������ ������ �ؾ� �Ѵ�.
	virtual void OutputPure() = 0;
	// �Լ� �ڿ� abstract�� �ٿ��� ���������Լ��� ���� �� �ִ�.
	virtual void OutputPure1()	abstract
	{
	}

	void Output1()
	{
		printf("CParent Output1 Function\n");
	}
};

class CChild :
	public CParent
{
public:
	CChild()
	{
		mA = 500;
		//mB = 400;
		mZ = 600;
		printf("CChild ������\n");
	}

	~CChild()
	{
		printf("CChild �Ҹ���\n");
	}

public:
	int	mC = 30;

public:
	// �Լ� ������(�Լ� �������̵�). �θ�Ŭ������ �Լ��� ������ ������ ���·�
	// �ڽ�Ŭ������ ������ �ϴ°��� ���Ѵ�.
	// final Ű����� �� Ŭ������ �ڽ�Ŭ�������� ���̻� �� �Լ��� ������ �� ��
	// ���ٴ� �ǹ��̴�.
	void Output()	final
	{
		printf("CChild Output Function\n");
	}

	virtual void OutputPure()
	{
	}

	virtual void OutputPure1()
	{
	}

	// override�� ��������� �� �Լ��� �θ��� �Լ��� ������ �� �Լ��� �νĽ��Ѽ�
	// �θ� ���� �Լ��� ����� �Ǹ� ������ �߻��Ѵ�.
	/*void OutputOverride()	override
	{
	}

	void Output3()	override
	{
	}*/
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

public:
	int	mD = 30;
	int	mE = 40;

public:
	// �Լ� ������(�Լ� �������̵�). �θ�Ŭ������ �Լ��� ������ ������ ���·�
	// �ڽ�Ŭ������ ������ �ϴ°��� ���Ѵ�.
	/*void Output()
	{
		printf("CChild1 Output Function\n");
	}*/

	virtual void OutputPure()
	{
	}

	virtual void OutputPure1()
	{
	}
};

class CChildChild :
	public CChild
{
public:
	CChildChild()
	{
		printf("CChildChild ������\n");
	}

	~CChildChild()
	{
		printf("CChildChild �Ҹ���\n");
	}

public:
	int	mD = 30;

public:
	// �Լ� ������(�Լ� �������̵�). �θ�Ŭ������ �Լ��� ������ ������ ���·�
	// �ڽ�Ŭ������ ������ �ϴ°��� ���Ѵ�.
	/*void Output()
	{
		printf("CChildChild Output Function\n");
	}*/
};

// Ŭ������ ������ �� Ŭ���� �̸� �ڿ� abstract �� �ٿ��ָ� �ش� Ŭ������
// �߻�Ŭ������ �ȴ�.
class CEmpty	abstract
{
public:
	CEmpty()
	{
	}

	~CEmpty()
	{
	}

public:
	int	mA;
};

// Ŭ���� �ڿ� final Ű���带 �ٿ��ָ� ���̻� ����� �� ���� Ŭ������ �ȴ�.
class CEmpty1 final
{
public:
	CEmpty1()
	{
	}

	virtual ~CEmpty1()
	{
	}

public:
	int	mA;
};

//class CEmpty2 : public CEmpty1
//{
//};

int main()
{
	CEmpty	empty;

	// CChild Ÿ���� ��ü�� �����ϰ� �� �ּҸ� CParent ������ Ÿ���� ������
	// ��Ƶд�.
	CParent* Parent11[2];

	Parent11[0] = new CChild;
	Parent11[1] = new CChild1;

	CChild1* Child11 = dynamic_cast<CChild1*>(Parent11[0]);

	Parent11[0]->Output();
	Parent11[1]->Output();

	// CParent ������ Ÿ�Կ� �ִ� �ּҸ� �����Ѵ�.
	delete Parent11[0];
	delete Parent11[1];

	system("cls");

	printf("Empty Size : %d\n", sizeof(CEmpty));
	printf("Empty1 Size : %d\n", sizeof(CEmpty1));
	//CParent	parent, parent1;
	//CChild	child, child1;
	/*CChild	child;

	child.Output();
	child.Output1();*/

	return 0;

	//CParent	Parent;
	//CChild		Child;
	//CChildChild		ChildChild;

	//Child.Output();
	//Child.mA = 120;
	//Child.mB = 130;
	//Child.mZ = 1111;
	// typeid(���� Ȥ�� Ÿ��) �� �־��ָ� type_info Ÿ���� ��ü�� ���´�.
	//type_info
	//typeid(Child).;
	//printf("TypeName : %s\n", typeid(Child).name());

	CChild	Child;
	// Child��ü�� CParent ������Ÿ������ ��ĳ���� �Ͽ���.
	CParent* Parent = &Child;

	// Child1 ������ Ÿ������ �ٿ�ĳ���� �Ͽ���.
	CChild1* Child1 = (CChild1*)Parent;

	int	Addr = (int)Child1;

	printf("�޸� : %p\n", &Child);
	printf("�޸� : %p\n", Parent);
	printf("�޸� : %p\n", Child1);

	/*
	C++�� ����ȭ
	static_cast : �Ϲ����� Ÿ�� ����ȯ. ��κ��� ����ȯ�� ���Ѵ�.
	const_cast : const �Ӽ��� ������ �� ����Ѵ�.
	dynamic_cast : ��Ÿ�ӿ� Ÿ���� �˻��Ͽ� ����ȯ�� �����Ѵ�. Ÿ���� �������̶��
	����ȯ�� ���ְ� �ƴϸ� nullptr�� ��ȯ�Ѵ�.
	reinterpret_cast : ��Ʈ ������ ���� ����ȯ.
	*/
	//Addr = static_cast<int>(Child1);
	Addr = static_cast<int>(3.14f);

	const int	cNumber = 500;

	//int* Addr2 = &cNumber;
	int* Addr1 = const_cast<int*>(&cNumber);

	CParent* Parent1 = dynamic_cast<CParent*>(&Child);

	printf("dynamic cast Parent1 = %p\n", Parent1);

	/*CChild1* dnChild1 = dynamic_cast<CChild1*>(Parent1);

	printf("dynamic cast dnChild1 = %p\n", dnChild1);*/


	return 0;
}
