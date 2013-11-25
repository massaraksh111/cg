#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Diagnostics;

namespace project 
{
	public ref class Vector4
	{
	public:
		double X;
		double Y;
		double Z;
		double W;

		Vector4() : X(0), Y(0), Z(0), W(0) { }

		Vector4(double x, double y, double z, double w) : X(x), Y(y), Z(z), W(w) { }
		Vector4(double x, double y, double z) : X(x), Y(y), Z(z), W(0) { }

		Vector4(Vector4^ v) : X(v->X), Y(v->Y), Z(v->Z), W(v->W) { }

		double% operator[](int i)
		{
			switch(i)
			{
			case 0: return X; break;
			case 1: return Y; break;
			case 2: return Z; break;
			default: return W; break;
			}
		}

		static double mult(Vector4^ v1, Vector4^ v2)
		{
			return v1->X*v2->X + v1->Y*v2->Y + v1->Z*v2->Z + v1->W*v2->W ;
		}

		static Vector4^ add(Vector4^ v1, Vector4^ v2)
		{
			return gcnew Vector4(v1->X + v2->X, v1->Y + v2->Y, v1->Z + v2->Z, v1->W + v2->W );
		}

		static Vector4^ sub(Vector4^ v1, Vector4^ v2)
		{
			return gcnew Vector4(v1->X - v2->X, v1->Y - v2->Y, v1->Z - v2->Z, v1->W - v2->W );
		}
	};

	enum Proections
	{
		X_PR = 1,
		Y_PR = 2,
		Z_PR = 4
	};

	public ref class TransformationData
	{
	public:
		Vector4^ trackPositions;
		Vector4^ point;
		Vector4^ vector;

		TransformationData()
		{
			trackPositions = gcnew Vector4();
			point = gcnew Vector4();
			vector = gcnew Vector4();
		}
	};

	public ref class Matrix4_4
	{
		static Vector4^ temp = gcnew Vector4(0, 0, 0, 0);

		List<Vector4^>^ data;

		static double determinator3_3(array<double>^ a1,
							   array<double>^ a2,
							   array<double>^ a3)
		{
			return a1[0]*(a2[1]*a3[2] - a2[2]*a3[1]) - 
				   a1[1]*(a2[0]*a3[2] - a2[2]*a3[0]) +
				   a1[2]*(a2[0]*a3[1] - a2[1]*a3[0]);

		}

		static double minor(Matrix4_4^ m, int i, int j)
		{
			int countI = 0, countJ = 0;

			array<array<double>^>^ a = {
									gcnew array<double>(3),
									gcnew array<double>(3),
									gcnew array<double>(3)
									};

			for(int x = 0; x != 4; x++)
			{
				if(x == i)
					continue;

				countJ = 0;
				for(int y = 0; y != 4; y++)
				{
					if(y == j)
						continue;

					a[countI][countJ++] = m->data[x][y];
				}
				countI++;
			}

			return determinator3_3(a[0], a[1], a[2]);
		}

	public:

		Matrix4_4^ invertible()
		{
			double determinator = 0.0;
			for(int i = 0; i < 4; i++)
				determinator += (i%2 == 0 ? 1 : -1)*data[i][0]*minor(this, i, 0);

			if(Math::Abs(determinator) < 0.001)
				return nullptr;

			Matrix4_4^ minors = gcnew Matrix4_4();

			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 4; j++)
				{
					minors(i, j) = ((i+j)%2 == 0 ? 1 : -1)*minor(this, i, j) / determinator;
				}
			}

