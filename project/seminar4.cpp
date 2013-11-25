#include "stdafx.h"
#include "Form1.h"

namespace project
{
	void Form1::fillFigure1()
	{
		figure1 = gcnew Figure();

		figure1->addPoint(0, 0,  50, 1);
		figure1->addPoint(0, 0, -50, 1);

		figure1->addPoint(50,  50, 0, 1);
		figure1->addPoint(-50, 50, 0, 1);

		figure1->addPoint(-50, -50, 0, 1);
		figure1->addPoint(-50, -50, 0, 1);

		figure1->addEdge(0, 2, 3);
		figure1->addEdge(0, 3, 4);
		figure1->addEdge(0, 4, 5);

		figure1->addEdge(0, 5, 2);
		figure1->addEdge(1, 2, 3);
		figure1->addEdge(1, 3, 4);

		figure1->addEdge(1, 4, 5);
	}

	void Form1::fillFigure2()
	{
		figure2 = gcnew Figure();

		figure2->addPoint(0, 0,  50, 1);
		figure2->addPoint(0, 10, -50, 1);

		figure2->addPoint(-20,  70, 0, 1);
		figure2->addPoint(-0, 50, 0, 1);

		figure2->addPoint(-50, -50, 0, 1);
		figure2->addPoint(-50, -50, 0, 1);

		figure2->addEdge(0, 2, 3);
		figure2->addEdge(0, 3, 4);
		figure2->addEdge(0, 4, 5);

		figure2->addEdge(0, 5, 2);
		figure2->addEdge(1, 2, 3);
		figure2->addEdge(1, 3, 4);

		figure2->addEdge(1, 4, 5);
	}

	void Form1::createRorationWindow()
	{
		controll = gcnew RotationControll();

		controll->FormClosing += gcnew FormClosingEventHandler(this, &Form1::RotationControll_Closing);

		controll->Rotate += gcnew RotateDelegate(this, &Form1::rotate);
		controll->RotateAround += gcnew RotateAroundDelegate(this, &Form1::rotateAround);
		controll->RotateAroundPar += gcnew RotateAroundParDelegate(this, &Form1::rotatePar);

		controll->setBars(figure->data()->trackPositions);

		controll->Show();
	}

	void Form1::drawFigure(System::Object^, System::EventArgs^) 
	{
		clearCanvas();

		figure->draw(X_PR | Y_PR, canvas(), linePen, Point(100, 100));
		figure->draw(Y_PR | Z_PR, canvas(), linePen, Point(300, 100));
		figure->draw(X_PR | Z_PR, canvas(), linePen, Point(100, 300));
	}

	void Form1::rotateAround(Vector4^ point, Vector4^ vector, Vector4^ angle)
	{
		double length = Math::Sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);
		for(int i = 0; i < 3; i++)
			vector[i] = vector[i] / length;

		Matrix4_4 ^D = gcnew Matrix4_4(), ^Rx = gcnew Matrix4_4(), 
			^Ry = gcnew Matrix4_4(), ^Rz, ^_Ry, ^_Rx, ^tmp;

		double d = Math::Sqrt(vector[1]*vector[1] + vector[2]*vector[2]);
		double cosphi = vector[2] / d, sinphi = vector[1] / d;
		double l = vector[0];

		D(0, 0) = 1;
		D(1, 1) = 1;
		D(2, 2) = 1;
		D(3, 3) = 1;
		D(3, 0) = -point[0];
		D(3, 1) = -point[1];
		D(3, 2) = -point[2];

		Rx(0, 0) = 1;
		Rx(1, 1) = cosphi;
		Rx(1, 2) = sinphi;
		Rx(2, 1) = -sinphi;
		Rx(2, 2) = cosphi;
		Rx(3, 3) = 1;

		Ry(0, 0) = l;
		Ry(1, 1) = 1;
		Ry(2, 2) = l;
		Ry(3, 3) = 1;
		Ry(0, 2) = -d;
		Ry(2, 0) = d;

		Rz = Matrix4_4::createRotateMatrix(Z_PR, angle[3]);
		_Ry = Matrix4_4::createRotateMatrix(Y_PR, -angle[2]);
		_Rx = Matrix4_4::createRotateMatrix(X_PR, -angle[3]);

		tmp = D->mult(Rx)->mult(Ry)->mult(Rz)
			   ->mult(_Ry)->mult(_Rx);

		D(3, 0) = point[0];
		D(3, 1) = point[1];
		D(3, 2) = point[2];

		figure->transform(tmp->mult(D));


		for(int i = 0; i < 4; i++)
		{
			figure->data()->point[i] = point[i];
			figure->data()->vector[i] = vector[i];
		}

		drawFigure(nullptr, nullptr);
	}

	void Form1::rotatePar(Vector4^ point, double a)
	{
		Matrix4_4 ^D = gcnew Matrix4_4(), ^R, ^tmp;

		D(0, 0) = 1;
		D(1, 1) = 1;
		D(2, 2) = 1;
		D(3, 3) = 1;
		D(3, 0) = -point[0];
		D(3, 1) = -point[1];
		D(3, 2) = -point[2];

		Proections p;
		if(point[0] == 0)
			p = X_PR;
		else if(point[1] == 0)
			p = Y_PR;
		else
			p = Z_PR;

		R = Matrix4_4::createRotateMatrix(p, a);

		tmp = D->mult(R);

		D(3, 0) = point[0];
		D(3, 1) = point[1];
		D(3, 2) = point[2];

		figure->transform(tmp->mult(D));

		drawFigure(nullptr, nullptr);
	}

	void Form1::rotate(Proections pr, int val)
	{
		clearCanvas();

		int index = 0;
		switch(pr)
		{
		case X_PR:index = 0; break;
		case Y_PR:index = 1; break;
		case Z_PR:index = 2; break;
		}

		figure->transform(Matrix4_4::createRotateMatrix(pr, (figure->data()->trackPositions[index] - val) * 10.));
		figure->data()->trackPositions[index] = val;

		drawFigure(nullptr, nullptr);
	}

	void Form1::comboClicked(System::Object^, System::EventArgs^)
	{
		if(comboBox1->SelectedIndex == 0)
		{
			if(figure2 == figure)
			{
				figure2 = figure;
				figure2->setData(figure->data());
			}

			figure = figure1;
		}
		else
		{
			if(figure1 == figure)
			{
				figure1 = figure;
				figure1->setData(figure->data());
			}

			figure = figure2;
		}

		if(controll != nullptr)
			controll->setBars(figure->data()->trackPositions);

		drawFigure(nullptr, nullptr);
	}

	void Form1::RotationControll_Closing(Object^, System::Windows::Forms::FormClosingEventArgs^)
	{
		controll = nullptr;
	}

	void Form1::rotateWindow_Click(System::Object^, System::EventArgs^)
	{
		if(controll == nullptr)createRorationWindow();
		drawFigure(nullptr, nullptr);
	}
}
