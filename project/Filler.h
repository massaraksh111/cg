#include "stdafx.h"

using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System;

public ref class Filler
{
	List<Point>^ from;
	List<Point>^ to;

	List<Point>^ centers;
	List<int>^ radius;

public:
	Filler();

	void addLine(int x1, int y1, int x2, int y2);

	void addCircle(int x, int y, int r);

	bool isOnLine(int x, int y);

	bool isDirectLine(int x, int y)
	{
		for(int i = 0; i < from->Count; i++)
		{
			if(from[i].Y - to[i].Y != 0)
				continue;

			if(from[i].Y == y)
				return true;
		}

		return false;
	}
};

