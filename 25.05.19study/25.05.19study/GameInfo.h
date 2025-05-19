#pragma once

#include <iostream>
#include <vector>

#define SAFE_DELETE(p) if(p)	{delete p; p=nullptr;}



enum class ETileType : char
{
	Road = '0',
	Wall = '1',
	Start = '2',
	Exit = '3'
};