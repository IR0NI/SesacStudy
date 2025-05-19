#include "GameManager.h"
#include "Maze/MazeManager.h"

CGameManager* CGameManager::mInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	CMazeManager::DestroyInst();
}

bool CGameManager::Init()
{
	if (!CMazeManager::GetInst()->Init())
		return false;

	return true;
}

void CGameManager::Run()
{
}

CGameManager* CGameManager::GetInst()
{
	if (!mInst)
		mInst = new CGameManager;

	return mInst;
}

void CGameManager::DestroyInst()
{
	SAFE_DELETE(mInst);
}


