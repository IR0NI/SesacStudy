#pragma once
#include "../GameInfo.h"

class CMaze
{
public:
	CMaze();
	~CMaze();

private:
	int		mCountX = 0;
	int		mCountY = 0;
	std::vector<ETileType>	mTileList;
	

public:
	bool Init(const char* FileName);
	void Output(char* Buffer);

};

