#pragma once

#include "../GameInfo.h"
class CMaze;
class CMazeManager
{
private:
	CMazeManager();
	~CMazeManager();

private:
	std::vector<CMaze*>mMazeList;
public:
	bool Init();
	void Run();
private:
	static CMazeManager* mInst;
public:
	static CMazeManager* GetInst();
	static void DestroyInst();
};

