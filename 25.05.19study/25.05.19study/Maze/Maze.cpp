#include "Maze.h"

CMaze::CMaze()
{
}

CMaze::~CMaze()
{
}

bool CMaze::Init(const char* FileName)
{
	FILE* File = nullptr;

	fopen_s(&File, FileName, "rt");

	if (!File)
		return false;

	char Line[256] = {};

	fgets(Line, 256, File);

	char* Context = nullptr;

	char* Result = strtok_s(Line, ",", &Context);

	mCountX = atoi(Result);
	mCountY = atoi(Context);

	mTileList.reserve(mCountX * mCountY);

	for (int i = 0; i < mCountY; ++i)
	{
		fgets(Line, 256, File);

		for (int j = 0; j < mCountX; ++j)
		{
			mTileList.push_back((ETileType)Line[j]);
		}
	}

	fclose(File);
	return true;
}

void CMaze::Output(char* Buffer)
{
}