			return minors;
		}

		Matrix4_4()
		{
			data = gcnew List<Vector4^>();
			data->Add(gcnew Vector4(0, 0, 0, 0));
			data->Add(gcnew Vector4(0, 0, 0, 0));
			data->Add(gcnew Vector4(0, 0, 0, 0));
			data->Add(gcnew Vector4(0, 0, 0, 0));
		}

		double% operator()(int x, int y)
		{
			return data[y][x];
		}

		void set(int x, int y, double value)
		{
			data[y][x] = value;
		}

		Vector4^ mult(Vector4^ vec)
		{
			temp[0] = Vector4::mult(vec, data[0]);
			temp[1] = Vector4::mult(vec, data[1]);
			temp[2] = Vector4::mult(vec, data[2]);
			temp[3] = Vector4::mult(vec, data[3]);

			return gcnew Vector4(temp);
		}

		Matrix4_4^ mult(Matrix4_4^ matrix)
		{
			Matrix4_4^ res = gcnew Matrix4_4();

			for(int i = 0; i < 4; i++)
			{
				for(int h = 0; h < 4; h++)
					temp[h] = this(i, h);

				for(int h = 0; h < 4; h++)
				{
					res(i, h) = Vector4::mult(temp, matrix->data[h]);
				}
			}

			return res;
		}

		void debug()
		{
			Debug::WriteLine("-------------");
			for(int i = 0; i < 4; i++)
			{
				for(int h = 0; h < 4; h++)
				{
					Debug::Write(this(i, h) + " ");
				}
				Debug::WriteLine("");
			}
		}

		static Matrix4_4^ createRotateMatrix(Proections p, double rotate)
		{
			double radian = rotate / 180.0 * Math::PI;
			Matrix4_4^ ret = gcnew Matrix4_4();

			ret(3, 3) = 1;

			if(p == X_PR)
			{
				ret(0, 0) = 1;
				ret(1, 1) = Math::Cos(radian);
				ret(2, 2) = Math::Cos(radian);

				ret(1, 2) = Math::Sin(radian);
				ret(2, 1) = -Math::Sin(radian);
			}
			else if(p == Y_PR)
			{
				ret(1, 1) = 1;

				ret(0, 0) = Math::Cos(radian);
				ret(2, 2) = Math::Cos(radian);

				ret(0, 2) = -Math::Sin(radian);
				ret(2, 0) = Math::Sin(radian);
			}
			else
			{
				ret(2, 2) = 1;

				ret(0, 0) = Math::Cos(radian);
				ret(1, 1) = Math::Cos(radian);

				ret(0, 1) = Math::Sin(radian);
				ret(1, 0) = -Math::Sin(radian);
			}

			return ret;
		}
	};

	public ref class Figure
	{
		List<Vector4^>^ points;
		List<Vector4^>^ edges;

		TransformationData^ trData;

		Point to2DPoint(int mask, Vector4^ point, Point offcet)
		{
			Point p;
			int count = 0;
			array<int>^ ar = gcnew array<int>(2);

			if(mask & X_PR)
			{
				ar[count++] = point[0];
			}
			if(mask & Y_PR)
			{
				ar[count++] = point[1];
			}
			if(mask & Z_PR)
			{
				ar[count++] = point[2];
			}

			p.X = ar[0] + offcet.X;
			p.Y = ar[1] + offcet.Y;

			return p;
		}

	public:
		Figure()
		{
			points = gcnew List<Vector4^>();
			edges = gcnew List<Vector4^>();
			trData = gcnew TransformationData();
		}

		TransformationData^ data() { return trData; }
		void setData(TransformationData^ dd) { trData = dd; }

		void addEdge(int a, int b, int c)
		{
			edges->Add(gcnew Vector4(a, b, c, 0));
		}

		int addPoint(int x, int y, int z, int w)
		{
			points->Add(gcnew Vector4(x, y, z, w));
			return points->Count-1;
		}

		void draw(int mask, Graphics^ g, Pen^ pen, Point offcet)
		{
			for(int i = 0; i < edges->Count; i++)
			{
				array<Point>^ p = { to2DPoint(mask, points[edges[i][0]], offcet),
									to2DPoint(mask, points[edges[i][1]], offcet),
									to2DPoint(mask, points[edges[i][2]], offcet)
								};

				g->DrawPolygon(pen, p);
			}
		}

		void transform(Matrix4_4^ matrix)
		{
			for(int i = 0; i < points->Count; i++)
			{
				points[i] = matrix->mult(points[i]);
			}
		}
	};
}


