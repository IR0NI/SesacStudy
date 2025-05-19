#pragma once
#include <assert.h>

template <typename T>
class CListNode
{
	// CLinkdedList 클래스에서 CListNode 클래스의
	// private 멤버들에 접근이 가능하다.
	// template 클래스이므로 아래와 같이 friend 처리를 한다.
	template <typename T>
	friend class CLinkedList;
private:
	CListNode() {

	}
	~CListNode() {

	}

private:
	T	mData;
	CListNode<T>* mNext = nullptr;
	CListNode<T>* mPrev = nullptr;
};



template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		mBegin = new CListNode<T>;
		mEnd = new CListNode<T>;

		mBegin->mNext = mEnd;
		mEnd->mPrev = mBegin;
	}
	~CLinkedList()
	{

	}
private:
	CListNode<T>* mBegin;
	CListNode<T>* mEnd;
	int mSize = 0;

public:
	void push_back(const T& Data)
	{
		CListNode<T>* Node = new CListNode<T>;

		Node->mData = Data;

		// End노드와 End의 이전노드 사이에 추가한다.
		CListNode<T>* Prev = mEnd->mPrev;

		Prev->mNext = Node;
		Node->mPrev = Prev;

		Node->mNext = mEnd;
		mEnd->mPrev = Node;

		++mSize;
	}

	void push_front(const T& Data)
	{
		CListNode<T>* Node = new CListNode<T>;

		Node->mData = Data;

		//Begin 노드와 Begin의 다음노드 사이에 추가한다.
		CListNode<T>* Next = mBegin->mNext;

		mBegin->mNext = Node;
		Node->mPrev = mBegin;

		Node->mNext = Next;
		Next->mPrev = Node;

		++mSize;
	}

	void pop_back()
	{
		assert(mSize > 0);

		// 지울 노드
		CListNode<T>* DeleteNode = mEnd->mPrev;

		// 지울 노드의 이전노드
		CListNode<T>* Prev = DeleteNode->mPrev;

		// 지울노드의 이전노드와 End노드를 연결한다.
		Prev->mNext = mEnd;
		mEnd->mPrev = Prev;

		// 지울노드의 메모리를 제거한다.
		delete DeleteNode;

		--mSize;
	}

	void pop_front()
	{
		assert(mSize > 0);

		// 지울 노드
		CListNode<T>* DeleteNode = mBegin->mNext;
		// 지울 노드의 다음노드
		CListNode<T>* Next = DeleteNode->mNext;

		// 지울노드의 다음노드와 Begin노드를 연결
		mBegin->mNext = Next;
		Next->mPrev = mBegin;

		delete DeleteNode;

		--mSize;
	}
};

