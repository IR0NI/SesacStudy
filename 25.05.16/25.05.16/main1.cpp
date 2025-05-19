#include <iostream>
#include <stack>
#include <assert.h>

/*
//�ڷᱸ�� ���� : ���Լ����� �ڷᱸ���̴�.
//���߿� �߰��� �����Ͱ� ���� ������ ����̴�.

�ڷᱸ�� ť : ���Լ����� �ڷᱸ���̴�.
���� �߰��� �����Ͱ� ���� ������ ����̴�.
*/

// ��Ÿ�� ���ø� ���� : ����Ÿ���� �ƴ� ������ Ÿ������ ���ø� ���ڸ� 
// ������ִ� ����̴�. ����� �νĵȴ�.
template <typename T, int PoolSize = 1024>
class CMemoryPool
{
public:
	CMemoryPool()
	{
		// ::operator new �� �ϸ� ���������� new�� ȣ���Ѵ�.
		// ������ ȣ�� ���� �����ϰ� �޸𸮸� �Ҵ��ϴ� ���
		mMemory =(T*)(::operator new (PoolSize * sizeof(T)));
		//c��� ����Ÿ���� �޸� �������
		//mMemory = (T*)malloc(PoolSize * sizeof(T));

		// ���ÿ� �ε��� ���� �ּҸ� ��� ��Ƶд�.
		for (int i = 0; i < PoolSize; ++i)
		{
			mAllocMemory.push(mMemory + i);
		}
	}
	~CMemoryPool()
	{
		::operator delete(mMemory);
		//free(mMemory);
	}
public:
	T* Alloc()
	{
		// ���̻� �Ҵ��� �� �ִ� ������ ���� ��� ����ó���� �ص� �ǰ�
		assert(!mAllocMemory.empty() && "Memory Pool Is Empty");

		// top�� �̿��ؼ� �������� �߰��� �����͸� ���´�.
		T* Ptr = mAllocMemory.top();

		// �������� �߰��� �����͸� �����Ѵ�.
		mAllocMemory.pop();

		// placement new
		// 1. �޸� �Ҵ�
		// 2. ��ü ������ ȣ��
		// �̹� �Ҵ�� �ּҿ� ��ü�� ������ �� ����Ѵ�.
		// ���� �޸𸮸� �Ҵ��ϴ� ����� �ƴϴ�.
		new (Ptr) T;


		return Ptr;
	}

	void DeAlloc(T* Ptr)
	{
		// �޸𸮸� Ǯ�� ��ȯ�� �� �Ҹ��ڸ� ȣ���ϰ� ���� ���
		//Ptr->~T();

		mAllocMemory.push(Ptr);
	}
private:
	T* mMemory = nullptr;
	std::stack<T*> mAllocMemory;
};

class Cmonster
{
public:
	Cmonster()
	{
		printf("cmonster ������\n");
	}
	~Cmonster()
	{
		printf("cmonster �Ҹ���\n");
	}
public:
	char mName[32] = {};

private:
	static CMemoryPool<Cmonster>	mMonsterPool;
public :
	static void* operator new (size_t Size)
	{
		return mMonsterPool.Alloc();
	}

};

CMemoryPool<Cmonster> Cmonster::mMonsterPool;

int main()
{
	//CMemoryPool<Cmonster> MonsterPool;
	//
	//Cmonster* Monster1 = MonsterPool.Alloc();
	//// placement new�� �̿��Ͽ� �����ڰ� ȣ��� �� �ֵ��� �Ѵ�.
	//// new (Monster1) Cmonster;
	//
	//MonsterPool.DeAlloc(Monster1);
	//
	//return 0;
}