#include "MazeManager.h"
#include "../Maze.h"

CMazeManager* CMazeManager::mInst = nullptr;

CMazeManager::CMazeManager()
{
}

CMazeManager::~CMazeManager()
{
}

bool CMazeManager::Init()
{
    // 미로 리스트 파일을 읽어온다.
    FILE* File = nullptr;

    fopen_s(&File, "MazeList.txt", "rt");
    if (!File)
        return false;

    char    Line[128] = {};

    fgets(Line, 128, File);

    int MazeCount = atoi(Line);

    for (int i = 0; i < MazeCount; ++i)
    {
        fgets(Line, 128, File);

        // 읽어온 파일 이름의 마지막이 개행문자일 경우 0으로
        // 채워준다.
        int Length = strlen(Line);

        if (Line[Length - 1] = '\n')
            Line[Length - 1] = 0;

        // 미로 생성
        CMaze* Maze = new CMaze;

        if (!Maze->Init(Line))
        {
            SAFE_DELETE(Maze);
            return false;
        }

        mMazeList.push_back(Maze);
    }

    fclose(File);

    return true;
}

void CMazeManager::Run()
{
}

CMazeManager* CMazeManager::GetInst()
{
    if (!mInst)
        mInst = new CMazeManager;

    return mInst;
}

void CMazeManager::DestroyInst()
{
    SAFE_DELETE(mInst);
}
