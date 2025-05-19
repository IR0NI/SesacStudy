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
    // �̷� ����Ʈ ������ �о�´�.
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

        // �о�� ���� �̸��� �������� ���๮���� ��� 0����
        // ä���ش�.
        int Length = strlen(Line);

        if (Line[Length - 1] = '\n')
            Line[Length - 1] = 0;

        // �̷� ����
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
