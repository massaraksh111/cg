#include "StdAfx.h"
#include "Filler.h"

Filler::Filler()
{
	from = gcnew List<Point>();
	to = gcnew List<Point>();

	centers = gcnew List<Point>();
	radius = gcnew List<int>();
}

void Filler::addLine(int x1, int y1, int x2, int y2)
{
	from->Add(Point(x1, y1));
	to->Add(Point(x2, y2));
}

void Filler::addCircle(int x, int y, int r)
{
	centers->Add(Point(x, y));
	radius->Add(r);
}

bool Filler::isOnLine(int x, int y)
{
	for(int i = 0; i < from->Count; i++)
	{
		double k = (double)(from[i].Y - to[i].Y) /
			(from[i].X - to[i].X);

		int y_ex = k*x + from[i].Y;

		if(y_ex == y)
			return true;
	}

	for(int i = 0; i < from->Count; i++)
	{
		double y_2 = (y - to[i].Y)*(y - to[i].Y);
		double x_2 = (x - to[i].X)*(x - to[i].X);

		if(y_2 + x_2 == radius[i]*radius[i])
			return true;
	}

	return false;
}
